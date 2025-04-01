#!/bin/bash

# Переменные
SRC="tests/iaPerceptron/iaPerceptronTest.cpp"
OUT="tests/Test_iaPerceptron"

IA_PERCEPTRON_SRC="iaAi/iaMl/iaPerceptron/iaPerceptron.cpp"
IA_ACTIVATIONS_SRC="iaMath/iaFunctions/iaActivations.cpp"

CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra"

# Пути к заголовочным файлам
INCLUDE_DIRS="-I. -IiaAi/iaMl/iaPerceptron -IiaMath/iaFunctions -IiaMath/iaLinearAlgebra/iaVector"

# Компиляция
echo "Компилируем $SRC -> $OUT"
$CXX $CXXFLAGS -o $OUT $SRC $IA_PERCEPTRON_SRC $IA_ACTIVATIONS_SRC $INCLUDE_DIRS

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
    echo "Исполняемый файл: $OUT"
else
    echo "❌ Ошибка компиляции!"
    exit 1
fi
