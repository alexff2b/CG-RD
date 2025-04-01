#include "iaLexer.hpp"
#include <cctype>
#include <sstream>

const std::vector<std::string> keywords = {"int", "return", "if", "else", "begin", "end"};

bool iaLexer::isKeyword(const std::string& word) {
    for (const auto& keyword : keywords) {
        if (word == keyword) return true;
    }
    return false;
}

std::vector<iaToken> iaLexer::tokenize(const std::string& code) {
    std::vector<iaToken> tokens;
    std::istringstream stream(code);
    std::string word;

    while (stream >> word) {
        if (isKeyword(word)) {
            tokens.emplace_back(iaToken::KEYWORD, word);
        } else if (std::isdigit(word[0])) {
            tokens.emplace_back(iaToken::NUMBER, word);
        } else {
            tokens.emplace_back(iaToken::IDENTIFIER, word);
        }
    }

    return tokens;
}
