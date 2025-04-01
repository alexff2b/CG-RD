#include "iaToken.hpp"

iaToken::iaToken(TokenType type, std::string value) : type(type), value(value) {}

std::string iaToken::getTypeString() const {
    switch (type) {
        case KEYWORD: return "KEYWORD";
        case IDENTIFIER: return "IDENTIFIER";
        case NUMBER: return "NUMBER";
        case OPERATOR: return "OPERATOR";
        case DELIMITER: return "DELIMITER";
        case SPECIAL: return "SPECIAL";
        case STRING: return "STRING";
        case CHAR: return "CHAR";
        case UNKNOWN: return "UNKNOWN";
        default: return "UNKNOWN";
    }
}
