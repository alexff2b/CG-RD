#ifndef IALINKEDLINEARLIST_H
#define IALINKEDLINEARLIST_H

// Структура узла связанного списка
struct Node {
    int data;           // Данные узла
    struct Node* next;  // Указатель на следующий узел
};

// Функции для работы с линейным связанным списком
struct Node* createNode(int value);       // Создание нового узла
void appendNode(struct Node** head, int value);  // Добавление узла в конец списка
void printList(struct Node* head);       // Вывод списка
void deleteList(struct Node* head);      // Удаление списка

#endif // IALINKEDLINEARLIST_H
