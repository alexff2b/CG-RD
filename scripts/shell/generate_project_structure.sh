#!/bin/bash

# Определяем путь к скрипту
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Определяем корень проекта (на 2 уровня выше)
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

# Имя выходного файла
OUTPUT_FILE="$PROJECT_ROOT/project_structure.txt"

# Записываем структуру проекта в файл
echo "📂 Структура проекта: $PROJECT_ROOT" > "$OUTPUT_FILE"
echo "-----------------------------------" >> "$OUTPUT_FILE"
tree "$PROJECT_ROOT" >> "$OUTPUT_FILE"

# Сообщение о завершении
echo "✅ Структура проекта сохранена в $OUTPUT_FILE"
