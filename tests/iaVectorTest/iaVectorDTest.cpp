#include "../../iaAi/iaMl/iaVector/iaVector.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string inputPath = "./iaVectorTest.txt";
    std::string outputPath = "./iaVectorTest.txt";

    // Проверка существования входного файла
    if (!fs::exists(inputPath)) {
        std::cerr << "Ошибка: файл " << inputPath << " не найден!" << std::endl;
        return 1;
    }

    // Создание выходной директории, если ее нет
    fs::create_directories("tests/TestResults");

    std::ifstream inputFile(inputPath);
    std::ofstream outputFile(outputPath);

    if (!inputFile || !outputFile) {
        std::cerr << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    iaVector<double> vec;
    double value;

    // Читаем числа из файла и добавляем в вектор
    while (inputFile >> value) {
        vec.push_back(value);
    }

    // Записываем исходный вектор
    outputFile << "Исходный вектор: " << vec << "\n";

    // Вычисляем разные характеристики
    outputFile << "Сумма элементов: " << vec.sum() << "\n";
    outputFile << "Среднее значение: " << vec.average() << "\n";
    outputFile << "Максимальный элемент: " << vec.maxElement() << "\n";
    outputFile << "Минимальный элемент: " << vec.minElement() << "\n";
    outputFile << "L1-норма: " << vec.L1norm() << "\n";
    outputFile << "L2-норма: " << vec.L2norm() << "\n";

    // Сортируем вектор и записываем результат
    vec.selectionSort();
    outputFile << "Отсортированный вектор: " << vec << "\n";

    std::cout << "Тест завершен. Результаты записаны в " << outputPath << std::endl;

    return 0;
}
