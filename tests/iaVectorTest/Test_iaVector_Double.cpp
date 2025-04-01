#include <iostream>
#include <fstream>
#include <iomanip>  // Для управления точностью вывода
#include <filesystem>
#include "../../iaMath/iaLinearAlgebra/iaVector/iaVector.hpp"  // Подключаем iaVector

// Функция для вывода в консоль и в файл
void logResult(std::ofstream& out, const std::string& message) {
    std::cout << message << std::endl;  // Вывод в консоль
    out << message << std::endl;        // Запись в файл
}

void testDoubleVectors(std::ifstream& inFile, std::ofstream& outFile);

int main() {
    // Пути к файлам
    std::string inputFilePath = "tests/TestsDatas/iaVector_Double.txt";
    std::string outputFilePath = "tests/TestsResults/iaVector_Double.txt";

    // Отладочная информация
    logResult(std::cout, "Текущая рабочая директория: " + std::filesystem::current_path().string());
    logResult(std::cout, "Открываем файл: " + std::filesystem::absolute(inputFilePath).string());

    // Открытие файлов
    std::ifstream inFile(inputFilePath);
    std::ofstream outFile(outputFilePath);

    // Проверка файлов
    if (!inFile) {
        std::cerr << "Ошибка: не удалось открыть " << inputFilePath << std::endl;
        return 1;
    }
    if (!outFile) {
        std::cerr << "Ошибка: не удалось открыть " << outputFilePath << std::endl;
        return 1;
    }

    // Запуск тестов
    testDoubleVectors(inFile, outFile);

    logResult(std::cout, "Тестирование завершено. Результаты в " + outputFilePath);
    return 0;
}

void testDoubleVectors(std::ifstream& inFile, std::ofstream& outFile) {
    // Настройка вывода чисел с фиксированной точностью
    outFile << std::fixed << std::setprecision(6);

    int size1, size2;
    inFile >> size1;
    std::vector<double> data1(size1);
    for (int i = 0; i < size1; i++) {
        inFile >> data1[i];
    }

    inFile >> size2;
    std::vector<double> data2(size2);
    for (int i = 0; i < size2; i++) {
        inFile >> data2[i];
    }

    // Создание векторов
    iaVector<double> vec1(size1, data1.data());
    iaVector<double> vec2(size2, data2.data());

    logResult(outFile, "▶ Тестирование iaVector<double>:");

    logResult(outFile, "Размер: " + std::to_string(vec1.size()));
    logResult(outFile, "Сумма элементов: " + std::to_string(vec1.sum()));
    logResult(outFile, "L1-норма: " + std::to_string(vec1.L1norm()));
    logResult(outFile, "L2-норма: " + std::to_string(vec1.L2norm()));

    logResult(outFile, "\nИсходный вектор:");
    vec1.print(outFile);

    logResult(outFile, "\n▶ Тестирование арифметических операций:");
    logResult(outFile, "Сложение:\n" + std::to_string((vec1 + vec2).sum()));
    logResult(outFile, "Разность:\n" + std::to_string((vec1 - vec2).sum()));
    logResult(outFile, "Умножение на 2.5:\n" + std::to_string((vec1 * 2.5).sum()));

    logResult(outFile, "\n▶ Тестирование скалярного произведения:");
    logResult(outFile, "vec1 | vec2 = " + std::to_string((vec1 | vec2)));

    logResult(outFile, "\n▶ Тестирование экстремальных значений:");
    logResult(outFile, "Максимальный элемент: " + std::to_string(vec1.maxElement()));
    logResult(outFile, "Минимальный элемент: " + std::to_string(vec1.minElement()));

    logResult(outFile, "\n▶ Тестирование палиндрома:");
    logResult(outFile, "Является ли вектор палиндромом: " + std::string(vec1.iaPalindrome() ? "Да" : "Нет"));

    logResult(outFile, "\n▶ Добавление элемента (99.99):");
    vec1.push_back(99.99);
    vec1.print(outFile);
    logResult(outFile, "Размер после добавления: " + std::to_string(vec1.size()));

    logResult(outFile, "\n▶ Удаление последнего элемента:");
    vec1.pop_back();
    vec1.print(outFile);
    logResult(outFile, "Размер после удаления: " + std::to_string(vec1.size()));

    logResult(outFile, "\n▶ Тестирование угла между векторами:");
    try {
        double angleRad = vec1.angle(vec2);
        double angleDeg = angleRad * (180.0 / M_PI);
        logResult(outFile, "Угол между vec1 и vec2 (в радианах): " + std::to_string(angleRad));
        logResult(outFile, "Угол между vec1 и vec2 (в градусах): " + std::to_string(angleDeg));
    } catch (const std::exception& e) {
        logResult(outFile, "Ошибка вычисления угла: " + std::string(e.what()));
    }

    logResult(outFile, "\n▶ Тестирование расстояния между векторами:");
    try {
        double dist = vec1.distance(vec2);
        logResult(outFile, "Расстояние между vec1 и vec2: " + std::to_string(dist));
    } catch (const std::exception& e) {
        logResult(outFile, "Ошибка вычисления расстояния: " + std::string(e.what()));
    }

    logResult(outFile, "\nТестирование завершено.");
}
