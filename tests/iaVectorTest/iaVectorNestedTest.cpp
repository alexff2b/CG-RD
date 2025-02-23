#include <iostream>
#include <fstream>
#include "../../iaAi/iaMl/iaVector/iaVector.hpp"

int main() {
    std::ifstream inputFile("../../tests/data_to_tests/iaVectorNestedTest.txt");
    std::ofstream outputFile("../../tests/Tests_Results/iaVectorNestedTestResults.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла входных данных!" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла результатов!" << std::endl;
        return 1;
    }

    int numVectors, vectorSize;
    inputFile >> numVectors >> vectorSize;

    iaVector<iaVector<int>> nestedVectors(numVectors);
    
    for (int i = 0; i < numVectors; ++i) {
        iaVector<int> tempVector(vectorSize);
        for (int j = 0; j < vectorSize; ++j) {
            int value;
            inputFile >> value;
            tempVector[j] = value;
        }
        nestedVectors[i] = tempVector;
    }

    outputFile << "Исходные векторы:\n";
    nestedVectors.print(outputFile);

    // Пример операций над вложенными векторами
    if (numVectors > 1) {
        outputFile << "Сложение первых двух вложенных векторов:\n";
        iaVector<int> sumVector = nestedVectors[0] + nestedVectors[1];
        sumVector.print(outputFile);
        
        outputFile << "Вычитание первых двух вложенных векторов:\n";
        iaVector<int> subVector = nestedVectors[0] - nestedVectors[1];
        subVector.print(outputFile);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Тестирование завершено. Результаты записаны в файл.\n";
    return 0;
}
