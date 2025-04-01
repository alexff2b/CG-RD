//
//  iaLinkedList.hpp
//  Classes_DevTest
//
//  Created by alexff on 06/02/2025.
//
#ifndef iaLinkedList_hpp
#define iaLinkedList_hpp

#include <iostream>
#include "../MathClasses/iaVector.hpp"

//#include "../MathClasses/iaVector.hpp" // Подключение файла iaVector.hpp

class iaSinglyLinkedList {
private:
    struct Node {
     //   iaMemory* data; // Указатель на объект iaMemory
        double data;   // Поле типа double
        iaVector<double>* vectorRef; // Указатель на объект iaVector
        Node* next;
    };
    Node* head;
    
public:
    iaSinglyLinkedList();
    ~iaSinglyLinkedList();
    void add(double value, iaVector<double>* vector); // Метод для добавления элемента
        
};

#endif /* iaLinkedList_hpp */

/*

    // Класс для односвязного списка
template <typename T>
class iaSinglyLinkedList : public LinkedList<T> {
        // Реализация односвязного списка
public:
    void add(T value) override {
            // Логика добавления элемента
    }
    
    void display() override {
            // Логика отображения списка
    }
};

    // Класс для двусвязного списка
template <typename T>
class iaDoublyLinkedList : public LinkedList<T> {
        // Реализация двусвязного списка
public:
    void add(T value) override {
            // Логика добавления элемента
    }
    
    void display() override {
            // Логика отображения списка
    }
};

    // Класс для кольцевого списка
template <typename T>
class iaCircularLinkedList : public LinkedList<T> {
        // Реализация кольцевого списка
public:
    void add(T value) override {
            // Логика добавления элемента
    }
    
    void display() override {
            // Логика отображения списка
    }
};

    // Класс для кольцевого двусвязного списка
template <typename T>
class iaCircularDoublyLinkedList : public LinkedList<T> {
        // Реализация кольцевого двусвязного списка
public:

*/
