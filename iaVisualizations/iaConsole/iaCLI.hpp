/**
 * @file iaCLI.hpp
 * @brief Заголовочный файл для работы с окнами и символами рамки в CLI.
 * Содержит функции для рисования окон с углами, границами и установкой цветов.
 * 
 * @author Your Name
 * @date March 2025
 */

#ifndef IACLI_HPP
#define IACLI_HPP

#include "iaScreen.hpp"  // Подключаем iaScreen.hpp для использования TextColor, BackColor и других функций
#include <iostream>

// Символы для рисования окон
/**
 * @def VERTICAL_DOUBLE
 * @brief Символ для вертикальной границы окна.
 */
#define VERTICAL_DOUBLE "║"

/**
 * @def HORIZONTAL_DOUBLE
 * @brief Символ для горизонтальной границы окна.
 */
#define HORIZONTAL_DOUBLE "═"

/**
 * @def TOP_LEFT_CORNER
 * @brief Символ для верхнего левого угла окна.
 */
#define TOP_LEFT_CORNER "╔"

/**
 * @def TOP_RIGHT_CORNER
 * @brief Символ для верхнего правого угла окна.
 */
#define TOP_RIGHT_CORNER "╗"

/**
 * @def BOTTOM_LEFT_CORNER
 * @brief Символ для нижнего левого угла окна.
 */
#define BOTTOM_LEFT_CORNER "╚"

/**
 * @def BOTTOM_RIGHT_CORNER
 * @brief Символ для нижнего правого угла окна.
 */
#define BOTTOM_RIGHT_CORNER "╝"

/**
 * @def CROSS
 * @brief Символ для центрального пересечения границ окна.
 */
#define CROSS "╬"

/**
 * @def T_LEFT
 * @brief Символ для левой границы T-образного соединения.
 */
#define T_LEFT "╠"

/**
 * @def T_RIGHT
 * @brief Символ для правой границы T-образного соединения.
 */
#define T_RIGHT "╣"

/**
 * @def T_TOP
 * @brief Символ для верхней границы T-образного соединения.
 */
#define T_TOP "╦"

/**
 * @def T_BOTTOM
 * @brief Символ для нижней границы T-образного соединения.
 */
#define T_BOTTOM "╩"


// Прототипы функций
void initWindow(iaS::TextColor tColor, iaS::BackColor bColor, int x0, int y0, int width, int height);
void drawCorners(int x0, int y0, int width, int height);
void drawWindow(int xS, int yS, int width, int height);

#endif // IACLI_HPP
