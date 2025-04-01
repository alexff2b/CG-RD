#!/bin/bash

# Скрипт компиляции с использованием стандарта C++17

# Пути к исходным файлам и заголовочным файлам
SOURCE_FILE="tests/iaDerivativesTest/iaDerivativesTest.cpp"
DERIVATIVES_FILE="iaMath/iaFunctions/iaDerivatives.cpp"  # Укажите правильный путь к iaDerivatives.cpp
OUTPUT_FILE="tests/Test_iaDerivatives"

# Пути к заголовочным файлам
INCLUDE_DIRS=(
    "iaMath/iaFunctions"           # Директория с функциями производных
    "iaMath/iaLinearAlgebra/iaVector"  # Директория с iaVector.hpp
)

# Формирование флагов -I для компилятора
INCLUDE_FLAGS=""
for dir in "${INCLUDE_DIRS[@]}"; do
    INCLUDE_FLAGS="$INCLUDE_FLAGS -I$dir"
done

# Компиляция с флагами
g++ -std=c++17 -Wall $INCLUDE_FLAGS -o $OUTPUT_FILE $SOURCE_FILE $DERIVATIVES_FILE

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция прошла успешно."
else
    echo "❌ Ошибка компиляции."
    exit 1
fi
