#!/bin/bash

# Проверяем, что скрипт выполняется из корня проекта
if [ ! -d "iaAi" ]; then
    echo "Скрипт должен быть запущен из корня проекта!"
    exit 1
fi

# Создаем папки
mkdir -p iaAi/iaMath/iaFunctions
mkdir -p test/iaFunctionsTest

# Создаем пустые файлы для библиотеки математических функций
touch iaAi/iaMath/iaFunctions/activation_functions.hpp
touch iaAi/iaMath/iaFunctions/derivatives.hpp
touch iaAi/iaMath/iaFunctions/utils.hpp
touch iaAi/iaMath/iaFunctions/activation_functions.cpp
touch iaAi/iaMath/iaFunctions/derivatives.cpp
touch iaAi/iaMath/iaFunctions/utils.cpp

# Создаем пустой файл для тестов
touch test/iaFunctionsTest/iaFunctionsTest.cpp

echo "Структура проекта для математической библиотеки создана."
