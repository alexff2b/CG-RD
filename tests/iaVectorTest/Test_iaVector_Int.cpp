#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "../../iaMath/iaLinearAlgebra/iaVector/iaVector.hpp" // Убедись, что путь корректный


/// Функция для вывода в консоль и в файл
void logResult(std::ostream& out, const std::string& message) {
    out << message << std::endl;  // Запись в поток (консоль или файл)
}

/**
 * @brief Функция тестирования класса iaVector<int>.
 * @param inputPath Путь к входному файлу с данными.
 * @param outputPath Путь к выходному файлу с результатами.
 */
void testIntVector(const std::string& inputPath, const std::string& outputPath) {
    // Вывод текущей директории для отладки
    logResult(std::cout, "Текущая рабочая директория: " + std::filesystem::current_path().string());
    logResult(std::cout, "Открываю входной файл: " + std::filesystem::absolute(inputPath).string());

    std::ifstream inFile(inputPath);
    if (!inFile) {
        std::cerr << "Ошибка: не удалось открыть входной файл\n";
        return;
    }

    // Проверяем, существует ли директория для выходного файла
    std::filesystem::path outPath(outputPath);
    std::filesystem::create_directories(outPath.parent_path());

    std::ofstream outFile(outputPath);
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть выходной файл\n";
        return;
    }

    logResult(outFile, "▶ Тестирование класса iaVector<int>:\n");

    // Чтение данных
    int size;
    inFile >> size;
    if (size <= 0) {
        std::cerr << "Ошибка: некорректный размер вектора\n";
        return;
    }

    // Чтение элементов вектора
    std::vector<int> data(size);
    for (int i = 0; i < size; i++) {
        inFile >> data[i];
    }

    iaVector<int> vec(size, data.data());

    logResult(outFile, "▶ Тестирование класса iaVector<int>:\n");
    logResult(outFile, "Размер: " + std::to_string(vec.size()));
    logResult(outFile, "Сумма элементов: " + std::to_string(vec.sum()));
    logResult(outFile, "L1-норма: " + std::to_string(vec.L1norm()));
    logResult(outFile, "L2-норма: " + std::to_string(vec.L2norm()));

    logResult(outFile, "\nИсходный вектор:");
    vec.print(outFile);

    // Тестирование арифметических операций
    logResult(outFile, "\n▶ Тестирование арифметических операций:");
    iaVector<int> vec2(size, data.data());

    logResult(outFile, "Сложение:");
    (vec + vec2).print(outFile);

    logResult(outFile, "Разность:");
    (vec - vec2).print(outFile);

    logResult(outFile, "Умножение на 2:");
    (vec * 2).print(outFile);

    // Тестирование скалярного произведения
    logResult(outFile, "\n▶ Тестирование скалярного произведения:");
    logResult(outFile, "vec | vec2 = " + std::to_string(vec | vec2));

    // Тестирование максимального и минимального элементов
    logResult(outFile, "\n▶ Тестирование экстремальных значений:");
    logResult(outFile, "Максимальный элемент: " + std::to_string(vec.maxElement()));
    logResult(outFile, "Минимальный элемент: " + std::to_string(vec.minElement()));

    // Тестирование палиндрома
    logResult(outFile, "\n▶ Тестирование палиндрома:");
    logResult(outFile, "Является ли вектор палиндромом: " + std::string(vec.iaPalindrome() ? "Да" : "Нет"));

    // Добавление нового элемента и повторный вывод
    logResult(outFile, "\n▶ Добавление элемента:");
    vec.push_back(100);
    vec.print(outFile);
    logResult(outFile, "Размер после добавления: " + std::to_string(vec.size()));

    // Удаление последнего элемента
    logResult(outFile, "\n▶ Удаление последнего элемента:");
    vec.pop_back();
    vec.print(outFile);
    logResult(outFile, "Размер после удаления: " + std::to_string(vec.size()));

    logResult(outFile, "\nТестирование завершено.");
    logResult(std::cout, "Результаты записаны в: " + std::filesystem::absolute(outputPath).string());
}

int main() {
    // Пути к файлам
    std::string inputFile = "tests/TestsDatas/iaVector_Int.txt";
    std::string outputFile = "tests/TestsResults/iaVector_Int.txt";

    // Запуск теста
    testIntVector(inputFile, outputFile);

    return 0;
}
