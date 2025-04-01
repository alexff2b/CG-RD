#!/bin/bash

echo "Компилируем tests/iaMatrixTest/Test_iaMatrix_Double.cpp -> tests/Test_iaMatrix_Double"

g++ -std=c++17 -Wall -Wextra -Werror \
    tests/iaMatrixTest/Test_iaMatrix_Double.cpp \
    -o tests/Test_iaMatrix_Double \
    -IiaMath/iaLinearAlgebra/iaVector \
    -IiaMath/iaLinearAlgebra/iaMatrix

if [ $? -eq 0 ]; then
    echo "✅ Компиляция успешна!"
else
    echo "❌ Ошибка компиляции!"
fi
