/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaComplex.hpp
 *    @brief      : Заголовочный файл для класса iaComplex (Комплексные числа).
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
 *    @note       : Изменения с предыдущей версии:
 *                  - Первая версия класса `iaComplex`, предназначенная для работы с комплексными числами.
 *                  - Включены базовые арифметические операции (сложение, вычитание, умножение, деление).
 *                  - Поддержка вычисления модуля, аргумента, конъюгирования.
 *                  - В дальнейшем планируется добавление новых методов (возведение в степень, работа с разными типами).
 *
 *    @description: Класс `iaComplex` реализует работу с комплексными числами, 
 *                  поддерживает основные арифметические операции и дополнительные вычисления.
 *                  Используется в научных, инженерных, математических приложениях.
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

#ifndef IA_COMPLEX_H
#define IA_COMPLEX_H

#include <iostream>

/**
 * @class iaComplex
 * @brief Класс для работы с комплексными числами.
 */
class iaComplex {
public:
    /** 
     * @brief Конструктор по умолчанию (инициализирует 0 + 0i).
     */
    iaComplex();

    /** 
     * @brief Конструктор с параметрами.
     * @param r Реальная часть.
     * @param i Мнимая часть.
     */
    iaComplex(double r, double i);

    /** 
     * @brief Конструктор копирования.
     * @param otherComplex Другой комплексный объект.
     */
    iaComplex(const iaComplex& otherComplex);

    /** 
     * @brief Деструктор (по умолчанию, так как динамическая память не используется).
     */
    ~iaComplex() = default;

    /** 
     * @brief Получить реальную часть.
     * @return Реальная часть.
     */
    double getReal() const;

    /** 
     * @brief Получить мнимую часть.
     * @return Мнимая часть.
     */
    double getImag() const;

    /** 
     * @brief Установить реальную часть.
     * @param r Новое значение реальной части.
     */
    void setReal(double r);

    /** 
     * @brief Установить мнимую часть.
     * @param i Новое значение мнимой части.
     */
    void setImag(double i);

    /** 
     * @brief Оператор присваивания.
     */
    iaComplex& operator=(const iaComplex &otherComplex);

    /** Операторы арифметических операций */
    iaComplex operator+(const iaComplex &otherComplex) const;
    iaComplex operator-(const iaComplex &otherComplex) const;
    iaComplex operator*(const iaComplex &otherComplex) const;
    iaComplex operator/(const iaComplex &otherComplex) const;

    /** Операторы сравнения */
    bool operator==(const iaComplex &otherComplex) const;
    bool operator!=(const iaComplex &otherComplex) const;

    /** 
     * @brief Получить модуль комплексного числа.
     */
    double magnitude() const;

    /** 
     * @brief Получить аргумент комплексного числа.
     */
    double argument() const;

    /** 
     * @brief Получить сопряженное комплексное число.
     */
    iaComplex conjugate() const;

    /** 
     * @brief Оператор вывода в поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const iaComplex& complex);

private:
    double real; ///< Реальная часть.
    double imag; ///< Мнимая часть.
};

#endif // IA_COMPLEX_H
