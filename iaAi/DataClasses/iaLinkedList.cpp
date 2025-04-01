#include "../DataClasses/iaLinkedList.hpp"
#include "../MathClasses/iaVector.hpp" // Подключение файла iaVector.hpp

iaSinglyLinkedList::iaSinglyLinkedList() : head(nullptr) {
        // Конструктор инициализирует указатель head как nullptr
}

iaSinglyLinkedList::~iaSinglyLinkedList() {
        // Деструктор для освобождения памяти
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
/*
void iaSinglyLinkedList::add(double value, iaVector<double>* vector) {
    Node* newNode = new Node;
    newNode->data = value; // Заполняем поле double
 //   newNode->vectorObject = vector; // Сохраняем ссылку на объект iaVector
    newNode->next = head; // Новый узел указывает на текущую голову списка
    head = newNode; // Обновляем голову списка
}
*/
