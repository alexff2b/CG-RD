#include <stdio.h>
#include <stdlib.h>
#include "iaLinkedLinearList.h"

// Функция для создания нового узла
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // выделяем память
    newNode->data = value;  // присваиваем данные узла
    newNode->next = NULL;   // устанавливаем указатель на следующий узел в NULL
    return newNode;
}

// Функция для добавления узла в конец списка
void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // создаем новый узел
    if (*head == NULL) {
        *head = newNode;  // если список пустой, новый узел становится головой списка
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;  // ищем последний узел
        }
        temp->next = newNode;  // добавляем новый узел в конец списка
    }
}

// Функция для вывода списка
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);  // выводим данные узла
        temp = temp->next;  // переходим к следующему узлу
    }
    printf("NULL\n");
}

// Функция для удаления всего списка
void deleteList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // освобождаем память
    }
}
