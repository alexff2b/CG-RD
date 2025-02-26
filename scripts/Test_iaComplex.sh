#!/bin/bash

# Проверка существования нужных файлов
echo "Проверка существования файлов..."

# Пути к исходным файлам с учётом расположения скрипта в папке scripts
TEST_FILE="../tests/iaComplexTest/iaComplexTest.cpp"
COMPLEX_FILE="../iaAi/iaMath/iaLinearAlgebra/iaComplex/iaComplex.cpp"
HEADER_FILE="../iaAi/iaMath/iaLinearAlgebra/iaComplex/iaComplex.hpp"

# Проверка существования файлов
if [ ! -f "$TEST_FILE" ]; then
    echo "Ошибка: Файл теста $TEST_FILE не найден!"
    exit 1
fi

if [ ! -f "$COMPLEX_FILE" ]; then
    echo "Ошибка: Файл $COMPLEX_FILE не найден!"
    exit 1
fi

if [ ! -f "$HEADER_FILE" ]; then
    echo "Ошибка: Заголовочный файл $HEADER_FILE не найден!"
    exit 1
fi

# Создание папки для результата, если она не существует
OUTPUT_DIR="../tests/iaComplexTest"
if [ ! -d "$OUTPUT_DIR" ]; then
    mkdir -p "$OUTPUT_DIR"
fi

# Команда для компиляции тестера
echo "Компиляция тестера..."
clang++ -std=c++17 -Wall -Wextra -Werror -pedantic -I../iaAi "$TEST_FILE" "$COMPLEX_FILE" -o "$OUTPUT_DIR/iaComplexTest"

# Проверка результата
if [ $? -eq 0 ]; then
    echo "Компиляция прошла успешно!"
    echo "Для запуска тестера используйте команду: ./$OUTPUT_DIR/iaComplexTest"
else
    echo "Ошибка компиляции."
    exit 1
fi
