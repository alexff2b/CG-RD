#include "../../iaMath/iaFunctions/iaActivations.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <stdexcept>  // Для обработки исключений

// Функция для вывода в консоль и в файл
void logResult(std::ofstream& out, const std::string& message) {
    std::cout << message << std::endl;  // Вывод в консоль
    out << message << std::endl;        // Запись в файл
}

int main() {
    using namespace iaMath::iaFunctions;

    std::ifstream input("tests/TestsDatas/iaActivations.txt");
    std::ofstream output("tests/TestsResults/iaActivations.txt");

    // Проверка на успешное открытие файлов
    if (!input.is_open()) {
        std::cerr << "Ошибка открытия входного файла!" << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cerr << "Ошибка открытия выходного файла!" << std::endl;
        return 1;
    }

    logResult(output, "▶ Тестирование iaActivations:");

    std::vector<double> values;
    double x;
    while (input >> x) {
        values.push_back(x);
    }

    // Вывод значений, считанных из файла
    logResult(output, "Считанные значения:");
    output << '[';
    for (double v : values) output << v << " ";
    output << "]\n";

    // Процесс тестирования для всех значений
    for (double x : values) {
        logResult(output, "--------------------");
        logResult(output, "x = " + std::to_string(x));
        logResult(output, "▶ identity: " + std::to_string(identity(x)));
        logResult(output, "▶ heaviside: " + std::to_string(heaviside(x)));
        logResult(output, "▶ sigmoid: " + std::to_string(sigmoid(x)));
        logResult(output, "▶ tanh: " + std::to_string(tanh(x)));

        try {
            logResult(output, "▶ arctanh: " + std::to_string(arctanh(x)));  // Обработка исключения
        } catch (const std::domain_error& e) {
            logResult(output, "▶ arctanh: Ошибка: " + std::string(e.what()));
        }

        logResult(output, "▶ softsign: " + std::to_string(softsign(x)));
        logResult(output, "▶ relu: " + std::to_string(relu(x)));
        logResult(output, "▶ lrelu: " + std::to_string(lrelu(x)));
        logResult(output, "▶ hardSwish: " + std::to_string(hardSwish(x)));
        logResult(output, "▶ softshrink: " + std::to_string(softshrink(x, 0.1)));
        logResult(output, "▶ isru: " + std::to_string(isru(x, 0.01)));
        logResult(output, "▶ rrelu: " + std::to_string(rrelu(x, 0.01)));
        logResult(output, "▶ selu: " + std::to_string(selu(x, 0.1, 0.01)));
    }

    // Массив значений для softmax
    std::vector<double> softmax_values = values;

    // Применяем softmax ко всему вектору значений только один раз
    softmax(softmax_values.data(), softmax_values.size());

    // Выводим softmax для всего вектора в конце
    logResult(output, "▶ softmax:");
    for (double sm : softmax_values) {
        output << sm << " ";
    }
    output << "\n";

    input.close();
    output.close();
    return 0;
}
