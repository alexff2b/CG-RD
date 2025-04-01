#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "../../iaAi/DataClasses/iaArray.hpp"

void logResult(std::ostream& out, const std::string& message) {
    out << message << std::endl;
}

void testIaArray(const std::string& inputPath, const std::string& outputPath) {
    logResult(std::cout, "Текущая рабочая директория: " + std::filesystem::current_path().string());
    logResult(std::cout, "Открываю входной файл: " + std::filesystem::absolute(inputPath).string());

    std::ifstream inFile(inputPath);
    if (!inFile) {
        std::cerr << "Ошибка: не удалось открыть входной файл\n";
        return;
    }

    std::filesystem::path outPath(outputPath);
    std::filesystem::create_directories(outPath.parent_path());

    std::ofstream outFile(outputPath);
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть выходной файл\n";
        return;
    }

    logResult(outFile, "▶ Тестирование класса iaArray<int>:\n");

    int size;
    inFile >> size;
    if (size <= 0) {
        std::cerr << "Ошибка: некорректный размер массива\n";
        return;
    }

    iaArray<int> arr(size);
    for (int i = 0; i < size; i++) {
        int value;
        inFile >> value;
        arr[i] = value;
    }

    logResult(outFile, "Размер: " + std::to_string(arr.size()));
    logResult(outFile, "Пуст ли массив: " + std::string(arr.empty() ? "Да" : "Нет"));

    logResult(outFile, "\nИсходный массив:");
    outFile << arr << std::endl;

    logResult(outFile, "\n▶ Тестирование добавления элементов:");
    arr.push_back(42);
    outFile << arr << std::endl;

    logResult(outFile, "\n▶ Тестирование удаления последнего элемента:");
    arr.pop_back();
    outFile << arr << std::endl;

    logResult(outFile, "\n▶ Тестирование вставки элемента:");
    arr.insert(1, 99);
    outFile << arr << std::endl;

    logResult(outFile, "\n▶ Тестирование удаления элемента (ручное сдвижение):");
    for (size_t i = 1; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr.pop_back();
    outFile << arr << std::endl;

    logResult(outFile, "\n▶ Тестирование доступа по индексу:");
    logResult(outFile, "Элемент [0]: " + std::to_string(arr.at(0)));

    logResult(outFile, "\n▶ Тестирование резервирования памяти:");
    arr.reserve(50);
    logResult(outFile, "Новая capacity: " + std::to_string(arr.getCapacity()));

    logResult(outFile, "\nТестирование завершено.");
    logResult(std::cout, "Результаты записаны в: " + std::filesystem::absolute(outputPath).string());
}

int main() {
    std::string inputFile = "tests/TestsDatas/iaArray_Int.txt";
    std::string outputFile = "tests/TestsResults/iaArray_Int.txt";

    testIaArray(inputFile, outputFile);
    return 0;
}
