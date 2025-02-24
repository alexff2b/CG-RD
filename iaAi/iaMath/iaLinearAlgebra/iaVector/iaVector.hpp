/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaVector.hpp
 *    @brief      : Заголовочный файл для шаблонного класса iaVector.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 3.0.1-alpha (дорабатывается, тестируется)
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
 *
 *    @previous_version: 2.0.0 (законченная, прошедшая тестирование, удалена)
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Класс стал шаблонным (`iaVector<T>`).
 *                  - Добавлена поддержка работы с разными типами (`int`, `double`, `float` и др.).
 *                  - Оптимизированы операции сложения, вычитания и умножения.
 *                  - Реализована поддержка итераторов.
 *                  - Добавлены методы `begin()`, `end()` для совместимости с `std::vector`.
 *                  - Улучшена документация и стиль кода.
 *
 *    @description: Этот заголовочный файл определяет шаблонный класс `iaVector<T>`, представляющий
 *                  математический вектор с возможностью выполнения различных операций.
 *                  Поддерживает базовые арифметические операции, работу с итераторами,
 *                  а также вычисление математических характеристик.
 *
 *    @methods     :
 *                   - iaVector(); // Конструктор по умолчанию
 *                   - iaVector(int m); // Конструктор с размером
 *                   - iaVector(int m, const T values[]); // Конструктор со значениями
 *                   - iaVector(const iaVector<T>& otherVector); // Конструктор копирования
 *                   - iaVector& operator=(const iaVector<T>& otherVector) noexcept; // Оператор присваивания
 *                   - ~iaVector(); // Деструктор
 *                   - int size() const; // Возвращает размер вектора
 *                   - void print() const; // Печатает вектор
 *                   - T& operator[](int j); // Оператор доступа
 *                   - iaVector operator+(const iaVector<T>& otherVector) const; // Сложение
 *                   - iaVector operator-(const iaVector<T>& otherVector) const; // Вычитание
 *                   - iaVector operator*(T scalar) const; // Умножение на скаляр
 *                   - T dotProduct(const iaVector<T>& otherVector) const; // Скалярное произведение
 *                   - T L2norm() const; // Вычисление L2 нормы
 *                   - T sum() const; // Вычисление суммы элементов
 *                   - T maxElement() const; // Максимальный элемент
 *                   - T minElement() const; // Минимальный элемент
 *                   - double angleBetween(const iaVector<T>& otherVector) const noexcept; // Угол между векторами
 *                   - void inverting() noexcept; // Инверсия вектора
 *                   - T* begin(); // Итератор на начало
 *                   - T* end(); // Итератор на конец
 *
 *    @properties  :
 *                   - int m;        ///< Размер вектора
 *                   - T* values;    ///< Значения вектора
 *
 *    @license     :
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Вы можете свободно использовать, изменять и распространять этот код при соблюдении
 *                  условий лицензии. Полный текст лицензии доступен по адресу:
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 * **************************************************************************************************
 */
#ifndef IAVECTOR_HPP
#define IAVECTOR_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

/**
 * @brief Шаблонный класс математического вектора.
 * @tparam T Тип данных (int, float, double, iaVector и др.).
 */
template <typename T>
class iaVector {
private:
    std::vector<T> data; ///< Данные вектора.

public:
    /** @brief Конструктор по умолчанию */
    iaVector() = default;

    /** @brief Конструктор с размером */
    explicit iaVector(size_t n) : data(n, T()) {}

    /** @brief Конструктор с массивом */
    iaVector(std::initializer_list<T> list) : data(list) {}

    /** @brief Конструктор копирования */
    iaVector(const iaVector<T>& other) = default;

    /** @brief Оператор присваивания */
    iaVector<T>& operator=(const iaVector<T>& other) = default;

    /** @brief Конструктор перемещения */
    iaVector(iaVector<T>&& other) noexcept = default;

    /** @brief Оператор перемещения */
    iaVector<T>& operator=(iaVector<T>&& other) noexcept = default;

    /** @brief Деструктор */
    ~iaVector() = default;

    /** @brief Размер вектора */
    size_t size() const { return data.size(); }

    /** @brief Доступ к элементу */
    T& operator[](size_t index) { return data.at(index); }

    /** @brief Доступ к элементу (константный) */
    const T& operator[](size_t index) const { return data.at(index); }

    /** @brief Добавить элемент в конец */
    void push_back(const T& value) { data.push_back(value); }

    /** @brief Удалить последний элемент */
    void pop_back() { if (!data.empty()) data.pop_back(); }

    /** @brief Очистить вектор */
    void clear() { data.clear(); }

    /** @brief Сложение векторов */
    iaVector<T> operator+(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result[i] = data[i] + other[i];
        return result;
    }

    /** @brief Вычитание векторов */
    iaVector<T> operator-(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result[i] = data[i] - other[i];
        return result;
    }

    /** @brief Умножение на скаляр */
    iaVector<T> operator*(T scalar) const {
        iaVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result[i] = data[i] * scalar;
        return result;
    }

    /** @brief Скалярное произведение */
    T dotProduct(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        T sum = 0;
        for (size_t i = 0; i < size(); ++i) sum += data[i] * other[i];
        return sum;
    }

    /** @brief Норма L2 */
    T L2norm() const {
        T sum = 0;
        for (const T& val : data) sum += val * val;
        return std::sqrt(sum);
    }

    /** @brief Норма L1 */
    T L1norm() const {
        T sum = 0;
        for (const T& val : data) sum += std::abs(val);
        return sum;
    }

    /** @brief Угол между векторами (в радианах) */
    double angleBetween(const iaVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Размеры не совпадают");
        double dot = static_cast<double>(dotProduct(other));
        double norms = static_cast<double>(L2norm() * other.L2norm());
        return norms == 0 ? 0 : std::acos(dot / norms);
    }

    /** @brief Поиск максимального элемента */
    T maxElement() const {
        if (data.empty()) throw std::runtime_error("Вектор пуст");
        return *std::max_element(data.begin(), data.end());
    }

    /** @brief Поиск минимального элемента */
    T minElement() const {
        if (data.empty()) throw std::runtime_error("Вектор пуст");
        return *std::min_element(data.begin(), data.end());
    }

    /** @brief Проверка, является ли вектор палиндромом */
    bool isPalindrome() const {
        for (size_t i = 0, j = size() - 1; i < j; ++i, --j)
            if (data[i] != data[j]) return false;
        return true;
    }

    /** @brief Вывод вектора в поток */
    friend std::ostream& operator<<(std::ostream& os, const iaVector<T>& vec) {
        os << "[ ";
        for (const T& val : vec.data) os << val << " ";
        os << "]";
        return os;
    }
};

#endif // IAVECTOR_HPP
