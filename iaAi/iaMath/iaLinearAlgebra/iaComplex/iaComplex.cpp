/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaComplex.cpp
 *    @brief      : Реализация класса iaComplex (Комплексные числа).
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.0.0-alpha (первая версия, завершенная, полевое тестирование, будут добавляться методы)
 *    @license    : Apache License 2.0
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr. +33 6 58 04 64 56
 *                  Rus. +7 985 975 1326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Февраль 2025
 *    @released   : 26 февраля 2025 (первая версия, активное полевое тестирование)
 *    
 *    @previous_version: Нет
 *
 *    @note       : Реализованы базовые операции работы с комплексными числами:
 *                  - Сложение, вычитание, умножение, деление.
 *                  - Вычисление модуля, аргумента, конъюгирование.
 *                  - Операторы сравнения.
 *                  - В дальнейшем планируется расширение функциональности.
 *
 *    @description: Этот файл содержит реализацию методов класса `iaComplex`.
 *                  Класс позволяет выполнять основные арифметические операции с комплексными числами,
 *                  а также проводить дополнительные вычисления.
 *
 *    @methods     :
 *                   - iaComplex(); // Конструктор по умолчанию
 *                   - iaComplex(double real, double imag); // Конструктор с параметрами
 *                   - iaComplex(const iaComplex& other); // Конструктор копирования
 *                   - iaComplex& operator=(const iaComplex& other); // Оператор присваивания
 *                   - ~iaComplex(); // Деструктор
 *                   - double real() const; // Действительная часть
 *                   - double imag() const; // Мнимая часть
 *                   - iaComplex conjugate() const; // Конъюгирование
 *                   - double magnitude() const; // Модуль числа
 *                   - double argument() const; // Аргумент числа
 *                   - iaComplex operator+(const iaComplex& other) const; // Сложение
 *                   - iaComplex operator-(const iaComplex& other) const; // Вычитание
 *                   - iaComplex operator*(const iaComplex& other) const; // Умножение
 *                   - iaComplex operator/(const iaComplex& other) const; // Деление
 *                   - bool operator==(const iaComplex& other) const; // Сравнение на равенство
 *                   - bool operator!=(const iaComplex& other) const; // Сравнение на неравенство
 *
 *    @license     :
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Вы можете свободно использовать, изменять и распространять этот код при соблюдении
 *                  условий лицензии. Полный текст лицензии доступен по адресу:
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 * **************************************************************************************************
 */
#include "iaComplex.hpp"
#include <cmath>
#include <stdexcept>

/** Конструктор по умолчанию */
iaComplex::iaComplex() : real(0.0), imag(0.0) {}

/** Конструктор с параметрами */
iaComplex::iaComplex(double r, double i) : real(r), imag(i) {}

/** Конструктор копирования */
iaComplex::iaComplex(const iaComplex& otherComplex) 
    : real(otherComplex.real), imag(otherComplex.imag) {}

/** Получить реальную часть */
double iaComplex::getReal() const {
    return real;
}

/** Получить мнимую часть */
double iaComplex::getImag() const {
    return imag;
}

/** Установить реальную часть */
void iaComplex::setReal(double r) {
    real = r;
}

/** Установить мнимую часть */
void iaComplex::setImag(double i) {
    imag = i;
}

/** Оператор присваивания */
iaComplex& iaComplex::operator=(const iaComplex &otherComplex) {
    if (this != &otherComplex) { // Проверка на самоприсваивание
        real = otherComplex.real;
        imag = otherComplex.imag;
    }
    return *this;
}

/** Оператор сложения */
iaComplex iaComplex::operator+(const iaComplex &otherComplex) const {
    return {real + otherComplex.real, imag + otherComplex.imag};
}

/** Оператор вычитания */
iaComplex iaComplex::operator-(const iaComplex &otherComplex) const {
    return {real - otherComplex.real, imag - otherComplex.imag};
}

/** Оператор умножения */
iaComplex iaComplex::operator*(const iaComplex &otherComplex) const {
    return {real * otherComplex.real - imag * otherComplex.imag, 
            real * otherComplex.imag + imag * otherComplex.real};
}

/** Оператор деления */
iaComplex iaComplex::operator/(const iaComplex &otherComplex) const {
    double denominator = otherComplex.real * otherComplex.real + otherComplex.imag * otherComplex.imag;
    const double epsilon = 1e-9; // Защита от деления на 0

    if (std::fabs(denominator) < epsilon) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    return {(real * otherComplex.real + imag * otherComplex.imag) / denominator,
            (imag * otherComplex.real - real * otherComplex.imag) / denominator};
}

/** Оператор равенства */
bool iaComplex::operator==(const iaComplex &otherComplex) const {
    const double epsilon = 1e-9;
    return (std::fabs(real - otherComplex.real) < epsilon &&
            std::fabs(imag - otherComplex.imag) < epsilon);
}

/** Оператор неравенства */
bool iaComplex::operator!=(const iaComplex &otherComplex) const {
    return !(*this == otherComplex);
}

/** Получить модуль комплексного числа */
double iaComplex::magnitude() const {
    return std::sqrt(real * real + imag * imag);
}

/** Получить аргумент комплексного числа */
double iaComplex::argument() const {
    return std::atan2(imag, real);
}

/** Получить сопряженное комплексное число */
iaComplex iaComplex::conjugate() const {
    return {real, -imag};
}

/** Оператор вывода в поток */
std::ostream& operator<<(std::ostream& os, const iaComplex& complex) {
    os << complex.real;
    if (complex.imag >= 0) os << "+";
    os << complex.imag << "i";
    return os;
}
