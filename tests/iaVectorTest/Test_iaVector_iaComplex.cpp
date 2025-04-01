#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "iaComplex.hpp"
#include "iaVector.hpp"

void testComplexVector(std::ifstream& inFile, std::ofstream& outFile);

int main() {
    // Пути к файлам
    std::string inputFilePath = "tests/TestsDatas/iaVectorComplex.txt";
    std::string outputFilePath = "tests/TestsResults/iaVectorComplex.txt";

    // Информация для отладки
    std::cout << "Текущая рабочая директория: " << std::filesystem::current_path() << std::endl;
    std::cout << "Открываем файл: " << std::filesystem::absolute(inputFilePath) << std::endl;

    // Открываем файлы
    std::ifstream inFile(inputFilePath);
    std::ofstream outFile(outputFilePath);

    // Проверка файлов
    if (!inFile) {
        std::cerr << "Ошибка: не удалось открыть " << inputFilePath
                  << " (errno: " << errno << " - " << std::strerror(errno) << ")" << std::endl;
        return 1;
    }
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть " << outputFilePath
                  << " (errno: " << errno << " - " << std::strerror(errno) << ")" << std::endl;
        return 1;
    }

    // Запускаем тест
    testComplexVector(inFile, outFile);

    std::cout << "Тестирование завершено. Результаты в " << outputFilePath << std::endl;
    return 0;
}

/**
 * @brief Тестирование работы с вектором комплексных чисел
 *
 * @param inFile  Входной файл с тестовыми данными
 * @param outFile Файл для записи результатов тестирования
 */
void testComplexVector(std::ifstream& inFile, std::ofstream& outFile) {
    size_t vectorSize;
    inFile >> vectorSize;

    if (vectorSize == 0) {
        outFile << "Ошибка: пустой вектор комплексных чисел. Нечего тестировать.\n";
        return;
    }

    outFile << "▶ Тестирование iaVector<iaComplex>:\n";

    iaVector<iaComplex> vector;

    double real, imag;
    for (size_t i = 0; i < vectorSize; ++i) {
        inFile >> real >> imag;
        vector.push_back(iaComplex(real, imag));
    }

    // Выводим исходный вектор
    outFile << "Исходный вектор комплексных чисел:\n";
    for (size_t i = 0; i < vector.size(); ++i) {
        outFile << vector[i] << "\n";
    }

    outFile << "\n▶ Добавление нового элемента (1.0 + i):\n";
    iaComplex newComplex(1.0, 1.0);
    vector.push_back(newComplex);

    for (size_t i = 0; i < vector.size(); ++i) {
        outFile << vector[i] << "\n";
    }
}
