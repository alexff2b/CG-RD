/*
****************************************************************************************************
 *
 *    Компания    : Helios Prime - Nova Terra (CosmoGenesis)(c)
 *    @file       : iaScreen.hpp
 *    @brief      : Библиотека для работы с экраном консоли (очистка, цвета, перемещение курсора, ввод).
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
 *                  - Улучшена поддержка цветного вывода в терминалах Windows/Linux/macOS.
 *                  - Добавлены новые функции работы с курсором.
 *                  - Оптимизирован ввод клавиш (поддержка специальных клавиш, обработка ESC-последовательностей).
 *                  - Улучшена документация и добавлены примеры использования.
 *
 *    @description: 
 *                  `iaScreen` — это библиотека для работы с экраном консоли, которая позволяет:
 *                  - Управлять цветом текста и фона.
 *                  - Очищать экран или его части.
 *                  - Перемещать курсор в заданные координаты.
 *                  - Считывать нажатия клавиш (включая специальные клавиши).
 *                  
 *                  Поддерживается работа в терминалах Windows (через WinAPI) и Linux/macOS (через ANSI-escape).
 *
 *    @applications:
 *                  `iaScreen` используется в различных приложениях, таких как:
 *                  - **Игры**: текстовые и консольные интерфейсы, управление экраном.
 *                  - **Разработка CLI**: создание пользовательских интерфейсов командной строки.
 *                  - **Отладка и тестирование**: визуализация отладочной информации в консоли.
 *                  - **Образовательные проекты**: тренировка работы с консольным вводом/выводом.
 *
 *    @platforms   : 
 *                  - Windows (cmd, PowerShell, Windows Terminal)
 *                  - Linux (bash, zsh, терминалы с поддержкой ANSI)
 *                  - macOS (Terminal, iTerm, другие эмуляторы терминала)
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

#ifndef IASCREEN_HPP
#define IASCREEN_HPP

// Для работы с операционной системой
#ifdef _WIN32  // Для Windows
#include <windows.h>
#else  // Для Unix-подобных систем (Linux, macOS)
#include <unistd.h>
#include <term.h>  // Для работы с терминалом на Unix
#endif

namespace iaS {

    // Enum for clearing screen or line
    enum ClearTarget { 
        ALL = 2,   /**< Clear the entire screen. */
        LINE = 0   /**< Clear the current line. */
    };

    // Enum for setting text colors
    enum TextColor {
        BLACK = 30,   /**< Black color. */
        RED = 31,     /**< Red color. */
        GREEN = 32,   /**< Green color. */
        YELLOW = 33,  /**< Yellow color. */
        BLUE = 34,    /**< Blue color. */
        MAGENTA = 35, /**< Magenta color. */
        CYAN = 36,    /**< Cyan color. */
        WHITE = 37    /**< White color. */
    };

    // Enum for setting background colors
    enum BackColor {
        B_BLACK = 40,   /**< Black background. */
        B_RED = 41,     /**< Red background. */
        B_GREEN = 42,   /**< Green background. */
        B_YELLOW = 43,  /**< Yellow background. */
        B_BLUE = 44,    /**< Blue background. */
        B_MAGENTA = 45, /**< Magenta background. */
        B_CYAN = 46,    /**< Cyan background. */
        B_WHITE = 47    /**< White background. */
    };

    // Enum for setting text formats
    enum TextFormat {
        RESET = 0,        /**< Reset all styles. */
        BOLD = 1,         /**< Bold text. */
        UNDERLINE = 4,    /**< Underlined text. */
        BLINK = 5,        /**< Blinking text. */
        STRIKETHROUGH = 9 /**< Strikethrough text. */
    };

    // Enum for key codes
    enum KeyCode {
        NONE,     /**< No key pressed. */
        UP,       /**< Up arrow key. */
        DOWN,     /**< Down arrow key. */
        LEFT,     /**< Left arrow key. */
        RIGHT,    /**< Right arrow key. */
        ESC,      /**< ESC key. */
        ENTER,    /**< Enter key. */
        SPACE,    /**< Space key. */
        OTHER,    /**< Other key. */
        HOME,     /**< Home key. */
        END,      /**< End key. */
        PAGE_UP,  /**< Page Up key. */
        PAGE_DOWN,/**< Page Down key. */
        INSERT,   /**< Insert key. */
        DELETE,   /**< Delete key. */
        F1,       /**< F1 key. */
        F2,       /**< F2 key. */
        F3,       /**< F3 key. */
        F4,       /**< F4 key. */
        F5,       /**< F5 key. */
        F6,       /**< F6 key. */
        F7,       /**< F7 key. */
        F8,       /**< F8 key. */
        F9,       /**< F9 key. */
        F10,      /**< F10 key. */
        F11,      /**< F11 key. */
        F12       /**< F12 key. */
    };

    /**
     * @brief Resets all terminal settings (colors, formats).
     */
    void reset();

    /**
     * @brief Clears the screen or the current line based on the target.
     * 
     * @param target The target to clear: screen (ALL) or line (LINE).
     */
    void clear(ClearTarget target);

    /**
     * @brief Sets the text color.
     * 
     * @param color The color of the text.
     */
    void setTextColor(TextColor color);

    /**
     * @brief Sets the text format.
     * 
     * @param format The text format (bold, underlined, etc.).
     */
    void setTextFormat(TextFormat format);

    /**
     * @brief Sets the background color.
     * 
     * @param color The color of the background.
     */
    void setBackgroundColor(BackColor color);

    /**
     * @brief Moves the cursor to a specific position.
     * 
     * @param x The row (y-coordinate).
     * @param y The column (x-coordinate).
     */
    void moveCursorTo(int x, int y);

    /**
     * @brief Moves the cursor to the start of the screen (position (0, 0)).
     */
    void moveCursorToZero();

    /**
     * @brief Moves the cursor up by one row.
     */
    void moveCursorUp();

    /**
     * @brief Moves the cursor down by one row.
     */
    void moveCursorDown();

    /**
     * @brief Moves the cursor left by one character.
     */
    void moveCursorLeft();

    /**
     * @brief Moves the cursor right by one character.
     */
    void moveCursorRight();

    /**
     * @brief Saves the current cursor position.
     */
    void saveCursorPosition();

    /**
     * @brief Restores the saved cursor position.
     */
    void restoreCursorPosition();

    /**
     * @brief Waits for a key press from the terminal and returns the corresponding key code.
     * 
     * @return The key code of the pressed key.
     */
    KeyCode getKey();
}

#endif // IASCREEN_HPP
