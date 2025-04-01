#ifndef IA_LEXER_HPP
#define IA_LEXER_HPP

#include "iaToken.hpp"
#include <vector>

/**
 * @brief Класс для лексического анализа.
 */
class iaLexer {
public:
    /**
     * @brief Лексический анализ строки кода.
     * @param code Исходный код.
     * @return std::vector<iaToken> Список токенов.
     */
    std::vector<iaToken> tokenize(const std::string& code);

private:
    /**
     * @brief Проверяет, является ли строка ключевым словом.
     * @param word Проверяемое слово.
     * @return true, если это ключевое слово, иначе false.
     */
    bool isKeyword(const std::string& word);
};

#endif // IA_LEXER_HPP
