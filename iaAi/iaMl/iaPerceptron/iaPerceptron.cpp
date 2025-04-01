#include "iaPerceptron.hpp"
#include "iaMath/iaFunctions/iaActivations.hpp"
#include "iaMath/iaFunctions/iaDerivatives.hpp"

/**
 * @brief Конструктор по умолчанию.
 * Создает перцептрон с 2 входами, случайными весами и смещением.
 */
iaPerceptron::iaPerceptron() {
    weights = iaVector<double>(input_size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    // Инициализация весов случайными значениями
    for (int i = 0; i < input_size; ++i) {
        weights[i] = dis(gen);
    }
    bias = dis(gen);
}

/**
 * @brief Конструктор с заданным количеством входов.
 * @param m Количество входов.
 */
iaPerceptron::iaPerceptron(int m) : input_size(m) {
    weights = iaVector<double>(input_size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    // Инициализация весов случайными значениями
    for (int i = 0; i < input_size; ++i) {
        weights[i] = dis(gen);
    }
    bias = dis(gen);
}

/**
 * @brief Конструктор с заданными весами.
 * @param m Количество входов.
 * @param weights Массив весов.
 */
iaPerceptron::iaPerceptron(int m, const double* weights) : input_size(m), weights(input_size) {
    for (int i = 0; i < input_size; ++i) {
        this->weights[i] = weights[i];
    }
    bias = 1.0; // По умолчанию
}

/**
 * @brief Конструктор с вектором весов.
 * @param m Количество входов.
 * @param weights Вектор весов.
 */
iaPerceptron::iaPerceptron(int m, const iaVector<double>& weights) : input_size(m), weights(weights) {
    bias = 1.0; // По умолчанию
}

/**
 * @brief Конструктор копирования.
 * @param other Другой объект iaPerceptron.
 */
iaPerceptron::iaPerceptron(const iaPerceptron& other) 
    : input_size(other.input_size), weights(other.weights), bias(other.bias) {}

/**
 * @brief Оператор присваивания.
 * @param other Другой объект iaPerceptron.
 * @return Ссылка на текущий объект.
 */
iaPerceptron& iaPerceptron::operator=(const iaPerceptron& other) noexcept {
    if (this == &other) return *this;

    input_size = other.input_size;
    weights = other.weights;
    bias = other.bias;

    return *this;
}

/**
 * @brief Метод для вывода информации о состоянии перцептрона.
 * @param out Поток вывода (по умолчанию std::cout).
 */
void iaPerceptron::printPerceptron(std::ostream& out) const {
    out << "Перцептрон с " << input_size << " входами:" << std::endl;
    out << "Веса: ";
    for (size_t i = 0; i < weights.size(); ++i) {
        out << weights[i] << " ";
    }
    out << std::endl;
    out << "Смещение: " << bias << std::endl;
    out << "Скорость обучения: " << learning_rate << std::endl;
}

/**
 * @brief Прямое распространение сигнала (forward pass).
 * @param input Входной вектор.
 * @return Результат активационной функции.
 */
double iaPerceptron::forward(const iaVector<double>& input) const {
    // Проверка размеров
    if (input.size() != input_size) {
        throw std::invalid_argument("Размеры входных данных не совпадают с размером входа нейрона.");
    }

    // Прямой проход: вычисление выходного значения
    double z = (input | weights) + bias;  // Используем перегрузку оператора | (скалярное произведение)
    double output = iaMath::iaFunctions::sigmoid(z);  // Используем полное пространство имен для sigmoid
    return output;
}

/**
 * @brief Обучение перцептрона.
 * @param input Входной вектор.
 * @param target Ожидаемый выход.
 * @param learningRate Скорость обучения.
 * @param bias Смещение.
 */
void iaPerceptron::train(const iaVector<double>& input, double target, double learningRate, double bias) {
    // Проверка размеров
    if (input.size() != input_size) {
        throw std::invalid_argument("Размеры входных данных не совпадают с размером входа нейрона.");
    }

    // Прямой проход: вычисление выходного значения
    double z = (input | weights) + bias;  // Используем перегрузку оператора | (скалярное произведение)
    double output = iaMath::iaFunctions::sigmoid(z);  // Используем полное пространство имен для sigmoid

    // Вычисление ошибки
    double error = target - output;

    // Обратное распространение: обновление весов и смещения
    double gradient = error * iaMath::iaFunctions::derSigmoid(output);  // Используем полное пространство имен для derSigmoid

    // Обновление весов
    for (size_t i = 0; i < input.size(); ++i) {
        weights[i] += learningRate * gradient * input[i];
    }

    // Обновление смещения
    this->bias += learningRate * gradient;
}

/**
 * @brief Обновление весов на основе градиента.
 * @param input Входной вектор.
 * @param gradient Значение градиента.
 */
void iaPerceptron::updateWeights(const iaVector<double>& input, double gradient) {
    // Обновление весов
    for (size_t i = 0; i < input.size(); ++i) {
        weights[i] += learning_rate * gradient * input[i];
    }
}

