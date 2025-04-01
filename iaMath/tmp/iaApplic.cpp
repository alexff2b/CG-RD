//
//  iaApplic.cpp
//  Classes_DevTest
//
//  Created by alexff on 28/01/2025.
//

#include "iaApplic.hpp"

//функции преобразовния

//double radtodeg(double rad){
//    return rad * 180 / M_PI;/
//}

//double degtorad(double deg) {
    
 //   return deg * M_PI / 180;
//}





// Функции
/**
 * @brief Вычисляет факториал числа рекурсивным методом.
 *
 * Функция принимает неотрицательное целое число и возвращает его факториал.
 * Факториал числа n (обозначается n!) равен произведению всех положительных
 * целых чисел от 1 до n. Факториал 0 определен как 1.
 *
 * @param num Неотрицательное целое число, для которого вычисляется факториал.
 * @return Факториал числа num.
 */
int fact(int num) {
    if (num == 0) {
        return 1; // Факториал 0 равен 1
    } else {
        return num * fact(num - 1); // Рекурсивный вызов для вычисления факториала
    }
}

/**
 * @brief Вычисляет n-е число Фибоначчи рекурсивным методом.
 *
 * Функция принимает неотрицательное целое число и возвращает n-е число
 * Фибоначчи. Числа Фибоначчи определяются рекурсивно: F(0) = 0, F(1) = 1,
 * F(n) = F(n-1) + F(n-2) для n > 1.
 *
 * @param num Неотрицательное целое число, для которого вычисляется n-е число Фибоначчи.
 * @return n-е число Фибоначчи.
 */
int fibo(int num) {
    if (num == 0) return 0; // Базовый случай: F(0) = 0
    else if (num == 1) return 1; // Базовый случай: F(1) = 1
    else
        return fibo(num - 1) + fibo(num - 2); // Рекурсивный вызов для вычисления n-го числа Фибоначчи
}
/**
 * @brief Тождественная функция активации.
 *
 * Эта функция возвращает входное значение без изменений.
 *
 * @param x Входное значение.
 * @return Возвращает x.
 */
double identify(double x) {
    return x;
}

/**
 * @brief Единичная ступенчатая функция активации (Heaviside).
 *
 * Эта функция возвращает 0, если x < 0, и 1, если x >= 0.
 *
 * @param x Входное значение.
 * @return 0.0 или 1.0 в зависимости от значения x.
 */
double Heaviside(double x) {
    if (x < 0) return 0.0;
    else return 1.0;
}

/**
 * @brief Логистическая сигмоидная функция активации.
 *
 * Эта функция возвращает значение в диапазоне (0, 1) по формуле:
 * 1 / (1 + exp(-x)).
 *
 * @param x Входное значение.
 * @return Значение сигмоиды.
 */
double sigmoid(double x) {
    return 1.0 /(1.0 + exp(-x));
}


// Производные
/**
 * @brief Производная тождественной функции.
 *
 * Производная тождественной функции равна 1.
 *
 * @param x Входное значение.
 * @return 1.0.
 */
double identify_derivative(double x) {
    return 1.0;
}

/**
 * @brief Производная единичной ступенчатой функции (Heaviside).
 *
 * Производная функции Heaviside не определена в точке x = 0,
 * но равна 0 в остальных точках.
 *
 * @param x Входное значение.
 * @return 0.0.
 */
double Heaviside_derivative(double x) {
    return 0.0; // Неопределена в x = 0
}

/**
 * @brief Производная логистической сигмоидной функции.
 *
 * Производная сигмоиды вычисляется по формуле:
 * sigmoid(x) * (1 - sigmoid(x)).
 *
 * @param x Входное значение.
 * @return Производная сигмоиды.
 */
double sigmoid_derivative(double x) {
    double sig = sigmoid(x);
    return sig * (1.0 - sig);
}

/*
double hyprbolictanh(double x) {
    
    return tanh(x);
    //return (exp(x) - exp(-x))/(exp(x) + exp(-x));
}

double archtanh(double x) {
    return atan(x);
    
}

double Softsign(double x) {
    return 1 / (1 + abs(x));
}

double ISRU(double x) {
    return x / sqrt(x);
}

double ReLU(double x) {
    if (x < 0) return 0.0;
    else return x;
}
double LReLU(double x) {
    if (x < 0) return 0.01 * x;
    else return x;
}

double PReLU(double x){
    return 0;
}

double RReLU(double x) {
    return 0;
}

double ELU(double x) {
    return 0;
}

double SELU(double x) {
    return 0;
}

double SReLU(double x) {
    return 0;
}

double ISRLU(double x) {
    return 0;
}

double APL(double x) {
    //???
    return 0;
}

double SoftPlus(double x) {
    return log(1 + exp(x));
}

double BentIdentity(double x) {
    return (sqrt(x * x + 1) - 1) / 2 + x;
}
 */
/*
int operator||(int num) {
    
    if (num < 0) return num * -1;
    else return num;
}

double operator ||(double num) {
    if (num < 0) return num * -1;
    else return num;
}
*/


/*

int fact(int num) {
    if (num == 0) { return 1; }
    else { return num * fact(num - 1); }
}

int fibo(int num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    else
        return fibo(num - 1) + fibo(num - 2);
}

*/
