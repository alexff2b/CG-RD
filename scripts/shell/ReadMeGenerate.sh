#!/usr/bin/env bash

# Функция для извлечения информации из шапки файла
extract_info() {
    local file="$1"
    local filename=""
    local brief=""
    local description=""

    while IFS= read -r line; do
        line="${line#"${line%%[![:space:]]*}"}"  # Убираем ведущие пробелы
        line="${line%${line##*[![:space:]]}}"  # Убираем конечные пробелы

        [[ "$line" =~ @file[[:space:]]*:[[:space:]]*(.*) ]] && filename="${BASH_REMATCH[1]}"
        [[ "$line" =~ @brief[[:space:]]*:[[:space:]]*(.*) ]] && brief="${BASH_REMATCH[1]}"
        [[ "$line" =~ @description[[:space:]]*:[[:space:]]*(.*) ]] && description="${BASH_REMATCH[1]}"
    done < <(head -n 50 "$file") # Читаем только первые 50 строк

    [[ -z "$description" ]] && description="Нет описания"
    echo "$filename|$brief|$description"
}

# Обрабатываем директории рекурсивно
find . -type d -not -path "./.*" | while read -r dir; do
    readme_file="$dir/README.md"
    echo "# $(basename "$dir")" > "$readme_file"
    echo "" >> "$readme_file"
    echo "## Описание" >> "$readme_file"
    echo "Папка **$(basename "$dir")** содержит следующие файлы и подпапки:" >> "$readme_file"
    echo "" >> "$readme_file"

    has_files=false
    has_subfiles=false
    temp_list=$(mktemp)  # Временный файл для уникальных записей

    # Поиск файлов с кодом в текущей папке
    for file in "$dir"/*; do
        [[ -f "$file" && ("$file" == *.hpp || "$file" == *.h || "$file" == *.cpp || "$file" == *.c) ]] || continue
        has_files=true

        IFS="|" read -r filename brief description <<< "$(extract_info "$file")"
        [[ -z "$filename" ]] && continue

        echo "- 📄 **$filename** — $brief" >> "$temp_list"
        echo "  - $description" >> "$temp_list"
        echo "" >> "$temp_list"
    done

    # Если в папке нет файлов, ищем в подпапках
    if [[ "$has_files" == false ]]; then
        find "$dir" -mindepth 2 -type f \( -name "*.hpp" -o -name "*.h" -o -name "*.cpp" -o -name "*.c" \) | while read -r subfile; do
            has_subfiles=true
            subfolder=$(basename "$(dirname "$subfile")")

            IFS="|" read -r filename brief description <<< "$(extract_info "$subfile")"
            [[ -z "$filename" ]] && continue

            echo "- 📂 **$subfolder/** содержит:" >> "$temp_list"
            echo "  - 📄 **$filename** — $brief" >> "$temp_list"
            echo "    - $description" >> "$temp_list"
            echo "" >> "$temp_list"
        done
    fi

    # Если не было найдено ни файлов, ни подпапок с кодом, оставляем заглушку
    if [[ "$has_files" == false && "$has_subfiles" == false ]]; then
        echo "🔹 В этой папке пока нет описанных файлов." >> "$temp_list"
    fi

    sort -u "$temp_list" >> "$readme_file"  # Исключаем дубликаты
    rm "$temp_list"

    echo "Этот файл был создан автоматически." >> "$readme_file"
done

echo "✅ README.md файлы успешно обновлены во всех папках!"
