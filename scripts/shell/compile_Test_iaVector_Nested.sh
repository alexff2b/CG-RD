#!/bin/bash

# Переменные
SRC="tests/iaVectorTest/Test_iaVector_Nested.cpp"
OUT="tests/Test_iaVector_Nested"
INCLUDE_DIR="iaMath"  # Путь относительно корня проекта
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra -Wpedantic"

# Компиляция
echo "Компилируем $SRC -> $OUT"
$CXX $CXXFLAGS -o $OUT $SRC -I$INCLUDE_DIR

# Проверка статуса компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
    echo "Исполняемый файл: $OUT"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi
