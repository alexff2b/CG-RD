#include <stdio.h>
#include "iaLinkedLinearList.h"

int main() {
    // 1. Создаем пустой список
    struct Node* head = NULL;

    // 2. Добавляем элементы в список
    printf("Добавляем элементы в список:\n");
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // 3. Печатаем список (вперед)
    printf("Содержимое списка (вперед):\n");
    printList(head);

    // 4. Печатаем список (назад)
    printf("Содержимое списка (назад):\n");
    printListBackward(head);

    // 5. Удаляем список
    printf("Удаляем список...\n");
    deleteList(head);
    head = NULL;  // После удаления списка, голова должна быть NULL

    // 6. Печатаем список, который пуст
    printf("Содержимое списка после удаления:\n");
    printList(head);  // Здесь вывод должен быть "NULL"

    return 0;
}
