#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../models/Contact.h" 
using namespace std;

class HashTable {
private:
    struct Node {
        Contact data;
        Node* next;
    };
    static const int SIZE = 1000;
    Node* table[SIZE];

    int hashFunc(const string &phone);

public:
    HashTable();
    ~HashTable();

    void insert(const Contact &c);
    Contact* search(const string &phone);
    void remove(const string &phone);
};

#endif
