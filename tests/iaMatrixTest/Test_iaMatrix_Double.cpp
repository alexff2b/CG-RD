#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <cerrno>
#include <cstring>
#include "iaMatrix.hpp"  // Убедитесь, что этот заголовочный файл корректен

void logResult(std::ostream& out, const std::string& message) {
    std::cout << message << std::endl;
    out << message << std::endl;
}

bool readMatrix(std::ifstream& inFile, iaMatrix<double>& matrix, std::ostream& outFile, int index) {
    size_t rows, cols;
    inFile >> rows >> cols;
    
    if (rows == 0 || cols == 0) {
        logResult(outFile, "Ошибка: Некорректный размер матрицы (" + std::to_string(rows) + "x" + std::to_string(cols) + ")");
        return false;
    }

    matrix = iaMatrix<double>(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            inFile >> matrix[i][j];
        }
    }

    logResult(outFile, "Исходная матрица " + std::to_string(index) + " (" + std::to_string(rows) + "x" + std::to_string(cols) + "):");
    matrix.print(outFile);
    return true;
}

int main() {
    std::string inputFilePath = "tests/TestsDatas/iaMatrix.txt";
    std::string outputFilePath = "tests/TestsResults/iaMatrix.txt";

    std::cout << "Текущая рабочая директория: " << std::filesystem::current_path() << std::endl;
    std::cout << "Открываем файл: " << std::filesystem::absolute(inputFilePath) << std::endl;

    std::ifstream inFile(inputFilePath);
    std::ofstream outFile(outputFilePath);

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

    logResult(outFile, "▶ Тестирование iaMatrix:");

    std::vector<iaMatrix<double>> matrices(6);

    // Читаем 6 матриц из файла
    for (int i = 0; i < 6; ++i) {
        if (!readMatrix(inFile, matrices[i], outFile, i + 1)) {
            return 1;
        }
    }

    // Тестирование операций
    logResult(outFile, "\n▶ Доступ к одному элементу: " + std::to_string(matrices[0][2][1]));
    logResult(outFile, "▶ Матрица 1 квадратная? " + std::string(matrices[0].isSquare() ? "Да" : "Нет"));

    if (matrices[0].isSquare()) {
        logResult(outFile, "▶ Главная диагональ:");
        matrices[0].getDiagonal().print(outFile);

        logResult(outFile, "▶ Побочная диагональ:");
        matrices[0].getSecondaryDiagonal().print(outFile);

        logResult(outFile, "▶ Матрицы 1 и 2 равны? " + std::string(matrices[0] == matrices[1] ? "Да" : "Нет"));
        logResult(outFile, "▶ Матрица 1 диагональная? " + std::string(matrices[0].isDiagonal() ? "Да" : "Нет"));
        logResult(outFile, "▶ Матрица 2 единичная? " + std::string(matrices[1].isIdentity() ? "Да" : "Нет"));
        logResult(outFile, "▶ Матрица 3 верхнетреугольная? " + std::string(matrices[2].isUpTriang() ? "Да" : "Нет"));
        logResult(outFile, "▶ Матрица 4 нижнетреугольная? " + std::string(matrices[3].isLowTriang() ? "Да" : "Нет"));
    }

    // Пример использования методов для поворота матрицы
    iaMatrix<double> turned90 = matrices[0].turn90();
    iaMatrix<double> turned180 = matrices[0].turn180();
    iaMatrix<double> turned270 = matrices[0].turn270();

    logResult(outFile, "\n▶ Матрица 1 повернута на 90°:");
    turned90.print(outFile);

    logResult(outFile, "▶ Матрица 1 повернута на 180°:");
    turned180.print(outFile);

    logResult(outFile, "▶ Матрица 1 повернута на 270°:");
    turned270.print(outFile);

    // Проверка симметрии и косимметрии
    logResult(outFile, "\n▶ Матрица 1 симметрична? " + std::string(matrices[0].isSymmetric() ? "Да" : "Нет"));
    logResult(outFile, "▶ Матрица 1 косимметрична? " + std::string(matrices[0].isCoSymmetric() ? "Да" : "Нет"));

    matrices[2].print(outFile);



    logResult(outFile, "▶ Определитель Матрицы 3 " + std::to_string(matrices[2].Determinant()));
    logResult(outFile, "\n▶ Минорный элемент: " + std::to_string(matrices[2][2][2]));
    logResult(outFile, "▶ Минор Матрицы 3, по элементу 3,3 " + std::to_string(matrices[2].minor(2,2)));

    logResult(outFile, "\n▶ Минорный элемент дополнения: " + std::to_string(matrices[2][1][2]));
    logResult(outFile, "▶ Алгебраическое дополнение  Матрицы 3, по элементу 1,2 " + std::to_string(matrices[2].complement(1,2)));

    iaMatrix<int> X;
    iaVector<int> row1(3, {4,1,3});
    X.push_back(row1);
    iaVector<int> row2(3, {-2, 1, 0});
    X.push_back(row2);
    iaVector<int. row3(3, {-2, 1, 0});
    X.push_back(row3);
    X.print(outFile);
    logResult(outFile, "▶ Определитель " + std::to_string(X.Determinant()));






    return 0;
}
