# Название программы
TARGET = linked_list_program

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -g

# Исходные файлы
SRC = iaLinkedLinearList.c main.c
OBJ = $(SRC:.c=.o)

# Правило для компиляции всех исходников
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Правило для компиляции исходного файла .c в объектный файл .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка временных файлов
clean:
	rm -f $(OBJ) $(TARGET)

# Правило для выполнения программы
run: $(TARGET)
	./$(TARGET)
