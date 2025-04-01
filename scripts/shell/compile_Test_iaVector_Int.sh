#!/bin/bash

# Устанавливаем строгий режим работы скрипта
set -e  # Прерывает выполнение при ошибке
set -u  # Запрещает использование необъявленных переменных

# Определяем пути
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SRC_FILE="$PROJECT_ROOT/tests/iaVectorTest/Test_iaVector_Int.cpp"
OUTPUT_FILE="$PROJECT_ROOT/tests/Test_iaVector_Int"

# Флаги компиляции
CXX=g++
CXX_FLAGS="-std=c++17 -Wall -Wextra -Wpedantic -O2"

# Компиляция
echo "Компиляция $SRC_FILE..."
$CXX $CXX_FLAGS -o "$OUTPUT_FILE" "$SRC_FILE"

# Проверяем успешность
if [[ -f "$OUTPUT_FILE" ]]; then
    echo "✅ Компиляция завершена успешно! Исполняемый файл: $OUTPUT_FILE"
else
    echo "❌ Ошибка компиляции!" >&2
    exit 1
fi
