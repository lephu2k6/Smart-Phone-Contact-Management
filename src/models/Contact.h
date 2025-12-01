#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phone;
    string email;
    string address;

public:
    Contact();
    Contact(string name, string phone, string email, string address);

    string getName() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;

    void setName(const string &n);
    void setPhone(const string &p);
    void setEmail(const string &e);
    void setAddress(const string &a);

    void print() const;
};

#endif
