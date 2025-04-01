#include "iaScreen.hpp"
#include <iostream>

int main() {
    iaS::clear(iaS::ALL);
    iaS::moveCursorTo(3, 15);
    iaS::setTextColor(iaS::RED);
    std::cout << "Это красный текст" << std::endl;

    iaS::setTextColor(iaS::GREEN);
    iaS::setTextFormat(iaS::BOLD);
    std::cout << "Это жирный зеленый текст" << std::endl;

    iaS::moveCursorTo(5, 0);
    iaS::setTextColor(iaS::WHITE);
    iaS::setBackgroundColor(iaS::B_BLUE);
    std::cout << "Это белый текст на синем фоне" << std::endl;
    iaS::reset();
    std::cout << "\nНажмите клавишу (ESC для выхода)..." << std::endl;
    bool running = true;
    while (running) {
        iaS::KeyCode key = iaS::getKey();
        switch (key) {
            case iaS::UP: {
                std::cout << "↑" << std::endl;
                iaS::moveCursorUp();
                break;
            } // UP
            case iaS::DOWN: {
                std::cout << "↓" << std::endl;
                iaS::moveCursorDown();
                break;
            } // DOWN
            case iaS::LEFT: {
                std::cout << "←" << std::endl;
                iaS::moveCursorLeft();  // Исправлено: добавлены скобки
                break;
            } // LEFT
            case iaS::RIGHT: {
                std::cout << "→" << std::endl;
                iaS::moveCursorRight();  // Исправлено: добавлены скобки
                break;
            } // RIGHT
            case iaS::F1: {
                std::cout << "F1" << std::endl;
                break;
            } // F1
            case iaS::F4: {
                std::cout << "F4" << std::endl;
                break;
            } // F4
            case iaS::ESC: {
                std::cout << "Выход..." << std::endl;
                running = false;
                break;
            } // ESC
            default: {
                break;
            } //default
        } // Switch
    } // While
    return 0;
} // main
