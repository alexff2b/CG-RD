/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaScreen.cpp
 *    @brief      : Реализация библиотеки для работы с экраном консоли (очистка, цвета, перемещение курсора, ввод).
 *    @author     : Александр Юшкевич
 *    @aka        : iA, alexff
 *    @project    : Все проекты CG. CG Research & Development(c) Projects
 *    @version    : 1.2.0 (Development)
 *    @license    : Apache License 2.0
 *    @contact    : 
 *                  Email:  
 *                      - alexff.2b@hotmail.com  
 *                      - alexff.2b@gmail.com  
 *                      - alexff.2b@icloud.com  
 *                      - alexff.2b@yandex.ru  
 *                  Телефон:  
 *                      - Франция: +33 6 58 04 64 56  
 *                      - Россия:  +7 985 975 1326  
 *
 *    @created    : Февраль 2024
 *    @modified   : Март 2025
 *    @released   : [Добавить дату релиза, если применимо]
 *
 *    @previous_version: 1.1.0 (Production)
 *
 *    @note       : Изменения с предыдущей версии:
 *                  - Реализована поддержка работы с курсором в терминалах.
 *                  - Улучшена оптимизация обработки ввода клавиш и вывода цветов.
 *                  - Исправлены мелкие ошибки в работе с текстовым выводом.
 *
 *    @description: 
 *                  Файл содержит реализацию методов библиотеки `iaScreen`, которая предназначена для работы с консолью.
 *                  Данная реализация включает в себя функциональность очистки экрана, изменения цветов текста и фона,
 *                  управления курсором и обработки ввода с клавиатуры.
 *
 *    @methods    : [Перечислите здесь краткие описания всех методов]
 *                   - void reset(); // Сброс всех цветов и форматирования.
 *                   - void clear(ClearTarget target); // Очистка экрана или строки.
 *                   - void setTextColor(TextColor color); // Установка цвета текста.
 *                   - void setTextFormat(TextFormat format); // Установка формата текста.
 *                   - void setBackgroundColor(BackColor color); // Установка цвета фона.
 *                   - void moveCursorTo(int x, int y); // Перемещение курсора на заданные координаты.
 *                   - void moveCursorToZero(); // Перемещение курсора в начало.
 *                   - void moveCursorUp(); // Перемещение курсора вверх.
 *                   - void moveCursorDown(); // Перемещение курсора вниз.
 *                   - void moveCursorLeft(); // Перемещение курсора влево.
 *                   - void moveCursorRight(); // Перемещение курсора вправо.
 *                   - KeyCode getKey(); // Получение нажатой клавиши.
 *
 *    @license    :
 *                  Этот файл лицензирован под Apache License 2.0.
 *                  Полный текст лицензии находится в файле LICENSE в корне проекта.
 *                  Официальный текст лицензии доступен по адресу:  
 *                  https://www.apache.org/licenses/LICENSE-2.0
 *
 *    @project_website: [Добавить ссылку на сайт проекта, когда он появится]
 *
 * **************************************************************************************************
 */
#include "iaScreen.hpp"
#include <iostream>
#include <termios.h>
#include <unistd.h>

namespace iaS {

    // Сброс всех терминальных атрибутов
    void reset() {
        std::cout << "\033[0m" << std::flush;
    }

    // Очистка экрана или строки
    void clear(ClearTarget target) {
        std::cout << "\033[" << target << (target == ALL ? "J" : "K") << "\033[H" << std::flush;
    }

    // Установка цвета текста
    void setTextColor(TextColor color) {
        std::cout << "\033[" << color << "m" << std::flush;
    }

    // Установка формата текста
    void setTextFormat(TextFormat format) {
        std::cout << "\033[" << format << "m" << std::flush;
    }

    // Установка цвета фона
    void setBackgroundColor(BackColor color) {
        std::cout << "\033[" << color << "m";
    }

    // Перемещение курсора в заданную позицию
    void moveCursorTo(int x, int y) {
        std::cout << "\033[" << y << ";" << x << "H";
    }

    // Перемещение курсора в начало экрана
    void moveCursorToZero() {
        std::cout << "\033[H";
    }

    // Перемещение курсора вверх
    void moveCursorUp() {
        std::cout << "\033[A";
    }

    // Перемещение курсора вниз
    void moveCursorDown() {
        std::cout << "\033[B";
    }

    // Перемещение курсора вправо
    void moveCursorRight() {
        std::cout << "\033[C";
    }

    // Перемещение курсора влево
    void moveCursorLeft() {
        std::cout << "\033[D";
    }

    // Сохранение позиции курсора
    void saveCursorPosition() {
        std::cout << "\033[s";
    }

    // Восстановление позиции курсора
    void restoreCursorPosition() {
        std::cout << "\033[u";
    }

    // Ожидание ввода клавиши с терминала
    KeyCode getKey() {
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        int ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch == 27) {  // ESC
            if (getchar() == 91) {  // CSI
                switch (getchar()) {
                    case 'A': return UP;           // Стрелка вверх
                    case 'B': return DOWN;         // Стрелка вниз
                    case 'C': return RIGHT;        // Стрелка вправо
                    case 'D': return LEFT;         // Стрелка влево
                    case 'H': return HOME;         // Home
                    case 'F': return END;          // End
                    case '5': { // Страница вверх
                        if (getchar() == '~') return PAGE_UP;
                        break;
                    }
                    case '6': { // Страница вниз
                        if (getchar() == '~') return PAGE_DOWN;
                        break;
                    }
                    case '2': { // Insert
                        if (getchar() == '~') return INSERT;
                        break;
                    }
                    case '3': { // Delete
                        if (getchar() == '~') return DELETE;
                        break;
                    }
                    case '1': { // F1
                        if (getchar() == '~') return F1;
                        break;
                    }
                    case '4': { // F4
                        if (getchar() == '~') return F4;
                        break;
                    }
                    // Для других функциональных клавиш можно продолжить с уникальными значениями.
                }
            }
            return ESC;  // ESC
        }

        if (ch == 10) return ENTER;  // Enter
        if (ch == 32) return SPACE;  // Space
        return OTHER;  // Все остальные клавиши
    }
}
