#!/bin/bash

# Устанавливаем флаг "немедленного выхода" при ошибке
set -e

echo "Текущая директория: $(pwd)"


# Определяем пути
PROJECT_ROOT=$(pwd)  # Корень проекта (текущая директория)
SRC_DIR="$PROJECT_ROOT/tests/iaVectorTest"  # Директория с тестами
BUILD_DIR="$PROJECT_ROOT/tests"  # Исполняемый файл будет в tests/
INCLUDE_DIR="$PROJECT_ROOT/iaAi/iaMath/iaLinearAlgebra/iaVector"  # Папка с заголовочными файлами

# Компиляция
g++ -std=c++17 -Wall -Wextra -o "$BUILD_DIR/Test_iaVector" \
    "$SRC_DIR/iaVectorTest.cpp" \
    -I"$INCLUDE_DIR"

# Вывод сообщения об успешной компиляции
echo "Компиляция завершена. Запуск: $BUILD_DIR/iaVectorTest"
