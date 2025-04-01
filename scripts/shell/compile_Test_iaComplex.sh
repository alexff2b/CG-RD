#!/bin/bash

# Пути к файлам
SRC="tests/iaComplexTest/Test_iaComplex.cpp"
IA_COMPLEX_SRC="iaMath/iaLinearAlgebra/iaComplex/iaComplex.cpp"
OUT_DIR="tests"
OUT_FILE="$OUT_DIR/Test_iaComplex"  # Исполняемый файл tests/Test_iaComplex

# Компилятор
CXX=g++

# Флаги компиляции
CXXFLAGS="-std=c++17 -Wall -Wextra -O2"

# Проверяем, существует ли папка OUT_DIR, если нет — создаём
mkdir -p "$OUT_DIR"

# Удаляем старый исполняемый файл, если он существует
[ -f "$OUT_FILE" ] && rm "$OUT_FILE"

# Компиляция
echo "Компиляция $SRC..."
$CXX $CXXFLAGS $SRC $IA_COMPLEX_SRC -o "$OUT_FILE"

# Проверяем, успешно ли прошла компиляция
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна! Исполняемый файл: $OUT_FILE"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi