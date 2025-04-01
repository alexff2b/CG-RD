
/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaComplex.cpp
 *    @brief      : Заголовочнвй файл класса iaComplex (Комплексные числа).
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

#ifndef IA_COMPLEX_HPP
#define IA_COMPLEX_HPP

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
