#include "Utils.h"

void displayMenu(const std::vector<std::string>& options) {
    std::cout << "\nМеню:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i << " - " << options[i] << '\n';
    }
    std::cout << "Выберите команду: ";
}

bool isNumber(const std::string& s)
{
    return  s.length() < 2 and !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

long numberOrDefault(const std::string& command){
    if (isNumber(command)) {
        return strtol(command.c_str(), NULL, 10);
    }
    return -1;
    
}




