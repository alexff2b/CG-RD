/*
 ****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaVector.hpp
 *    @brief      : Заголовочный файл для шаблонного класса iaVector.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 3.0.1-alpha (доробатывается, тестируется)
 *    @license    : MIT License
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr.+33658046456
 *                  rus. +79859751326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Февраль 2025
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
 *    @copyright    : Этот файл является частью проектов CG Research & Development(c). Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 *
 * **************************************************************************************************
 */
/*
 ****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaVector.h
 *    @brief      : Заголовочный файл для класса iaVector.
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & developement(c) Projects
 *    @version    : 1.0.0-alpha (Законченная версия, тестируется)
 *    @license    : MIT License
 *    @contact    : / alexff.2b@hotmail.com /
 *                   / alexff.2b@gmail.com   /
 *                   / alexff.2b@icloud.com  /
 *                   / alexff.2b@yandex.ru   /
 *    @tel        : Fr.+33658046456
 *                  rus. +79859751326
 *
 *    @created    : Октябрь 2021
 *    @modified   : Февраль 2025
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Добавлен метод инверсии вектора.
 *                  - Исправлены ошибки и улучшена документация для ясности и полноты.
 *
 *    @description: Этот заголовочный файл определяет класс iaVector, который представляет
 *                   вектор и предоставляет различные методы для выполнения математических операций.
 *                   Операции включают сложение, вычитание, скалярное произведение, умножение на скаляр,
 *                   инверсию вектора и другие. Класс также содержит методы для работы с элементами вектора,
 *                   а также для вычисления различных характеристик, таких как L2-норма, сумма элементов,
 *                   максимальный и минимальный элементы, угол между векторами.
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
 *    @copyright    : Этот файл является частью проектов CG Research & developement(c). Он лицензирован под MIT License.
 *                   Вы можете использовать, изменять и распространять этот код, при условии,
 *                   что Вы предоставите соответствующее упоминание об авторе.
 *
 * **************************************************************************************************
 */
#ifndef IAVECTOR_HPP
#define IAVECTOR_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * @brief Шаблонный класс для работы с векторами.
 * @tparam T Тип данных элементов вектора.
 */
template <typename T>
class iaVector {
private:
    T* data;     ///< Указатель на массив элементов вектора.
    size_t size; ///< Количество элементов в векторе.

public:
    /** @brief Конструктор по умолчанию */
    iaVector() : data(nullptr), size(0) {}

    /**
     * @brief Конструктор с указанием размера.
     * @param n Размер вектора.
     */
    iaVector(size_t n) : size(n) {
        data = new T[n]();
    }

    /**
     * @brief Конструктор копирования.
     * @param other Другой вектор для копирования.
     */
    iaVector(const iaVector& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    /**
     * @brief Оператор присваивания.
     * @param other Другой вектор для копирования.
     * @return Ссылка на текущий объект.
     */
    iaVector& operator=(const iaVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    /** @brief Деструктор */
    ~iaVector() {
        delete[] data;
    }

    /**
     * @brief Получить размер вектора.
     * @return Размер вектора.
     */
    size_t getSize() const {
        return size;
    }

    /**
     * @brief Добавить элемент в конец вектора.
     * @param value Значение элемента.
     */
    void push_back(T value) {
        T* newData = new T[size + 1];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        ++size;
    }

    /**
     * @brief Удалить последний элемент вектора.
     */
    void pop_back() {
        if (size == 0) throw std::out_of_range("Вектор пуст");
        T* newData = new T[size - 1];
        for (size_t i = 0; i < size - 1; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        --size;
    }

    /**
     * @brief Доступ к элементу по индексу.
     * @param index Индекс элемента.
     * @return Ссылка на элемент.
     */
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Индекс вне диапазона");
        return data[index];
    }

    /**
     * @brief Получение элемента по индексу (константная версия).
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент.
     */
    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Индекс вне диапазона");
        return data[index];
    }

    /**
     * @brief Очистка вектора.
     */
    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    /**
     * @brief Поэлементное сложение векторов.
     * @param other Второй вектор.
     * @return Новый вектор с результатом сложения.
     */
    iaVector operator+(const iaVector& other) const {
        if (size != other.size) throw std::invalid_argument("Размеры векторов не совпадают");
        iaVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    /**
     * @brief Поэлементное вычитание векторов.
     * @param other Второй вектор.
     * @return Новый вектор с результатом вычитания.
     */
    iaVector operator-(const iaVector& other) const {
        if (size != other.size) throw std::invalid_argument("Размеры векторов не совпадают");
        iaVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    /**
     * @brief Поэлементное умножение на скаляр.
     * @param scalar Число, на которое умножается вектор.
     * @return Новый вектор с результатом умножения.
     */
    iaVector operator*(T scalar) const {
        iaVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    T sum() const {
    T s = 0;
    for (size_t i = 0; i < size; i++) {
        s += data[i];
    }
    return s;
}

T average() const {
    return size > 0 ? sum() / size : 0;
}

T maxElement() const {
    if (size == 0 || data == nullptr) {
        throw std::runtime_error("Ошибка: попытка найти максимум в пустом векторе!");
    }

    T maxVal = data[0];
    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}


T minElement() const {
    if (size == 0 || data == nullptr) {
        throw std::runtime_error("Ошибка: попытка найти минимум в пустом векторе!");
    }
    T minVal = data[0];
    for (size_t i = 1; i < size; i++) {
        if (data[i] < minVal) minVal = data[i];
    }
    return minVal;
}

    /**
     * @brief L1-норма вектора.
     * @return Значение L1-нормы.
     */
    T L1norm() const {
        T norm = 0;
        for (size_t i = 0; i < size; ++i) {
            norm += std::abs(data[i]);
        }
        return norm;
    }

    /**
     * @brief L2-норма вектора.
     * @return Значение L2-нормы.
     */
    T L2norm() const {
        T norm = 0;
        for (size_t i = 0; i < size; ++i) {
            norm += data[i] * data[i];
        }
        return std::sqrt(norm);
    }

    /**
     * @brief Метод сортировки пузырьком.
     */
    void bubbleSort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }

    /**
     * @brief Метод сортировки выбором.
     */
    void selectionSort() {
        for (size_t i = 0; i < size - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < size; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(data[i], data[minIndex]);
        }
    }

    /**
     * @brief Переворот элементов вектора.
     */
    void reverse() {
        for (size_t i = 0; i < size / 2; ++i) {
            std::swap(data[i], data[size - i - 1]);
        }
    }

    /**
     * @brief Проверка, является ли вектор палиндромом.
     * @return true, если вектор палиндром, иначе false.
     */
    bool isPalindrome() const {
        for (size_t i = 0; i < size / 2; ++i) {
            if (data[i] != data[size - i - 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Вывод вектора в поток.
     * @param os Поток вывода.
     * @param vec Вектор для вывода.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const iaVector& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i] << " ";
        }
        return os;
    }
};

#endif // IAVECTOR_HPP
