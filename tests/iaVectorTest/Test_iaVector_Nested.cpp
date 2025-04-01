#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cmath>
#include "../../iaMath/iaLinearAlgebra/iaVector/iaVector.hpp" // Проверь путь!

/// Функция для вывода в консоль и в файл
void logResult(std::ostream& out, const std::string& message) {
    out << message << std::endl;  // Запись в поток (консоль или файл)
}

void testNestedVectors(std::ifstream& inFile, std::ofstream& outFile);

int main() {
    // Пути к файлам
    std::string inputFilePath = "tests/TestsDatas/iaVector_Nested.txt";
    std::string outputFilePath = "tests/TestsResults/iaVector_Nested.txt";

    // Информация для отладки
    logResult(std::cout, "Текущая рабочая директория: " + std::filesystem::current_path().string());
    logResult(std::cout, "Открываем файл: " + std::filesystem::absolute(inputFilePath).string());

    // Открываем файлы
    std::ifstream inFile(inputFilePath);
    std::ofstream outFile(outputFilePath);

    // Проверка файлов
    if (!inFile) {
        logResult(std::cerr, "Ошибка: не удалось открыть " + inputFilePath + " (errno: " + std::to_string(errno) + " - " + std::strerror(errno) + ")");
        return 1;
    }
    if (!outFile) {
        logResult(std::cerr, "Ошибка: не удалось открыть " + outputFilePath + " (errno: " + std::to_string(errno) + " - " + std::strerror(errno) + ")");
        return 1;
    }

    // Запускаем тест
    testNestedVectors(inFile, outFile);

    logResult(std::cout, "Тестирование завершено. Результаты в " + outputFilePath);
    return 0;
}

/**
 * @brief Тестирование работы с вложенными векторами и всех их методов
 *
 * @param inFile  Входной файл с тестовыми данными
 * @param outFile Файл для записи результатов тестирования
 */
void testNestedVectors(std::ifstream& inFile, std::ofstream& outFile) {
    size_t outerSize;
    inFile >> outerSize;

    if (outerSize == 0) {
        logResult(outFile, "Ошибка: Количество вложенных векторов = 0. Нечего тестировать.\n");
        return;
    }

    logResult(outFile, "▶ Тестирование iaVector<iaVector>:\n");

    iaVector<iaVector<double>> nestedVec;

    // Чтение данных из входного файла
    for (size_t i = 0; i < outerSize; i++) {
        size_t innerSize;
        inFile >> innerSize;
        std::vector<double> innerData(innerSize);

        for (size_t j = 0; j < innerSize; j++) {
            inFile >> innerData[j];
        }

        nestedVec.push_back(iaVector<double>(innerSize, innerData.data()));
    }

    // Выводим начальный вложенный вектор
    logResult(outFile, "Исходные вложенные векторы:\n");
    for (size_t i = 0; i < nestedVec.size(); i++) {
        nestedVec[i].print(outFile);
    }

    // Тестируем методы на двух первых векторах (если их хотя бы два)
    if (nestedVec.size() >= 2) {
        iaVector<double>& vec1 = nestedVec[0];
        iaVector<double>& vec2 = nestedVec[1];

        logResult(outFile, "\n▶ Тестирование арифметических операций:\n");
        logResult(outFile, "Сложение:\n");
        (vec1 + vec2).print(outFile);
        logResult(outFile, "Разность:\n");
        (vec1 - vec2).print(outFile);

        logResult(outFile, "\n▶ Тестирование скалярного произведения:\n");
        logResult(outFile, "vec1 | vec2 = " + std::to_string(vec1 | vec2) + "\n");

        logResult(outFile, "\n▶ Тестирование норм и суммы:\n");
        logResult(outFile, "Сумма vec1: " + std::to_string(vec1.sum()) + "\n");
        logResult(outFile, "L1-норма vec1: " + std::to_string(vec1.L1norm()) + "\n");
        logResult(outFile, "L2-норма vec1: " + std::to_string(vec1.L2norm()) + "\n");

        logResult(outFile, "\n▶ Тестирование угла между векторами:\n");
        double angle = vec1.angle(vec2);
        logResult(outFile, "Угол между vec1 и vec2 (в радианах): " + std::to_string(angle) + "\n");
        logResult(outFile, "Угол между vec1 и vec2 (в градусах): " + std::to_string(angle * (180.0 / M_PI)) + "\n");

        logResult(outFile, "\n▶ Тестирование расстояния между векторами:\n");
        double distance = vec1.distance(vec2);
        logResult(outFile, "Расстояние между vec1 и vec2: " + std::to_string(distance) + "\n");

        logResult(outFile, "\n▶ Добавление нового вектора:\n");
        double newVecData[] = {10, 20, 30};
        iaVector<double> newVec(3, newVecData);
        nestedVec.push_back(newVec);

        for (size_t i = 0; i < nestedVec.size(); i++) {
            nestedVec[i].print(outFile);
        }

        logResult(outFile, "\n▶ Добавление нового элемента в конец одного вектора:\n");
        double newD = 40;
        nestedVec[2].push_back(newD);

        for (size_t i = 0; i < nestedVec.size(); i++) {
            nestedVec[i].print(outFile);
        }

        logResult(outFile, "\nДоступ к одному элементу: " + std::to_string(nestedVec[2][2]) + "\n");

    } else {
        logResult(outFile, "\nНедостаточно данных для тестирования всех методов (нужно минимум 2 вектора).\n");
    }
}
