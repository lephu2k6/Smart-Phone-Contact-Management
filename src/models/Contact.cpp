#include "Contact.h"

Contact::Contact() { name = ""; phone = ""; email = ""; address = "";}
Contact::Contact(string name, string phone, string email, string address) {
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

string Contact::getName() const { return name; }
string Contact::getPhone() const { return phone; }
string Contact::getEmail() const { return email; }
string Contact::getAddress() const { return address; }

void Contact::setName(const string &n) { name = n; }
void Contact::setPhone(const string &p) { phone = p; }
void Contact::setEmail(const string &e) { email = e; }
void Contact::setAddress(const string &a) { address = a; }

void Contact::print() const {
    cout << "Name: " << name
         << ", Phone: " << phone
         << ", Email: " << email 
         << ", Address: " << address << endl;
}
