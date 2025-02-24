import os

# Структура папок проекта
directories = [
    "iaLanguageProcessing",
    "iaPerceptron",
    "iaLexer",
    "iaToken",
    "iaMemory",
    "iaNeuralNetworks",
    "iaObjectRecognition",
    "iaSpeechSynthesis"
]

# Путь к основной папке проекта
base_path = "iaMl"

# Создание файлов в каждой папке
for directory in directories:
    dir_path = os.path.join(base_path, directory)
    
    # Проверка, существует ли папка
    if os.path.exists(dir_path):
        # Создание .hpp файла
        hpp_file_path = os.path.join(dir_path, f"{directory}.hpp")
        with open(hpp_file_path, 'w') as hpp_file:
            hpp_file.write(f"// Header file for {directory}\n")
        
        # Создание .cpp файла
        cpp_file_path = os.path.join(dir_path, f"{directory}.cpp")
        with open(cpp_file_path, 'w') as cpp_file:
            cpp_file.write(f"// Source file for {directory}\n")
    else:
        print(f"Directory {dir_path} does not exist.")
