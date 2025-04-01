#include "iaDerivatives.cpp"  // Подключение производных
#include <iostream>
#include <fstream>
#include "iaVector.hpp"
#include <random>
#include <stdexcept>  // Для обработки исключений
#include <string>

/// Функция для вывода в консоль и в файл
void logResult(std::ostream& out, const std::string& message) {
    out << message << std::endl;  // Запись в поток (консоль или файл)
}

std::ifstream openFileToTest(const std::string& filePath) {
    std::ifstream input(filePath);
    // Проверка на успешное открытие файлов
    if (!input.is_open()) {
        logResult(std::cerr, "Ошибка открытия входного файла!");
        return std::ifstream();
    }
    return input;
}

// Функция для обработки команды
void processCommand(char command, const std::string& filePath) {
    switch (command) {
        case 't': {
            std::cout << "Команда 't' получена. Путь к файлу: " << filePath << std::endl;
            break;
        }

    //    case 'r':
    //        std::cout << "Команда 'r' получена. Путь к файлу: " << filePath << std::endl;
    //        break;

        default:
            std::cerr << "Ошибка: неизвестная команда '" << command << "'." << std::endl;
            break;
    }
}



int main(int argc, char* argv[]) {
    // Проверяем количество аргументов
    if (argc < 3) {
        std::cerr << "Ошибка: недостаточно аргументов." << std::endl;
        return 1;
    }

    // Читаем первый аргумент (символ)
    char command = argv[1][0]; // Первый символ из первого аргумента
    std::string filePath = argv[2]; // Второй аргумент — путь к файлу

    

    // Выводим значения для проверки
 //   std::cout << "Команда: " << command << std::endl;
  //  std::cout << "Путь к файлу: " << filePath << std::endl;

processCommand(command, filePath);



    double λ = 1.0507;
    double α = 1.67326;



    using namespace iaMath::iaFunctions;
/*
    std::ifstream input("tests/TestsDatas/iaDerivatives.txt");
    std::ofstream output("tests/TestsResults/iaDerivatives.txt");

    // Проверка на успешное открытие файлов
    if (!input.is_open()) {
        logResult(std::cerr, "Ошибка открытия входного файла!");
        return 1;
    }

    if (!output.is_open()) {
        logResult(std::cerr, "Ошибка открытия выходного файла!");
        return 1;
    }
*/
    std::ofstream output("tests/TestsResults/iaDerivatives.txt");
    if (!output.is_open()) {
        logResult(std::cerr, "Ошибка открытия выходного файла!");
        return 1;
    }

    logResult(output, "▶ Тестирование производных от функций активации:\n");
    std::ifstream input = openFileToTest(filePath);
    

    iaVector<double> values;
    double x;
    while (input >> x) {
        values.push_back(x);
    }

    // Вывод значений, считанных из файла
    logResult(output, "Считанные значения:");
    values.print(output);

    // Процесс тестирования для всех значений
    logResult(output, "\n▶ Результаты вычислений производных для значений:");

    for (size_t i = 0; i < values.size(); i++) {
        x = values[i];
        logResult(output, "--------------------");
        logResult(output, "x = " + std::to_string(x));

        logResult(output, "λ = " + std::to_string(λ));
        logResult(output, "α = " + std::to_string(α));

        // Здесь вызываются функции производных
        logResult(output, "▶ derIdentity: " + std::to_string(derIdentity(x)));
        logResult(output, "▶ derHeaviside: " + std::to_string(derHeaviside(x)));
        logResult(output, "▶ derSigmoid: " + std::to_string(derSigmoid(x)));
        logResult(output, "▶ derTanh: " + std::to_string(derTanh(x)));

        try {
            logResult(output, "▶ derArctanh: " + std::to_string(derArctanh(x)));  // Обработка исключения для аркгиперболического тангенса
        } catch (const std::domain_error& e) {
            logResult(output, "▶ derArctanh: Ошибка: " + std::string(e.what()));
        }

        // Тестирование для других производных
        logResult(output, "▶ derSoftsign: " + std::to_string(derSoftsign(x)));
        logResult(output, "▶ derRelu: " + std::to_string(derRelu(x)));
        logResult(output, "▶ derLrelu: " + std::to_string(derLrelu(x)));
        logResult(output, "▶ derHardSwish: " + std::to_string(derHardSwish(x)));
        logResult(output, "▶ derSoftShrinkr: " + std::to_string(derSoftShrink(x, λ)));
        logResult(output, "▶ derIsru: " + std::to_string(derIsru(x, α)));
        logResult(output, "▶ derRrelu: " + std::to_string(derRrelu(x, α)));
        logResult(output, "▶ derSelu: " + std::to_string(derSelu(x, 0.1, 0.01)));
    }

    /*
    // Массив значений для softmax
    std::vector<double> softmax_values = values;

    // Применяем softmax ко всему вектору значений только один раз
    softmax(softmax_values.data(), softmax_values.size());

    // Выводим softmax для всего вектора в конце
    logResult(output, "▶ softmax:");
    for (double sm : softmax_values) {
        output << sm << " ";
    }
    */
    
    output << "\n";

    input.close();
    output.close();
    return 0;
}
