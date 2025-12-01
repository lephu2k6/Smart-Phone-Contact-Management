#ifndef APP_H
#define APP_H

#include "./structures/BST.h"
#include "./structures/HashTable.h"
using namespace std;

class App{
private:
    BST bst;
    HashTable hash;

public:
    // chuong trình 
    void reset();
    bool loadContactsFromFile(const std::string &filename);
    void addContact(const Contact &c);
    void addContact();
    void deleteContact();
    void searchByName();
    void searchByPhone();
    void showAll();
    void updateContactName();



    // đo hiệu năng
    // đo thời gian load file
    void benchmarkLoadFromFile(const string &filename);

    // đo tìm kiếm tên trong BST
    void benchmarkSearchByName(const string &name);

    // đo tìm kiếm số điện thoại trong Hash Table
    void benchmarkSearchByPhone(const string &phone);

    // đo xóa tên trong BST
    void benchmarkDeleteByName(const string &name);


};

#endif
