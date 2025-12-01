#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable() {
    for(int i=0;i<SIZE;i++) table[i]=nullptr;
}
HashTable::~HashTable() {
    for(int i=0;i<SIZE;i++){
        Node* cur=table[i];
        while(cur){
            Node* tmp=cur;
            cur=cur->next;
            delete tmp;
        }
    }
}

int HashTable::hashFunc(const string &phone){
    long long sum=0;
    for(char c:phone) sum=(sum*31+c)%SIZE;
    return sum;
}

void HashTable::insert(const Contact &c){
    int idx=hashFunc(c.getPhone());
    Node* n=new Node{c, table[idx]};
    table[idx]=n;
}

Contact* HashTable::search(const string &phone){
    int idx=hashFunc(phone);
    Node* cur=table[idx];
    while(cur){
        if(cur->data.getPhone()==phone) return &cur->data;
        cur=cur->next;
    }
    return nullptr;
}

void HashTable::remove(const string &phone){
    int idx=hashFunc(phone);
    Node* cur=table[idx];
    Node* prev=nullptr;
    while(cur){
        if(cur->data.getPhone()==phone){
            if(prev) prev->next=cur->next;
            else table[idx]=cur->next;
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->next;
    }
}
