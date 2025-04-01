#!/bin/bash

# Устанавливаем строгий режим работы скрипта
set -e  # Прерывает выполнение при ошибке
set -u  # Запрещает использование необъявленных переменных

# Определяем корень проекта
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"

# Путь к исходному файлу с кавычками
SRC_FILE="$PROJECT_ROOT/tests/iaArrayTest/Test_iaArray.cpp"
OUTPUT_FILE="$PROJECT_ROOT/tests/Test_iaArray"

# Выводим путь для диагностики (можно удалить, если не нужно)
echo "Путь к исходному файлу: \"$SRC_FILE\""

# Флаги компиляции
CXX=g++
CXX_FLAGS="-std=c++17 -O2 -g" # Убираем флаги, которые выводят предупреждения

# Переходим в директорию проекта
cd "$PROJECT_ROOT"

# Проверяем, существует ли исходный файл
if [[ ! -f "$SRC_FILE" ]]; then
    echo "❌ Ошибка: Исходный файл \"$SRC_FILE\" не найден!" >&2
    exit 1
fi

# Создаем папку для выходного файла, если её нет
mkdir -p "$(dirname "$OUTPUT_FILE")"

# Компиляция, перенаправляем предупреждения в /dev/null, чтобы их не было в выводе
echo "🔧 Компиляция $SRC_FILE..."
if $CXX $CXX_FLAGS -o "$OUTPUT_FILE" "$SRC_FILE" 2>/dev/null; then
    echo "✅ Компиляция завершена успешно! Исполняемый файл: $OUTPUT_FILE"
else
    echo "❌ Ошибка компиляции!" >&2
    exit 1
fi
