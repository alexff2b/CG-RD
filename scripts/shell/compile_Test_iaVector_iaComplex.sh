#!/bin/bash

# Переменные
SRC="tests/iaVectorTest/Test_iaVector_iaComplex.cpp"
OUT="tests/Test_iaVector_iaComplex"
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra -Wpedantic"

# Пути к исходникам
IA_COMPLEX_SRC="iaMath/iaLinearAlgebra/iaComplex/iaComplex.cpp"

# Пути к заголовочным файлам
INCLUDE_DIRS="-IiaMath/iaLinearAlgebra/iaVector -IiaMath/iaLinearAlgebra/iaComplex"

# Компиляция
echo "Компилируем $SRC -> $OUT"
$CXX $CXXFLAGS -o $OUT $SRC $IA_COMPLEX_SRC $INCLUDE_DIRS

# Проверка статуса компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
    echo "Исполняемый файл: $OUT"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi
