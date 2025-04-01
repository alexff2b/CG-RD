//
//  iaArray.cpp
//  Classes_DevTest
//
//  Created by alexff on 09/02/2025.
//

#include "../DataClasses/iaArray.hpp"

/**
 * @brief Конструктор по умолчанию.
 * Устанавливает вместимость массива по умолчанию.
 */
template <typename T>
iaArray<T>::iaArray() : capacity(10), size(0) {
    this->data = new T[capacity]; // Выделение памяти для массива
}

/**
 * @brief Конструктор с заданной вместимостью.
 * @param initialCapacity Начальная вместимость массива.
 */
template <typename T>
iaArray<T>::iaArray(size_t initialCapacity) : capacity(initialCapacity > 0 ? initialCapacity : 10), size(0) {
    this->data = new T[capacity]; // Выделение памяти для массива
}

/**
 * @brief Конструктор с заданными параметрами.
 * @param size Размер массива.
 * @param initialCapacity Начальная вместимость массива.
 * @param data Указатель на массив данных.
 */
template <typename T>
iaArray<T>::iaArray(size_t size, size_t initialCapacity, T* data) : size(size), capacity(initialCapacity > 0 ? initialCapacity : 10) {
    this->data = new T[capacity]; // Выделение памяти для массива
    for (size_t i = 0; i < size; i++) {
        this->data[i] = data[i]; // Копирование данных
    }
}

/**
 * @brief Конструктор копирования.
 * @param otherArray Другой массив для копирования.
 */
template<typename T>
iaArray<T>::iaArray(const iaArray& otherArray) : size(otherArray.size), capacity(otherArray.capacity), data(nullptr) {
    if (size > 0) {
        data = new T[size]; // Выделение памяти для значений
        for (size_t i = 0; i < size; i++) {
            data[i] = otherArray.data[i]; // Копирование значений
        }
    }
}

/**
 * @brief Деструктор.
 * Освобождает память, занятую массивом.
 */
template <typename T>
iaArray<T>::~iaArray() {
    delete[] data; // Освобождение памяти
}

/*
 // ... existing code ...
 // Конструктор
 iaArray::iaArray(size_t initialSize) {
 // Инициализация массива заданного размера
 this->size = initialSize;
 this->capacity = initialSize;
 this->data = new int[capacity]; // Выделение памяти
 }
 
 // Деструктор
 iaArray::~iaArray() {
 delete[] data; // Освобождение памяти
 }
 
 // Метод добавления элемента
 void iaArray::add(int value) {
 if (size >= capacity) {
 // Увеличение емкости массива
 capacity *= 2;
 int* newData = new int[capacity];
 for (size_t i = 0; i < size; i++) {
 newData[i] = data[i]; // Копирование старых данных
 }
 delete[] data; // Освобождение старой памяти
 data = newData; // Перенаправление указателя
 }
 data[size++] = value; // Добавление нового элемента
 }
 
 // Метод получения элемента по индексу
 int iaArray::get(size_t index) const {
 if (index < size) {
 return data[index]; // Возврат элемента
 }
 throw std::out_of_range("Index out of range"); // Исключение при выходе за пределы
 }
 
 // Метод получения текущего размера массива
 size_t iaArray::getSize() const {
 return size; // Возврат текущего размера
 }
 
 // ... existing code ...
 */
