# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I iaAi/iaMl/iaVector

# Пути к файлам
TESTS_DIR = tests/iaVectorTest
IA_VECTOR_DIR = iaAi/iaMl/iaVector

# Файлы
TARGET = $(TESTS_DIR)/iaVectorTest
SOURCES = $(TESTS_DIR)/iaVectorTest.cpp $(IA_VECTOR_DIR)/iaVector.cpp
HEADERS = $(IA_VECTOR_DIR)/iaVector.hpp

# Компиляция исполняемого файла
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

tests/iaVectorTest: tests/iaVectorTest.cpp iaAi/iaMl/iaVector/iaVector.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<


# Очистка скомпилированных файлов
clean:
	rm -f $(TARGET)

# Пересборка
rebuild: clean $(TARGET)

.PHONY: clean rebuild


