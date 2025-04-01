//
//  iaApplic.hpp
//  Classes_DevTest
//
//  Created by alexff on 28/01/2025.
//

#ifndef iaApplic_hpp
#define iaApplic_hpp


#include <stdio.h>
#include <cmath>

#include <stdio.h>

// Основные физические величины

// Масса объекта (в килограммах)
double mass; // kg

// Ускорение (в метрах на секунду в квадрате)
double acceleration; // m/s^2

// Сила (в ньютонах)
double force; // N = kg * m/s^2

// Скорость (в метрах в секунду)
double velocity; // m/s

// Путь (в метрах)
double distance; // m

// Время (в секундах)
//double time; // s

// Импульс (в килограмм-метрах в секунду)
double momentum; // kg*m/s

// Работа (в джоулях)
double work; // J = N*m

// Кинетическая энергия (в джоулях)
double kinetic_energy; // J = 0.5 * m * v^2

// Потенциальная энергия (в джоулях)
double potential_energy; // J = m * g * h

// Угловая скорость (в радианах в секунду)
double angular_velocity; // rad/s

// Угловое ускорение (в радианах в секунду в квадрате)
double angular_acceleration; // rad/s^2

// Радиус (в метрах)
double radius; // m

// Гравитационная постоянная (в метрах в секунду в квадрате)
const double g = 9.81; // m/s^2 (ускорение свободного падения на поверхности Земли)





// Функции преобразования

/**
 * @brief Преобразует радианы в градусы.
 *
 * Эта функция принимает значение в радианах и преобразует его в градусы
 * по формуле: градусы = радианы * (180 / π).
 *
 * @param rad Угол в радианах.
 * @return Угол в градусах.
 */
double radtodeg(double rad) {
    return rad * 180 / M_PI;
}

/**
 * @brief Преобразует градусы в радианы.
 *
 * Эта функция принимает значение в градусах и преобразует его в радианы
 * по формуле: радианы = градусы * (π / 180).
 *
 * @param deg Угол в градусах.
 * @return Угол в радианах.
 */
double degtorad(double deg) {
    return deg * M_PI / 180;
}


/**
 * @brief Преобразует температуру из Цельсия в Кельвины.
 *
 * @param celsius Температура в градусах Цельсия.
 * @return Температура в Кельвинах.
 */
double celsiusToKelvin(double celsius);

/**
 * @brief Преобразует температуру из Кельвинов в Цельсий.
 *
 * @param kelvin Температура в Кельвинах.
 * @return Температура в градусах Цельсия.
 */
double kelvinToCelsius(double kelvin);

/**
 * @brief Преобразует температуру из Фаренгейта в Цельсий.
 *
 * @param fahrenheit Температура в градусах Фаренгейта.
 * @return Температура в градусах Цельсия.
 */
double fahrenheitToCelsius(double fahrenheit);

/**
 * @brief Преобразует температуру из Цельсия в Фаренгейты.
 *
 * @param celsius Температура в градусах Цельсия.
 * @return Температура в градусах Фаренгейта.
 */
double celsiusToFahrenheit(double celsius);

/**
 * @brief Преобразует скорость из километров в час в метры в секунду.
 *
 * @param kmh Скорость в километрах в час.
 * @return Скорость в метрах в секунду.
 */
double kmhToMps(double kmh);

/**
 * @brief Преобразует скорость из метров в секунду в километры в час.
 *
 * @param mps Скорость в метрах в секунду.
 * @return Скорость в километрах в час.
 */
double mpsToKmh(double mps);

/**
 * @brief Преобразует массу из килограммов в граммы.
 *
 * @param kg Масса в килограммах.
 * @return Масса в граммах.
 */
double kgToGrams(double kg);

/**
 * @brief Преобразует массу из граммов в килограммы.
 *
 * @param grams Масса в граммах.
 * @return Масса в килограммах.
 */
double gramsToKg(double grams);

/**
 * @brief Преобразует расстояние из миль в километры.
 *
 * @param miles Расстояние в милях.
 * @return Расстояние в километрах.
 */
double milesToKilometers(double miles);

/**
 * @brief Преобразует расстояние из километров в мили.
 *
 * @param kilometers Расстояние в километрах.
 * @return Расстояние в милях.
 */
double kilometersToMiles(double kilometers);


/**
 * @brief Преобразует длину из метров в километры.
 *
 * @param meters Длина в метрах.
 * @return Длина в километрах.
 */
double metersToKilometers(double meters);

/**
 * @brief Преобразует длину из километров в метры.
 *
 * @param kilometers Длина в километрах.
 * @return Длина в метрах.
 */
