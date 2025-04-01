#!/bin/bash

# Указываем имя выходного файла
output_file="project_files.txt"

# Указываем корневую директорию проекта
project_root=$(pwd)

# Записываем заголовок в выходной файл
echo "Структура проекта CG RD >>" > "$output_file"
echo "project_root/" >> "$output_file"

# Функция для рекурсивного обхода директорий
function list_directory {
    local dir="$1"
    local indent="$2"

    # Проходим по всем элементам в директории
    for item in "$dir"/*; do
        if [ -d "$item" ]; then
            # Если это директория, добавляем её в выходной файл
            echo "${indent}├── $(basename "$item")/" >> "$output_file"
            # Рекурсивно вызываем функцию для вложенной директории
            list_directory "$item" "  $indent"
        elif [ -f "$item" ]; then
            # Если это файл, добавляем его в выходной файл
            echo "${indent}├── $(basename "$item")" >> "$output_file"
        fi
    done
}

# Запускаем функцию для корневой директории проекта
list_directory "$project_root" " "

# Выводим сообщение о завершении
echo "Структура проекта сохранена в $output_file"
