/* ****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaArray.hpp
 *    @brief      : Реализация шаблонного класса iaArray (Динамический массив).
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.1.0 (Development)
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
 *    @created    : Март 2025
 *    @modified   : Март 2025
 *    @released   : [Добавить дату релиза, если применимо]
 *
 *    @description:
 *                  Этот заголовочный файл содержит определение шаблонного класса `iaArray<T>`,
 *                  предназначенного для работы с динамическими массивами.
 *                  Класс предоставляет базовые операции добавления, удаления, доступа
 *                  к элементам и автоматического изменения размера массива.
 *
 *                  Основные возможности класса:
 *                    - Создание массива с различными типами данных
 *                    - Автоматическое изменение размера
 *                    - Операции добавления, удаления и поиска элементов
 *                    - Поддержка итераторов
 *                    - Совместимость с алгоритмами стандартной библиотеки C++
 *
 *    @applications:
 *                  Класс `iaArray` применяется в различных областях программирования:
 *                  - **Системное программирование**: работа с динамическими структурами данных.
 *                  - **Компьютерная графика**: хранение и обработка больших наборов данных.
 *                  - **Машинное обучение**: векторизация данных, обработка массивов признаков.
 *                  - **Алгоритмы и структуры данных**: реализация динамических контейнеров.
 *                  - **Базы данных**: временное хранение и обработка записей.
 *                  - **Финансовые вычисления**: работа с временными рядами.
 *
 *    @tested_types:
 *                  Класс `iaArray` прошел тестирование на следующих типах данных:
 *                  - `int` – целочисленные данные
 *                  - `double` – числа с плавающей запятой двойной точности
 *                  - `std::string` – строки
 *                  - `iaArray<T>` – вложенные динамические массивы
 *
 *    @methods:
 *                   - iaArray(); // Конструктор по умолчанию
 *                   - iaArray(size_t m); // Конструктор с начальным размером
 *                   - iaArray(std::initializer_list<T> list); // Конструктор со списком значений
 *                   - iaArray(const iaArray<T>& other); // Конструктор копирования
 *                   - iaArray& operator=(const iaArray<T>& other); // Оператор присваивания
 *                   - ~iaArray(); // Деструктор
 *                   - size_t size() const; // Возвращает текущий размер массива
 *                   - bool empty() const; // Проверка, пуст ли массив
 *                   - void push_back(const T& value); // Добавить элемент в конец
 *                   - void pop_back(); // Удалить последний элемент
 *                   - void resize(size_t newSize); // Изменить размер массива
 *                   - void insert(size_t index, const T& value); // Вставка элемента сдвигом вправо
 *                   - void remove(size_t index); // Удаление элемента сдвигом влево
 *                   - bool erase(const T& value); // Удаление элемента по значению
 *                   - void reverse(); // Переворот массива
 *                   - void swap(iaArray<T>& other); // Обмен содержимым с другим массивом
 *                   - T& at(size_t index); // Безопасный доступ к элементу с проверкой границ
 *                   - T& operator[](int index); // Доступ к элементу по индексу
 *                   - const T& operator[](int index) const; // Константный доступ
 *                   - void clear(); // Очистить массив
 *                   - void assign(size_t n, const T& value); // Заполнить массив значениями
 *                   - T* begin(); // Итератор на начало
 *                   - T* end(); // Итератор на конец
 *
 *    @license:
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Полный текст лицензии находится в файле LICENSE в корне проекта.
 *                  Официальный текст лицензии доступен по адресу:
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 *    @project_website: [Добавить ссылку на сайт проекта, когда он появится]
 *
 ****************************************************************************************************
 */
#ifndef IA_ARRAY_HPP
#define IA_ARRAY_HPP

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

template <typename T>
class iaArray {
private:
    T* data;
    size_t capacity;
    size_t count;

public:
    // Конструктор по умолчанию
    iaArray() : data(nullptr), capacity(0), count(0) {}

    // Конструктор с начальной вместимостью
    explicit iaArray(size_t n) : data(new T[n]{}), capacity(n), count(n) {}

    // Конструктор инициализации через список
    iaArray(std::initializer_list<T> list) 
        : data(new T[list.size()]), capacity(list.size()), count(list.size()) {
        std::copy(list.begin(), list.end(), data);
    }

    // Конструктор копирования
    iaArray(const iaArray<T>& other) 
        : data(new T[other.capacity]), capacity(other.capacity), count(other.count) {
        std::copy(other.data, other.data + other.count, data);
    }

    // Конструктор перемещения
    iaArray(iaArray<T>&& other) noexcept 
        : data(other.data), capacity(other.capacity), count(other.count) {
        other.data = nullptr;
        other.capacity = other.count = 0;
    }

    // Конструктор из итераторов
    template <typename Iterator>
    iaArray(Iterator begin, Iterator end) {
        size_t n = std::distance(begin, end);
        data = new T[n];
        std::copy(begin, end, data);
        capacity = count = n;
    }

    // Деструктор
    ~iaArray() { delete[] data; }

    // Методы доступа
    size_t size() const { return count; }
    size_t getCapacity() const { return capacity; }
    bool empty() const { return count == 0; }

    T& at(size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= count) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Операторы
    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    // Методы изменения
    void push_back(const T& value) {
        if (count == capacity) reserve(capacity == 0 ? 1 : capacity * 2);
        data[count++] = value;
    }

    void pop_back() {
        if (count > 0) --count;
    }

    void insert(size_t index, const T& value) {
        if (index > count) throw std::out_of_range("Index out of range");
        if (count == capacity) reserve(capacity == 0 ? 1 : capacity * 2);
        for (size_t i = count; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++count;
    }

    void remove(size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        --count;
    }

    void reserve(size_t newCapacity) {
        if (newCapacity <= capacity) return;
        T* newData = new T[newCapacity];
        std::copy(data, data + count, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void clear() {
        delete[] data;
        data = nullptr;
        count = capacity = 0;
    }

    // Метод для вывода массива
    void print(std::ostream& out) const {
        for (size_t i = 0; i < count; ++i) {
            out << data[i] << " ";
        }
        out << std::endl;
    }

    // Итераторы
    T* begin() { return data; }
    T* end() { return data + count; }
    const T* begin() const { return data; }
    const T* end() const { return data + count; }

    // Метод для обратного порядка
    void reverse() {
        size_t left = 0;
        size_t right = count - 1;
        while (left < right) {
            std::swap(data[left], data[right]);
            ++left;
            --right;
        }
    }

    // Метод для обмена данными с другим массивом
    void swap(iaArray<T>& other) {
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
        std::swap(count, other.count);
    }

    // Метод для присваивания значений всему массиву
    void assign(size_t n, const T& value) {
        if (n > capacity) reserve(n);
        for (size_t i = 0; i < n; ++i) {
            data[i] = value;
        }
        count = n;
    }

    // Удаление элемента по значению
    bool erase(const T& value) {
        for (size_t i = 0; i < count; ++i) {
            if (data[i] == value) {
                remove(i);
                return true;
            }
        }
        return false;
    }
};

#endif // IA_ARRAY_HPP
