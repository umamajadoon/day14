#include <iostream>
#include <string>

bool stringToBool(const std::string& str, bool defaultValue = false) {
    if (str == "true") {
        return true;
    } else if (str == "false") {
        return false;
    } else {
        return defaultValue;
    }
}

int main() {
    std::string str1 = "true";
    std::string str2 = "false";
    std::string str3 = "invalid";

    std::cout << "String \"true\" to bool: " << stringToBool(str1) << std::endl;
    std::cout << "String \"false\" to bool: " << stringToBool(str2) << std::endl;
    std::cout << "String \"invalid\" to bool with default true: " << stringToBool(str3, true) << std::endl;

    return 0;
}