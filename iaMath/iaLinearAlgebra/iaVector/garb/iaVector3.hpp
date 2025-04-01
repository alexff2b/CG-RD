/*
 ****************************************************************************************************
 *
 *    Компания    : iA
 *    @file       : iaVector.hpp
 *    @brief      : Заголовочный файл для класса iaVector.
 *    @author     : Александра Юшкевича
 *    @aka        : iA, alexff
 *    @project    : Все проекты iA. IA Projects
 *    @version    : 0.3.0 (Stable version - fully tested and optimized)
 *    @license    : MIT License
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
 *                  - Добавлен метод инверсии вектора.
 *                  - Исправлены ошибки и улучшена документация для ясности и полноты.
 *
 *    @description: Этот класс представляет вектор, который может использоваться для
 *                   выполнения различных математических операций. Он поддерживает
 *                   операции с векторами, такие как сложение, вычитание, скалярное произведение,
 *                   умножение на скаляр и инверсия вектора. Класс также включает методы для
 *                   работы с элементами вектора, инициализации и вывода.
 *
 *    @methods     :
 *                   - iaVector(); // Конструктор по умолчанию
 *                   - iaVector(int m); // Конструктор с размером
 *                   - iaVector(int m, const double values[]); // Конструктор со значениями
 *                   - iaVector(const iaVector& otherVector); // Конструктор копирования
 *                   - iaVector& operator=(const iaVector& otherVector) noexcept; // Оператор присваивания
 *                   - ~iaVector(); // Деструктор
 *                   - int sizeOfVector() const; // Возвращает размер вектора
 *                   - void printVector() const; // Печатает вектор
 *                   - double& operator[](int j); // Оператор доступа
 *                   - double* operator&(int j); // Оператор адреса
 *                   - iaVector operator+(const iaVector& otherVector) const; // Сложение
 *                   - iaVector operator-(const iaVector& otherVector) const; // Вычитание
 *                   - iaVector operator*(double scalar) const; // Умножение на скаляр
 *                   - double dotProduct(const iaVector& otherVector) const; // Скалярное произведение
 *                   - double L2norm() const; // Вычисление L2 нормы
 *                   - double sum() const; // Вычисление суммы элементов
 *                   - double maxElement() const; // Вычисление максимального элемента
 *                   - double minElement() const; // Вычисление минимального элемента
 *                   - double angleBetween(const iaVector& otherVector) const noexcept; // Вычисление угла между векторами
 *                   - void inverting() noexcept; // Инверсия вектора
 *
 *    @properties  :
 *                   - int m;            ///< Размер вектора
 *                   - double* value;    ///< Значения вектора
 *
 *    @copyright    : Этот файл является частью проектов iA. Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 * **************************************************************************************************
 */

#ifndef iaVector_hpp
#define iaVector_hpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

class iaVector {
public:
    iaVector(); // Инициализация размера и указателя на массив

    iaVector(int m);

    iaVector(int m, const double values[]);

    iaVector(const iaVector& otherVector);

    ~iaVector();

    iaVector& operator=(const iaVector& otherVector) noexcept;

    iaVector operator+(const iaVector& otherVector) noexcept;

    iaVector operator-(const iaVector& otherVector) noexcept;

    iaVector operator*(const iaVector& otherVector) noexcept;

    iaVector operator*(double scal);

    void inverting() noexcept;

    int sizeOfVector() const;

    void printVector() const;

    double sum() const;

    double L2norm() const;

    double L1norm() const;

    double LMnorm() const;

    double dotProduct(const iaVector& otherVector) const;

    double angleBetween(const iaVector& otherVector) const noexcept;

    void sortAscending();
    void sortDescending();
    double maxElement() const;
    double minElement() const;
    double avverage() const;

    double& operator[](int j);

    bool operator==(const iaVector& otherVector) const noexcept;

    bool operator!=(const iaVector& otherVector) const noexcept;

    iaVector operator||(const iaVector& otherVector) const noexcept;

    double* value; 

private:
    int m; 
};

#endif /* iaVector_hpp */