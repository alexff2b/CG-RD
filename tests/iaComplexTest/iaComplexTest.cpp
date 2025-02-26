#include "iaMath/iaLinearAlgebra/iaComplex/iaComplex.hpp"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("data_to_tests/iaComplex.txt");
    std::ofstream outputFile("Tests_Results/iaComplex.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть входной файл iaComplexTest/In.txt!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть выходной файл iaComplexTest/Out.txt!" << std::endl;
        return 1;
    }

    double r1, i1, r2, i2;
    if (!(inputFile >> r1 >> i1 >> r2 >> i2)) {
        std::cerr << "Ошибка: недостаточно данных в iaComplexTest/In.txt!" << std::endl;
        return 1;
    }

    iaComplex c1(r1, i1);
    iaComplex c2(r2, i2);

    // Используем перегруженный оператор <<
    outputFile << "c1: " << c1 << std::endl;
    outputFile << "c2: " << c2 << std::endl;

    outputFile << "sum (c1 + c2): " << (c1 + c2) << std::endl;
    outputFile << "difference (c1 - c2): " << (c1 - c2) << std::endl;
    outputFile << "product (c1 * c2): " << (c1 * c2) << std::endl;

    if (c2 == iaComplex(0, 0)) {
        outputFile << "Error: division by zero is not allowed!\n";
    } else {
        outputFile << "quotient (c1 / c2): " << (c1 / c2) << std::endl;
    }

    outputFile << "conjugate of c1: " << c1.conjugate() << std::endl;

    outputFile << "magnitude of c1: " << c1.magnitude() << std::endl;
    outputFile << "argument of c1: " << c1.argument() << " radians" << std::endl;

    if (c1 == c2) {
        outputFile << "c1 and c2 are equal.\n";
    } else {
        outputFile << "c1 and c2 are not equal.\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
