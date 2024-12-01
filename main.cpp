#include <iostream>
#include "Utils.h"
#include "test.h"

int main() {
    std::string command;
    long value;
    while (true) {
        displayMenu(getMenuOptions);
        getline(std::cin, command);
        
        value = numberOrDefault(command);
        
        switch (value) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
    

