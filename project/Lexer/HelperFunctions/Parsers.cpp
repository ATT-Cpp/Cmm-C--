#include "../../Include/includes.h"

void Compiler::ParseString(const std::string& input, size_t& i) {
    if (i >= input.size() || input[i] != '"') {
        return;
    }

    std::string word;
    ++i;

    while (i < input.size() && input[i] != '"') {
        word += input[i];
        ++i;
    }

    if (i < input.size()) {
        Compiler::tokens.push_back({Compiler::STRING, word});
        ++i;
    }
}

void Compiler::ParseInt(const std::string& input, size_t& i) {
    if (i >= input.size() || !std::isdigit(static_cast<unsigned char>(input[i]))) {
        return;
    }

    std::string currentWord;
    while (i < input.size() &&
           std::isdigit(static_cast<unsigned char>(input[i]))) {
        currentWord += input[i];
        ++i;
    }

    Compiler::tokens.push_back({Compiler::INT, currentWord});
}
