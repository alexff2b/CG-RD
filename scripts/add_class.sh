#!/bin/bash

# Определение корневой директории проекта (замени путь, если нужно)
PROJECT_ROOT="../"

# Путь для нового класса
TARGET_DIR="$PROJECT_ROOT/iaAi/iaMath/iaLinearAlgebra/iaComplex"

# Создание директории, если её нет
mkdir -p "$TARGET_DIR"

# Создание пустых файлов
touch "$TARGET_DIR/iaComplex.hpp"
touch "$TARGET_DIR/iaComplex.cpp"

echo "Папка iaComplex и файлы iaComplex.hpp, iaComplex.cpp успешно созданы в $TARGET_DIR"
