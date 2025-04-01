#!/bin/bash

# Начало скрипта для создания структуры папок

# Главная библиотека: iaDataStructures
mkdir -p ../iaAi/iaMl/iaDataStructures

# Модули внутри iaDataStructures
mkdir -p ../iaAi/iaMl/iaDataStructures/iaArray
mkdir -p ../iaAi/iaMl/iaDataStructures/iaLinkedList
mkdir -p ../iaAi/iaMl/iaDataStructures/iaStack
mkdir -p ../iaAi/iaMl/iaDataStructures/iaQueue
mkdir -p ../iaAi/iaMl/iaDataStructures/iaHashTable
mkdir -p ../iaAi/iaMl/iaDataStructures/iaGraph
mkdir -p ../iaAi/iaMl/iaDataStructures/iaTree

# Библиотека iaArray
mkdir -p ../iaAi/iaMl/iaDataStructures/iaArray/iaArray

# Библиотека iaLinkedList
mkdir -p ../iaAi/iaMl/iaDataStructures/iaLinkedList/iaSinglyLinkedList
mkdir -p ../iaAi/iaMl/iaDataStructures/iaLinkedList/iaDoublyLinkedList
mkdir -p ../iaAi/iaMl/iaDataStructures/iaLinkedList/iaCircularLinkedList

# Библиотека iaStack
mkdir -p ../iaAi/iaMl/iaDataStructures/iaStack/iaStack

# Библиотека iaQueue
mkdir -p ../iaAi/iaMl/iaDataStructures/iaQueue/iaQueue
mkdir -p ../iaAi/iaMl/iaDataStructures/iaQueue/iaPriorityQueue

# Библиотека iaHashTable
mkdir -p ../iaAi/iaMl/iaDataStructures/iaHashTable/iaHashTable

# Библиотека iaGraph
mkdir -p ../iaAi/iaMl/iaDataStructures/iaGraph/iaGraph
mkdir -p ../iaAi/iaMl/iaDataStructures/iaGraph/iaDirectedGraph

# Заканчиваем скрипт
echo "Все необходимые папки успешно созданы!"
