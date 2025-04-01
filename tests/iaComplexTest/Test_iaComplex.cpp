#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include "../../iaMath/iaLinearAlgebra/iaComplex/iaComplex.hpp" // Проверьте правильность пути

void logResult(std::ostream& out, const std::string& message) {
    std::cout << message << std::endl;  // Вывод в консоль
    out << message << std::endl;        // Запись в файл
}

int main() {
    // Открытие входного файла с тестовыми данными
    std::ifstream inputFile("tests/TestsDatas/iaComplex.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл с тестовыми данными." << std::endl;
        return 1;
    }

    // Открытие выходного файла для записи результатов
    std::ofstream outputFile("tests/TestsResults/iaComplex.txt");
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл для записи результатов." << std::endl;
        return 1;
    }

    logResult(outputFile, "▶ Тестирование класса iaComplex - ");


    // Чтение данных из входного файла
    double real1, imag1, real2, imag2;
    inputFile >> real1 >> imag1 >> real2 >> imag2;

    // Создание комплексных чисел
    iaComplex c1(real1, imag1);
    iaComplex c2(real2, imag2);

    // Выполнение операций и запись результатов в выходной файл
    logResult(outputFile, "c1 = " + (std::ostringstream() << c1).str());
    logResult(outputFile, "c2 = " + (std::ostringstream() << c2).str());
    std::ostringstream oss;
    oss << (c1 + c2);
    logResult(outputFile, "c1 + c2 = " + oss.str());
    oss << (c1 - c2);
    logResult(outputFile, "c1 - c2 = " + oss.str());
    oss << (c1 * c2);
    logResult(outputFile, "c1 * c2 = " + oss.str());
    oss << (c1 /c2);
    logResult(outputFile, "c1 / c2 = " + oss.str());

    // Закрытие файлов
    inputFile.close();
    outputFile.close();

    std::cout << "Тестирование завершено. Результаты сохранены в tests/TestsResults/iaComplexTest.txt" << std::endl;
    return 0;
}