double kilometersToMeters(double kilometers);

/**
 * @brief Преобразует массу из килограммов в граммы.
 *
 * @param kilograms Масса в килограммах.
 * @return Масса в граммах.
 */
double kilogramsToGrams(double kilograms);

/**
 * @brief Преобразует массу из граммов в килограммы.
 *
 * @param grams Масса в граммах.
 * @return Масса в килограммах.
 */
double gramsToKilograms(double grams);

/**
 * @brief Преобразует скорость из метров в секунду в километры в час.
 *
 * @param mps Скорость в метрах в секунду.
 * @return Скорость в километрах в час.
 */
double mpsToKmph(double mps);

/**
 * @brief Преобразует скорость из километров в час в метры в секунду.
 *
 * @param kmph Скорость в километрах в час.
 * @return Скорость в метрах в секунду.
 */
double kmphToMps(double kmph);



/**
 * @brief Вычисляет факториал заданного числа.
 *
 * Эта функция использует рекурсивный подход для вычисления факториала.
 * Факториал числа n (обозначается n!) равен произведению всех положительных
 * целых чисел от 1 до n. Факториал 0 определен как 1.
 *
 * @param num Целое число, для которого нужно вычислить факториал.
 * @return Факториал числа num.
 */
int fact(int num);

/**
 * @brief Вычисляет n-е число Фибоначчи.
 *
 * Эта функция использует рекурсивный подход для вычисления n-го числа
 * Фибоначчи. Последовательность Фибоначчи определяется следующим образом:
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) для n > 1.
 *
 * @param num Индекс числа Фибоначчи, которое нужно вычислить.
 * @return n-е число Фибоначчи.
 */
int fibo(int num);



//---функции активации

/**
 * @brief Тождественная функция активации.
 *
 * Эта функция возвращает входное значение без изменений.
 *
 * @param x Входное значение.
 * @return Возвращает x.
 */
double identify(double x);

/**
 * @brief Единичная ступенчатая функция активации.
 *
 * Эта функция возвращает 0, если x < 0, и 1, если x >= 0.
 *
 * @param x Входное значение.
 * @return 0 или 1 в зависимости от значения x.
 */
double Heaviside(double x);

/**
 * @brief Логистическая сигмоидная функция активации.
 *
 * Эта функция возвращает значение в диапазоне (0, 1) по формуле 1 / (1 + exp(-x)).
 *
 * @param x Входное значение.
 * @return Значение сигмоиды.
 */
double sigmoid(double x);

/**
 * @brief Гиперболический тангенс.
 *
 * Эта функция возвращает значение гиперболического тангенса по формуле (exp(x) - exp(-x)) / (exp(x) + exp(-x)).
 *
 * @param x Входное значение.
 * @return Значение гиперболического тангенса.
 */
double hyperbolictanh(double x);

/**
 * @brief Арктангенс.
 *
 * Эта функция возвращает арктангенс входного значения.
 *
 * @param x Входное значение.
 * @return Арктангенс x.
 */
double archtanh(double x);

/**
 * @brief Softsign функция активации.
 *
 * Эта функция возвращает x / (1 + |x|).
 *
 * @param x Входное значение.
 * @return Значение Softsign.
 */
double Softsign(double x);

/**
 * @brief ISRU функция активации.
 *
 * Эта функция возвращает значение по формуле, зависящей от x.
 *
 * @param x Входное значение.
 * @return Значение ISRU.
 */
double ISRU(double x);

/**
 * @brief ReLU (Rectified Linear Unit) функция активации.
 *
 * Эта функция возвращает max(0, x).
 *
 * @param x Входное значение.
 * @return Значение ReLU.
 */
double ReLU(double x);

/**
 * @brief LReLU (Leaky ReLU) функция активации.
 *
 * Эта функция возвращает x, если x > 0, иначе возвращает 0.01 * x.
 *
 * @param x Входное значение.
 * @return Значение LReLU.
 */
double LReLU(double x);

/**
 * @brief PReLU (Parametric ReLU) функция активации.
 *
 * Эта функция возвращает x, если x > 0, иначе возвращает a * x, где a - параметр.
 *
 * @param x Входное значение.
 * @return Значение PReLU.
 */
double PReLU(double x);

/**
 * @brief RReLU (Randomized ReLU) функция активации.
 *
 * Эта функция возвращает x, если x > 0, иначе возвращает случайное значение в диапазоне (0, a).
 *
 * @param x Входное значение.
 * @return Значение RReLU.
 */
double RReLU(double x);

