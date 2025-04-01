#!/bin/bash

# Переменные
SRC="tests/iaScreenTest/screen_Test.cpp"
OUT="tests/Test_iaScreen"
INCLUDE_DIR="iaVisualizations/iaConsole/"
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra"

# Компиляция
echo "Компилируем $SRC -> $OUT"
$CXX $CXXFLAGS -o $OUT $SRC iaVisualizations/iaConsole/iaScreen.cpp -I$INCLUDE_DIR

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
    echo "Исполняемый файл: $OUT"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi