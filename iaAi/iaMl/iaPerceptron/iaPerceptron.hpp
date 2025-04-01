/*
 ****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra
 *    @file       : iaPerceptron.hpp
 *    @brief      : Заголовочный файл для класса iaPerceptron, использующего класс iaVector.
 *    @author     : Александра Юшкевича
 *    @aka        : iA, alexff
 *    @project    : Базовая библиотека классов для проектов Helios Prime - Nova Terra
 *    @version    : 0.2.0 (Стабильная версия - первая проба реализации)
 *    @license    : Лицензия MIT
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr.+33658046456
 *                  rus. +79859751326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Январь 2025
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Первая проба реализации класса iaPerceptron.
 *
 *    @description: Этот класс представляет перцептрон, который может использоваться для
 *                   выполнения задач машинного обучения. Он использует класс iaVector для
 *                   хранения весов и выполнения математических операций. Класс включает методы
 *                   для обучения и предсказания, а также для обновления весов.
 *
 *    @methods     :
 *                   - iaPerceptron(); // Конструктор по умолчанию
 *                   - iaPerceptron(int m); // Конструктор с размером
 *                   - iaPerceptron(int m, double weights[]); // Конструктор с массивом весов
 *                   - iaPerceptron(int m, iaVector weights); // Конструктор с объектом iaVector
 *                   - iaPerceptron(const iaPerceptron& otherPerceptron); // Конструктор копирования
 *                   - ~iaPerceptron(); // Деструктор
 *                   - void printPerceptron() const; // Печатает перцептрон
 *                   - double forward(iaVector input); // Прямое распространение
 *                   - iaPerceptron& operator=(const iaPerceptron& otherPerceptron) noexcept; // Оператор присваивания
 *                   - void train(iaVector input, double target, double learningrate, double bias); // Метод для обучения
 *                   - double predict(iaVector input); // Метод для предсказания
 *                   - void updateWeights(double error, iaVector input); // Метод для обновления весов
 *
 *    @properties  :
 *                   - int input_size;      ///< Количество входов
 *                   - iaVector weights;     ///< Поле для хранения весов
 *                   - double bias;         ///< Смещение
 *                   - double learning_rate; ///< Скорость обучения
 *
 *    @copyright    : Этот файл является частью проектов Helios Prime - Nova Terra. Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 * **************************************************************************************************
 */

#ifndef IA_PERCEPTRON_HPP
#define IA_PERCEPTRON_HPP

#include <iostream>
#include <vector>
#include <random>
#include "iaMath/iaLinearAlgebra/iaVector/iaVector.hpp"
#include "iaMath/iaFunctions/iaActivations.hpp"
#include "iaMath/iaFunctions/iaDerivatives.hpp"

/**
 * @class iaPerceptron
 * @brief Класс, реализующий простой однослойный перцептрон.
 */
class iaPerceptron {
public:
    /**
     * @brief Конструктор по умолчанию.
     * Создает перцептрон с 2 входами, случайными весами и смещением.
     */
    iaPerceptron();

    /**
     * @brief Конструктор с заданным количеством входов.
     * @param m Количество входов.
     */
    explicit iaPerceptron(int m);

    /**
     * @brief Конструктор с заданными весами.
     * @param m Количество входов.
     * @param weights Массив весов.
     */
    iaPerceptron(int m, const double* weights);

    /**
     * @brief Конструктор с вектором весов.
     * @param m Количество входов.
     * @param weights Вектор весов.
     */
    iaPerceptron(int m, const iaVector<double>& weights);

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект iaPerceptron.
     */
    iaPerceptron(const iaPerceptron& other);

    /**
     * @brief Оператор присваивания.
     * @param other Другой объект iaPerceptron.
     * @return Ссылка на текущий объект.
     */
    iaPerceptron& operator=(const iaPerceptron& other) noexcept;

    /**
     * @brief Деструктор (по умолчанию).
     */
    ~iaPerceptron() = default;

    /**
     * @brief Вывод информации о перцептроне.
     * @param out Поток вывода (по умолчанию std::cout).
     */
    void printPerceptron(std::ostream& out = std::cout) const;

    /**
     * @brief Прямое распространение сигнала.
     * @param input Входной вектор.
     * @return Результат активационной функции.
     */
    double forward(const iaVector<double>& input) const;

    /**
     * @brief Обучение перцептрона.
     * @param input Входной вектор.
     * @param target Ожидаемый выход.
     * @param learningRate Скорость обучения.
     * @param bias Смещение.
     */
    void train(const iaVector<double>& input, double target, double learningRate, double bias);

    /**
     * @brief Предсказание на основе входных данных.
     * @param input Входной вектор.
     * @return Результат предсказания.
     */
    inline double predict(const iaVector<double>& input) const { return forward(input); }

    /**
     * @brief Обновление весов на основе градиента.
     * @param input Входной вектор.
     * @param gradient Значение градиента.
     */
    void updateWeights(const iaVector<double>& input, double gradient);

private:
    int input_size = 2;  ///< Количество входов.
    iaVector<double> weights;  ///< Вектор весов.
    double bias = 1.0;  ///< Смещение (bias).
    double learning_rate = 0.1;  ///< Скорость обучения.
};

#endif // IA_PERCEPTRON_HPP
