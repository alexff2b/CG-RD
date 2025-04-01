#ifndef IA_TOKEN_HPP
#define IA_TOKEN_HPP

#include <string>

/**
 * @brief Класс, представляющий токен.
 */
class iaToken {
public:
    enum TokenType {
        KEYWORD,
        IDENTIFIER,
        NUMBER,
        OPERATOR,
        DELIMITER,
        SPECIAL,
        STRING,
        CHAR,
        UNKNOWN
    };

    TokenType type;  ///< Тип токена
    std::string value; ///< Значение токена

    /**
     * @brief Конструктор токена.
     * @param type Тип токена.
     * @param value Значение токена.
     */
    iaToken(TokenType type, std::string value);

    /**
     * @brief Метод для получения строкового представления типа токена.
     * @return std::string
     */
    std::string getTypeString() const;
};

#endif // IA_TOKEN_HPP
