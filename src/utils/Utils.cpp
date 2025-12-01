#include "../utils/Utils.h"
#include <iostream>
#include <regex>
#include <string>
#include <cctype>
using namespace std;

void Utils::showMenu() {
    cout << "\n==== PHONEBOOK MENU ====\n";
    cout << "1. Add contact\n";
    cout << "2. Delete contact\n";
    cout << "3. Search by name\n";
    cout << "4. Search by phone\n";
    cout << "5. Show all\n";
    cout << "6. Update name\n";
    cout << "7. Add Data Test\n" ;
    cout << "0. Exit\n";
    cout << "Choice: ";
}
// Kiểm tra định dạng email 
bool Utils::isValidEmail(const std::string &email) {
    const regex pattern(R"((\w+)(\.\w+)*@(\w+)\.(\w+))");
    return regex_match(email, pattern);
}
// kiem tra định dạng sdt hợp lệ 
bool Utils::isValidPhone(const std::string &phone) {
    if(phone.size() != 10) return false; 
    for(char c : phone){
        if(!isdigit(c)) return false; 
    }
    return true;
}
