#include "../../Include/includes.h"



void Compiler::Lexer(const std::string& input, size_t& i) {
    Compiler c;
    char currentSchar;
    std::string currentWord;



    if(i >= input.size()) {
        return;
    }

    while (i < input.size()) {
    if(i < input.size() && isspace(static_cast<unsigned char> (currentSchar))) {
        ++i;
        continue;
    }
    currentWord += input[i];
    currentSchar = input[i];

    c.keywords(input, i);
    c.Symbols(input, i);
    if (currentSchar == '"') {
        c.ParseString(input, i);
    } else if (currentSchar == '\'') {
        c.ParseChar(input, i);
    } else if (std::isdigit(static_cast<unsigned char>(currentSchar))) {
        c.ParseInt(input, i);
    }
    }
}