#include <iostream>
#include <fstream>
#include <vector>
#include "iaPerceptron.hpp"

#define INPUT_FILE  "tests/TestsDatas/iaPerceptron.txt"
#define OUTPUT_FILE "tests/TestsResults/iaPerceptron.txt"

void logResult(std::ostream& out, const std::string& message) {
    std::cout << message << std::endl;  // Вывод в консоль
    out << message << std::endl;        // Запись в файл
}

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл с тестовыми данными: " << INPUT_FILE << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл для записи результатов: " << OUTPUT_FILE << std::endl;
        return 1;
    }



    // Чтение размера входа
    int inputSize;
    inputFile >> inputSize;
    if (inputSize <= 0) {
        std::cerr << "Ошибка: некорректный размер входа." << std::endl;
        return 1;
    }

    // Чтение весов
    iaVector<double> weights(inputSize);
    for (int i = 0; i < inputSize; ++i) {
        inputFile >> weights[i];

    }

    // Создание перцептрона
    iaPerceptron perceptron(inputSize, weights);
    logResult(outputFile, "▶Тест класса Перцептрон");
    logResult(outputFile, "▶Создан перцептрон с заданными весами.");
    
    // Вывод информации о перцептроне
    perceptron.printPerceptron(outputFile);

    // Тест метода forward
    iaVector<double> testInput(inputSize);
    for (int i = 0; i < inputSize; ++i) {
        inputFile >> testInput[i];
    }
    double forwardResult = perceptron.forward(testInput);
    logResult(outputFile, "▶Тест forward: " + std::to_string(forwardResult));

    // Тест метода predict
    double predictResult = perceptron.predict(testInput);
    logResult(outputFile, "▶Тест predict: " + std::to_string(predictResult));

    // Тест метода train
    double target, learningRate, bias;
    inputFile >> target >> learningRate >> bias;
    perceptron.train(testInput, target, learningRate, bias);
    logResult(outputFile, "▶Тест train: Обучение выполнено.");

    // Тест метода updateWeights
    double gradient;
    inputFile >> gradient;
    perceptron.updateWeights(testInput, gradient);
    logResult(outputFile, "▶Тест updateWeights: Веса обновлены.");

    logResult(outputFile, "▶Все тесты успешно выполнены!");

    inputFile.close();
    outputFile.close();
    return 0;
}
