#include "Utils.h"

std::vector<std::string> getMenuOptions = {
        "Выход", "Алгоритм Кнута-Морриса-Пратта\n", "Поиск с помощью префиксного дерева\n",
        "Z-алгоритм\n", "Алгоритм Bitap", "Все алгоритмы"
    };


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

template <typename Func, typename... Args>
auto measureExecutionTime(Func&& func, Args&&... args) {
    using namespace std::chrono;

    auto start = high_resolution_clock::now(); // Начало измерения времени
    auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
    auto end = high_resolution_clock::now();   // Конец измерения времени

    auto duration = duration_cast<microseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " microseconds\n";

    return result; // Возвращаем результат вызова функции
}
