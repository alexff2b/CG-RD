#!/bin/bash

# Указываем имя выходного файла
output_file="project_structure_with_comments.txt"

# Удаляем файл, если он существует
if [ -f "$output_file" ]; then
    rm "$output_file"
fi

# Функция для добавления комментариев
add_comment() {
    echo "# $1" >> "$output_file"
}

# Добавляем заголовок
echo "# Структура проекта" > "$output_file"
echo "# Ниже представлена структура папок и файлов с пояснениями." >> "$output_file"
echo "" >> "$output_file"

# Рекурсивно проходим по всем каталогам и файлам, исключая скрытые папки и файлы, такие как .generated_files

# Директории
find . -type d -not -path './.*' -not -path './*/*/.generated_files*' -print | while read dir; do
    echo "$dir" >> "$output_file"
    add_comment "Каталог: $dir"
done

# Файлы
find . -type f -not -path './.*' -not -path './*/*/.generated_files*' -print | while read file; do
    echo "$file" >> "$output_file"
    add_comment "Файл: $file"
done

echo "Структура проекта с комментариями записана в $output_file"
