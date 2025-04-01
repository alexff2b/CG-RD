#!/bin/bash

# Определение корневой директории проекта
PROJECT_ROOT="../"

# Старое и новое расположение папки iaVector
OLD_DIR="$PROJECT_ROOT/iaAi/iaMl/iaVector"
NEW_DIR="$PROJECT_ROOT/iaAi/iaMath/iaLinearAlgebra/iaVector"

# Перемещение папки
if [ -d "$OLD_DIR" ]; then
    mv "$OLD_DIR" "$NEW_DIR"
    echo "Папка iaVector перемещена в $NEW_DIR"
else
    echo "Ошибка: Папка iaVector не найдена в $OLD_DIR"
    exit 1
fi

# Обновление путей в коде (если файлы используют старый путь)
grep -rl "iaMl/iaVector" "$PROJECT_ROOT" | xargs sed -i 's|iaMl/iaVector|iaMath/iaLinearAlgebra/iaVector|g'

echo "Обновлены пути в коде с iaMl/iaVector на iaMath/iaLinearAlgebra/iaVector"
