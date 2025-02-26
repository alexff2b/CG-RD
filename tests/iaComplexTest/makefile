# Определяем компилятор и флаги в зависимости от ОС
ifeq ($(shell uname), Darwin)
	# Для macOS
	CXX = clang++
	CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
else
	# Для Linux
	CXX = g++
	CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
endif

# Путь к корню проекта
PROJECT_ROOT = ../../

# Путь к папке с исходниками и заголовочными файлами
SRC_DIR = $(PROJECT_ROOT)iaAi/iaMath/iaLinearAlgebra/iaComplex
INCLUDE_DIR = $(PROJECT_ROOT)iaAi
TEST_SRC = iaComplexTest.cpp
COMPLEX_SRC = $(SRC_DIR)/iaComplex.cpp
HEADER = $(SRC_DIR)/iaComplex.hpp
OUT_DIR = .

# Имя исполнимого файла
OUTPUT = iaComplexTest

# Цель по умолчанию
all: $(OUTPUT)

# Компиляция и линковка
$(OUTPUT): $(TEST_SRC) $(COMPLEX_SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TEST_SRC) $(COMPLEX_SRC) -o $(OUT_DIR)/$(OUTPUT)

# Очистка скомпилированных файлов
clean:
	rm -f $(OUT_DIR)/$(OUTPUT)

# Запуск теста
run: $(OUTPUT)
	./$(OUTPUT)

# Результат
results: run
