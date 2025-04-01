import os

# Параметры для Doxygen
project_name = "CG RD library"
output_dir = "docs"
source_dir = "s../../"

# Создание файла конфигурации Doxygen
doxygen_config = f"""
# Doxyfile для проекта {project_name}
PROJECT_NAME = {project_name}
OUTPUT_DIRECTORY = {output_dir}
INPUT = {source_dir}
GENERATE_HTML = YES
GENERATE_LATEX = NO
"""

# Запись конфигурации в файл
with open("Doxyfile", "w") as f:
    f.write(doxygen_config)

# Запуск Doxygen
os.system("doxygen Doxyfile")
