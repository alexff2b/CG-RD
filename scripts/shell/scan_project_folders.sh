#!/bin/bash

# Определяем корень проекта
project_root=$(pwd)

# Указываем файл для сохранения структуры
output_file="$project_root/project_structure.txt"

# Записываем заголовок в файл
echo "Структура проекта CG RD >>" > "$output_file"
echo "project_root/" >> "$output_file"

# Функция для рекурсивного обхода директорий
function list_directories {
    local dir="$1"
    local level="$2"
    local indent=$(printf ' %.0s' $(seq 1 $level)) # Пробелы для отступа

    for entry in "$dir"/*; do
        if [ -d "$entry" ]; then
            echo "${indent}├── $(basename "$entry")/" >> "$output_file"
            list_directories "$entry" $((level + 1))
        fi
    done
}

# Запускаем функцию с корнем проекта
list_directories "$project_root" 1
