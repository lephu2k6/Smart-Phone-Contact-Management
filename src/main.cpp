#include "App.h"

#include "utils/Utils.h"
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    App app;
    int choice;

    while(true) {
        Utils::showMenu(); 
        cin >> choice; cin.ignore();

        switch(choice){
            case 1: app.addContact(); break;
            case 2: app.deleteContact(); break;
            case 3: app.searchByName(); break;
            case 4: app.searchByPhone(); break;
            case 5: app.showAll(); break;
            case 6: app.updateContactName(); break;
            case 7: app.loadContactsFromFile("test/contacts.txt"); 
            app.showAll();break;
            case 0: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
