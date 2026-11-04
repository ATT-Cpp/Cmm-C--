#include "../../Include/includes.h"

void Compiler::keywords(const std::string& input, size_t& i) {
    std::string currentWord;
    if(i >= input.size()) {
        std::cerr << "Error Tokenizing";
        return;
    }
    while(i < input.size() &&(std::isalnum(static_cast<unsigned char>(input[i])) || input[i] == '_')) {
        currentWord+=input[i];
        ++i;
    }
    bool isSymbol = std::find(Compiler::Symbol.begin(), Compiler::Symbol.end(), currentWord)
        != Compiler::Symbol.end();

    if (!currentWord.empty() && !isSymbol) {
        if (std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end()) {
            Compiler::tokens.push_back({KEYWORD, currentWord});
        } else {
            Compiler::tokens.push_back({Compiler::IDENTIFIER, currentWord});
        } 
    }
}