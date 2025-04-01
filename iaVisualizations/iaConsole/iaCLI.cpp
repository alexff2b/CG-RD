#include "iaCLI.hpp"

void drawCorners(int x0, int y0, int width, int height) {
    // Рисуем верхний левый угол
    iaS::moveCursorTo(x0, y0);
    std::cout << TOP_LEFT_CORNER;

    // Рисуем верхний правый угол
    iaS::moveCursorTo(x0 + width + 1, y0);
    std::cout << TOP_RIGHT_CORNER;

    // Рисуем нижний левый угол
    iaS::moveCursorTo(x0, y0 + height);
    std::cout << BOTTOM_LEFT_CORNER;

    // Рисуем нижний правый угол
    iaS::moveCursorTo(x0 + width, y0 + height);
    std::cout << BOTTOM_RIGHT_CORNER;
}
/*
void drawHbord(int x0, int y0,int width, int height) {
	for (int i = 0; i < width; i++) {
		iaS::MoveCursorTo(x0 + i , y0);

		std::cout << HORIZONTAL_DOUBLE;
	
		std::
	}


}
*/

void initWindow(iaS::TextColor tColor, iaS::BackColor bColor, int x0, int y0, int width, int height) {
    iaS::reset();
    iaS::clear(iaS::ALL);  // Очищаем экран
    iaS::setTextColor(tColor);  // Устанавливаем цвет текста
    iaS::setBackgroundColor(bColor);  // Устанавливаем цвет фона
    iaS::setTextFormat(iaS::BOLD);  // Устанавливаем формат текста (жирный)
  //  drawWindow();

    drawCorners(x0, y0, width, height);
}

void drawWindow(int xS, int yS, int width, int height) {
    iaS::clear(iaS::ALL);  // Очищаем экран
    drawCorners(xS, yS, width, height);
}
