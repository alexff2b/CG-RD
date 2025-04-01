# этот скрипт добавляетпапки и пустые файлы для библиотек математических функций
import os

# Определяем структуру папок и файлов для библиотеки математических функций
structure = {
    "iaAi/iaMath/iaFunctions": [
        "activation_functions.hpp",
        "derivatives.hpp",
        "utils.hpp",
        "activation_functions.cpp",
        "derivatives.cpp",
        "utils.cpp"
    ],
    "test/iaFunctionsTest": [
        "iaFunctionsTest.cpp"
    ]
}

# Функция для создания структуры папок и файлов
def create_structure(base_path, structure):
    for folder, files in structure.items():
        folder_path = os.path.join(base_path, folder)
        # Создаем папку, если её нет
        os.makedirs(folder_path, exist_ok=True)
        # Создаем файлы в папке
        for file_name in files:
            file_path = os.path.join(folder_path, file_name)
            # Создаем пустой файл
            with open(file_path, 'w') as f:
                pass  # Пустой файл

# Главная функция
if __name__ == "__main__":
    base_path = os.getcwd()  # Путь к текущей директории (корень проекта)
    create_structure(base_path, structure)
    print("Структура проекта для математической библиотеки создана.")
