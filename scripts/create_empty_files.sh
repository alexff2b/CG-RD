#!/bin/bash

# Функция для создания файлов в каждой папке
create_files_in_directory() {
    local dir_name=$1
    local file_name=$2

    # Переходим в нужную директорию и создаем файлы .c и .h
    touch "$dir_name/$file_name.c"
    touch "$dir_name/$file_name.h"
    echo "Созданы файлы: $dir_name/$file_name.c и $dir_name/$file_name.h"
}

# Создание файлов для библиотеки iaDataStructures
create_files_in_directory "../iaAi/iaMl/iaDataStructures" "iaDataStructures"

# Для каждого модуля внутри iaDataStructures
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaArray" "iaArray"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaLinkedList" "iaLinkedList"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaStack" "iaStack"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaQueue" "iaQueue"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaHashTable" "iaHashTable"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaGraph" "iaGraph"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaTree" "iaTree"

# Для каждого класса внутри iaLinkedList
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaLinkedList/iaSinglyLinkedList" "iaSinglyLinkedList"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaLinkedList/iaDoublyLinkedList" "iaDoublyLinkedList"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaLinkedList/iaCircularLinkedList" "iaCircularLinkedList"

# Для каждого класса внутри iaQueue
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaQueue/iaQueue" "iaQueue"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaQueue/iaPriorityQueue" "iaPriorityQueue"

# Для каждого класса внутри iaGraph
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaGraph/iaGraph" "iaGraph"
create_files_in_directory "../iaAi/iaMl/iaDataStructures/iaGraph/iaDirectedGraph" "iaDirectedGraph"

echo "Все файлы .c и .h успешно созданы!"
