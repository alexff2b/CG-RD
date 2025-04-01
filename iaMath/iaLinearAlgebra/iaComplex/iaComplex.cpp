/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaComplex.cpp
 *    @brief      : Реализация класса iaComplex (Комплексные числа).
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.0.0 (первая завершенная версия, протестирована, используется в разработке других классов)
 *    @license    : Apache License 2.0
 *    @contact    : 
 *                  Email:  
 *                      - alexff.2b@hotmail.com  
 *                      - alexff.2b@gmail.com  
 *                      - alexff.2b@icloud.com  
 *                      - alexff.2b@yandex.ru  
 *                  Телефон:  
 *                      - Франция: +33 6 58 04 64 56  
 *                      - Россия:  +7 985 975 1326  
 *
 *    @created    : Октябрь 2021
 *    @modified   : Март 2025
 *    @released   : 5 марта 2025 (первая версия, завершенная, используется в разработке других классов)
 *    
 *    @previous_version: Нет
 *
 *    @note       : Реализованы базовые операции работы с комплексными числами:
 *                  - Арифметические операции: сложение, вычитание, умножение, деление.
 *                  - Вычисление модуля, аргумента, конъюгирование.
 *                  - Операторы сравнения.
 *                  - Оператор потокового вывода.
 *                  - В дальнейшем планируется расширение функциональности.
 *
 *    @description: 
 *                  Этот файл содержит реализацию методов класса `iaComplex`, который предназначен
 *                  для работы с комплексными числами.  
 *                  
 *                  Основные возможности класса:  
 *                    - Создание комплексных чисел  
 *                    - Доступ к реальной и мнимой частям  
 *                    - Арифметические операции  
 *                    - Вычисление математических характеристик числа  
 *                    - Сравнение комплексных чисел  
 *                    - Вывод в поток  
 *
 *    @applications:
 *                  Класс `iaComplex` применяется в различных областях науки и техники, таких как:
 *                  - **Физика**: моделирование электромагнитных волн, квантовая механика.
 *                  - **Электротехника**: расчет электрических цепей переменного тока.
 *                  - **Цифровая обработка сигналов**: фильтрация, анализ частотных характеристик.
 *                  - **Компьютерная графика**: работа с фракталами (например, множества Мандельброта и Жюлиа).
 *                  - **Контроль и автоматизация**: разработка алгоритмов управления в сложных системах.
 *                  - **Математическое моделирование**: симуляции динамических систем, численные методы.
 *
 *    @methods    :
 *                   - iaComplex();                         // Конструктор по умолчанию (0 + 0i)
 *                   - iaComplex(double real, double imag); // Конструктор с параметрами
 *                   - iaComplex(const iaComplex& other);   // Конструктор копирования
 *                   - iaComplex& operator=(const iaComplex& other); // Оператор присваивания
 *                   - ~iaComplex();                        // Деструктор
 *                   
 *                   - double getReal() const; // Получить действительную часть
 *                   - double getImag() const; // Получить мнимую часть
 *                   - void setReal(double r); // Установить действительную часть
 *                   - void setImag(double i); // Установить мнимую часть
 *
 *                   - iaComplex conjugate() const; // Сопряженное число
 *                   - double magnitude() const;    // Модуль числа
 *                   - double argument() const;     // Аргумент числа (радианы)
 *
 *                   - iaComplex operator+(const iaComplex& other) const; // Сложение
 *                   - iaComplex operator-(const iaComplex& other) const; // Вычитание
 *                   - iaComplex operator*(const iaComplex& other) const; // Умножение
 *                   - iaComplex operator/(const iaComplex& other) const; // Деление
 *
 *                   - bool operator==(const iaComplex& other) const; // Сравнение на равенство
 *                   - bool operator!=(const iaComplex& other) const; // Сравнение на неравенство
 *
 *                   - friend std::ostream& operator<<(std::ostream& os, const iaComplex& complex);  
 *                     // Оператор вывода в поток
 *
 *    @license    :
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Полный текст лицензии находится в файле LICENSE в корне проекта.
 *                  Официальный текст лицензии доступен по адресу:  
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 *    @project_website: [Добавить ссылку на сайт проекта, когда он появится]
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
