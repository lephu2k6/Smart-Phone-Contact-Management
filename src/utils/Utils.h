#ifndef UTILS_H
#define UTILS_H
#include <string>

class Utils {
public:
    static void showMenu(); 
    static bool isValidEmail(const std::string &email);
    static bool isValidPhone(const std::string &phone);
    
    
};

#endif
