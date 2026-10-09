#include <iostream>
#include <vector>
#include <stdexcept>


int fromSupplementaryCode(const std::vector<int>& supplementary_code) {
    if (supplementary_code.empty()) {
        throw std::invalid_argument("Ошибка: массив битов пуст!");
    }
    int bits = supplementary_code.size();
    int number = 0;

    if (supplementary_code[0] == 1) {
        number -= (1 << (bits - 1));
    }

    for (int i = 1; i < bits; ++i) {
        if (supplementary_code[i] == 1) {
            number += (1 << (bits - 1 - i));
        }
    }
    return number;
}

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<int> test_negative = {1, 1, 1, 1, 1, 0, 1, 1};
    std::vector<int> test_positive = {0, 0, 0, 0, 1, 1, 0, 0};
    std::vector<int> test_min = {1, 0, 0, 0, 0, 0, 0, 0};
    try {
        std::cout << "--- Тестирование функции (Вариант 4) ---" << std::endl;
        std::cout << "Код 11111011 -> Десятичное: " << fromSupplementaryCode(test_negative) << " (Ожидается: -5)" << std::endl;
        std::cout << "Код 00001100 -> Десятичное: " << fromSupplementaryCode(test_positive) << " (Ожидается: 12)" << std::endl;
        std::cout << "Код 10000000 -> Десятичное: " << fromSupplementaryCode(test_min) << " (Ожидается: -128)" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
