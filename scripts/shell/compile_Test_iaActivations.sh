#!/bin/bash

# Переменные
SRC="tests/iaActivationsTest/iaActivationsTest.cpp"
OUT="tests/Test_iaActivations"
INCLUDE_DIR="iaMath/iaFunctions"
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra"

# Компиляция
echo "Компилируем $SRC -> $OUT"
$CXX $CXXFLAGS -o $OUT $SRC iaMath/iaFunctions/iaActivations.cpp -I$INCLUDE_DIR

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
    echo "Исполняемый файл: $OUT"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi