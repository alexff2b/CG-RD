#!/bin/bash

# Путь к корневой папке проекта
PROJECT_ROOT="../"  # Измените на правильный путь, если необходимо

# Проходим по всем папкам в проекте
find "$PROJECT_ROOT" -type d | while read -r dir; do
    # Проверяем, пустая ли папка
    if [ -z "$(ls -A "$dir")" ]; then
        # Получаем имя папки
        folder_name=$(basename "$dir")
        # Создаем пустые файлы с расширениями .hpp и .cpp
        touch "$dir/$folder_name.hpp"
        touch "$dir/$folder_name.cpp"
        echo "Созданы файлы: $folder_name.hpp и $folder_name.cpp в $dir"
    fi
done