/**
 * @brief ELU (Exponential Linear Unit) функция активации.
 *
 * Эта функция возвращает x, если x > 0, иначе возвращает a * (exp(x) - 1).
 *
 * @param x Входное значение.
 * @return Значение ELU.
 */
double ELU(double x);

/**
 * @brief SELU (Scaled Exponential Linear Unit) функция активации.
 *
 * Эта функция возвращает λ * x, если x > 0, иначе возвращает λ * a * (exp(x) - 1).
 *
 * @param x Входное значение.
 * @return Значение SELU.
 */
double SELU(double x);

/**
 * @brief SReLU (Soft ReLU) функция активации.
 *
 * Эта функция возвращает значение по формуле, зависящей от x.
 *
 * @param x Входное значение.
 * @return Значение SReLU.
 */
double SReLU(double x);

/**
 * @brief ISRLU (Inverse Soft Rectified Linear Unit) функция активации.
 *
 * Эта функция возвращает значение по формуле, зависящей от x.
 *
 * @param x Входное значение.
 * @return Значение ISRLU.
 */
double ISRLU(double x);

/**
 * @brief APL (Adaptive Piecewise Linear) функция активации.
 *
 * Эта функция возвращает значение по формуле, зависящей от x.
 *
 * @param x Входное значение.
 * @return Значение APL.
 */
double APL(double x);

/**
 * @brief SoftPlus функция активации.
 *
 * Эта функция возвращает ln(1 + exp(x)).
 *
 * @param x Входное значение.
 * @return Значение SoftPlus.
 */
double SoftPlus(double x);

/**
 * @brief Bent Identity функция активации.
 *
 * Эта функция возвращает (x + (x^2 + 1)^(1/2)) / 2.
 *
 * @param x Входное значение.
 * @return Значение Bent Identity.
 */
double BentIdentity(double x);

//---производные функций активации
/**
 * @brief Производная тождественной функции активации.
 *
 * @param x Входное значение.
 * @return 1.
 */
double identify_derivative(double x);

/**
 * @brief Производная единичной ступенчатой функции активации.
 *
 * @param x Входное значение.
 * @return 0 для всех x, кроме 0.
 */
double Heaviside_derivative(double x);

/**
 * @brief Производная логистической сигмоидной функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной сигмоиды.
 */
double sigmoid_derivative(double x);

/**
 * @brief Производная гиперболического тангенса.
 *
 * @param x Входное значение.
 * @return Значение производной гиперболического тангенса.
 */
double hyperbolictanh_derivative(double x);

/**
 * @brief Производная арктангенса.
 *
 * @param x Входное значение.
 * @return Значение производной арктангенса.
 */
double archtanh_derivative(double x);

/**
 * @brief Производная Softsign функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной Softsign.
 */
double Softsign_derivative(double x);

/**
 * @brief Производная ISRU функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной ISRU.
 */
double ISRU_derivative(double x);

/**
 * @brief Производная ReLU функции активации.
 *
 * @param x Входное значение.
 * @return 1, если x > 0, иначе 0.
 */
double ReLU_derivative(double x);

/**
 * @brief Производная LReLU функции активации.
 *
 * @param x Входное значение.
 * @return 1, если x > 0, иначе 0.01.
 */
double LReLU_derivative(double x);

/**
 * @brief Производная PReLU функции активации.
 *
 * @param x Входное значение.
 * @return 1, если x > 0, иначе a.
 */
double PReLU_derivative(double x);

/**
 * @brief Производная RReLU функции активации.
 *
 * @param x Входное значение.
 * @return 1, если x > 0, иначе случайное значение в диапазоне (0, a).
 */
double RReLU_derivative(double x);

/**
 * @brief Производная ELU функции активации.
 *
 * @param x Входное значение.
 * @return 1, если x > 0, иначе a * exp(x).
 */
double ELU_derivative(double x);

/**
 * @brief Производная SELU функции активации.
 *
 * @param x Входное значение.
 * @return λ, если x > 0, иначе λ * a * exp(x).
 */
double SELU_derivative(double x);

/**
 * @brief Производная SReLU функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной SReLU.
 */
double SReLU_derivative(double x);

/**
 * @brief Производная ISRLU функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной ISRLU.
 */
double ISRLU_derivative(double x);

/**
 * @brief Производная APL функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной APL.
 */
double APL_derivative(double x);

/**
 * @brief Производная SoftPlus функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной SoftPlus.
 */
double SoftPlus_derivative(double x);

/**
 * @brief Производная Bent Identity функции активации.
 *
 * @param x Входное значение.
 * @return Значение производной Bent Identity.
 */
double BentIdentity_derivative(double x);


#endif /* iaApplic_hpp */
