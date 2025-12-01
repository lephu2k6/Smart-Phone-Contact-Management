#include "App.h"
#include "utils/Utils.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

// ===== Thêm contact =====
void App::addContact() {
    string name, phone, email, address;

    cout << "Nhập họ tên: ";
    getline(cin, name);
    if(name.empty()){ 
        cout << "Tên không được rỗng.\n"; 
        return; 
    }
    if(bst.search(name)){ 
        cout << "Đã có liên hệ với tên này.\n"; 
        return; 
    }

    
    while(true){
        cout << "Nhập số điện thoại (10 chữ số): ";
        getline(cin, phone);
        if(phone.empty()){
            cout << "Số điện thoại không được rỗng.\n";
            continue;
        }
        if(!Utils::isValidPhone(phone)){
            cout << "Số điện thoại không hợp lệ. Phải gồm 10 chữ số.\n";
            continue;
        }
        if(hash.search(phone)){
            cout << "Đã có liên hệ với số điện thoại này.\n";
            continue;
        }
        break; 
    }

    
    while(true){
        cout << "Nhập email: ";
        getline(cin, email);
        if(email.empty()){
            cout << "Email không được để trống.\n";
            continue;
        }
        if(!Utils::isValidEmail(email)){
            cout << "Email không hợp lệ.\n";
            continue;
        }
        break; 
    }

    
    cout << "Nhập địa chỉ: ";
    getline(cin, address);

    Contact c(name, phone, email, address);
    bst.insert(c);
    hash.insert(c);

    cout << "Đã thêm liên hệ thành công!\n";
}
// ===== Xoá contact =====
void App::deleteContact() {
    string phone, name;

    cout << "Nhập số điện thoại để xóa (để trống để dùng tên): ";
    getline(cin, phone);

    if(!phone.empty()){
        Contact* c = hash.search(phone);
        if(c){
            name = c->getName();
            hash.remove(phone);
            bst.remove(name);
            cout << "Đã xoá liên hệ này.\n";
            return;
        } else {
            cout << "Không tìm thấy liên lạc với số điện thoại này.\n";
        }
    }

    cout << "Nhập tên để xóa: ";
    getline(cin, name);
    if(name.empty()){ cout << "Tên chưa được cung cấp.\n"; return; }

    Contact* c2 = bst.search(name);
    if(c2){
        string ph = c2->getPhone();
        bst.remove(name);
        hash.remove(ph);
        cout << "Đã xoá liên hệ này.\n";
    } else {
        cout << "Không tìm thấy liên hệ.\n";
    }
}

// ===== Tìm kiếm =====
void App::searchByName() {
    string name;
    cout << "Nhập tên để tìm kiếm: ";
    getline(cin, name);
    if(name.empty()){ cout << "Tên không được rỗng.\n"; return; }

    Contact* c = bst.search(name);
    if(c) c->print();
    else cout << "Không tìm thấy liên hệ.\n";
}

void App::searchByPhone() {
    string phone;
    cout << "Nhập số điện thoại để tìm kiếm: ";
    getline(cin, phone);
    if(phone.empty()){ cout << "Số điện thoại không được rỗng.\n"; return; }

    Contact* c = hash.search(phone);
    if(c) c->print();
    else cout << "Không tìm thấy liên hệ với số điện thoại này.\n";
}

// ===== In danh bạ =====
void App::showAll() {
    bst.printInorder();
}

// ===== Cập nhật tên contact =====
void App::updateContactName() {
    string phone, oldName, newName;

    cout << "Nhập số điện thoại để cập nhật tên (để trống để dùng tên): ";
    getline(cin, phone);

    Contact* contact = nullptr;

    if(!phone.empty()){
        if(!Utils::isValidPhone(phone)){
            cout << "Số điện thoại không hợp lệ (phải 10 chữ số).\n";
            return;
        }

        contact = hash.search(phone);
        if(!contact){ 
            cout << "Không tìm thấy liên hệ với số điện thoại này.\n"; 
            return; 
        }
        oldName = contact->getName();
    } else {
        cout << "Nhập tên hiện tại để cập nhật: ";
        getline(cin, oldName);
        if(oldName.empty()){ 
            cout << "Tên chưa được cung cấp.\n"; 
            return; 
        }

        contact = bst.search(oldName);
        if(!contact){ 
            cout << "Không tìm thấy liên hệ.\n"; 
            return; 
        }
    }

    cout << "Nhập tên mới: ";
    getline(cin, newName);
    if(newName.empty()){ 
        cout << "Tên mới không được rỗng.\n"; 
        return; 
    }
    if(newName == oldName){ 
        cout << "Tên mới giống tên hiện tại.\n"; 
        return; 
    }
    if(bst.search(newName)){ 
        cout << "Đã có liên hệ với tên mới này.\n"; 
        return; 
    }

    // Cập nhật tên trong BST
    bst.updateName(oldName, newName);

    // Cập nhật tên trong hash table
    string ph = contact->getPhone();
    Contact* hc = hash.search(ph);
    if(hc) hc->setName(newName);

    cout << "Đã cập nhật tên liên hệ.\n";
}
// Dữ liệu test
// thêm contact từ code/file
void App::addContact(const Contact &c) {
    if(hash.search(c.getPhone())){
        cout << "Đã có liên hệ với số điện thoại: " << c.getPhone() << "\n";
        return;
    }
    bst.insert(c);
    hash.insert(c);
}

// để add contact dữ liệu test
bool App::loadContactsFromFile(const string &filename) {
    ifstream file(filename);
    if(!file.is_open()) {
        cout << "Không thể mở file: " << filename << "\n";
        return false;
    }

    string line;
    int addedCount = 0; // chỉ tăng khi contact được thêm
    while(getline(file, line)) {
        if(line.empty()) continue;
        stringstream ss(line);
        string name, phone, email, address;

        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        getline(ss, address, ',');

        if(name.empty() || phone.empty()) continue; 

        Contact c(name, phone, email, address);

        // Kiểm tra trùng trước khi thêm
        if(!hash.search(c.getPhone())) {
            addContact(c); 
            ++addedCount;
        } else {
            if(hash.search(c.getPhone()))
                cout << "Đã có liên hệ với số điện thoại: " << c.getPhone() << "\n";
        }
    }

    cout << addedCount << " contact đã được thêm từ file.\n";
    return true;
}
// =====================================================================//
// =========================ĐO Hiệu năng===============================// 
// ===== Load từ file =====
void App::benchmarkLoadFromFile(const string &filename) {
    auto start = high_resolution_clock::now();
    loadContactsFromFile(filename);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Load file " << filename << " trong " << duration << " ms\n";
}

// ===== Tìm kiếm BST =====
void App::benchmarkSearchByName(const string& name) {
    auto start = high_resolution_clock::now();
    bst.search(name);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Tìm kiếm tên \"" << name << "\" BST: " << duration << " µs\n";
}

// ===== Tìm kiếm Hash Table =====
void App::benchmarkSearchByPhone(const string& phone) {
    auto start = high_resolution_clock::now();
    hash.search(phone);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Tìm kiếm số điện thoại \"" << phone << "\" Hash Table: " << duration << " µs\n";
}

// ===== Xóa BST =====
void App::benchmarkDeleteByName(const string& name) {
    auto start = high_resolution_clock::now();
    bst.remove(name);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start).count();
    cout << "Xóa tên \"" << name << "\" BST: " << duration << " µs\n";
}

