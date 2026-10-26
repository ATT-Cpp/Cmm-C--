    #include "lexer.h"
    #include "Helper/helper.h"
    #include<vector>
    #include<iostream>
    #include<cctype>
    #include <string>
    
    void Compiler::Lexer(std::string& input) {
        std::string currentWord;
        char currentSchar;
        int i = 0;
        
        for(int i = 0; i < input.size(); ++i) {
            currentSchar = input[i];
            if(isspace(currentSchar)) {
                continue;
            }
                    currentWord += input[i];
            if(std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end()) {
                tokens.push_back({KEYWORD, currentWord});
                currentWord.clear();
            }
            if(std::find(Symbol.begin(), Symbol.end(), currentWord) != Symbol.end()) {
                tokens.push_back({SYMBOLS, currentWord});
                    currentWord.clear();
            }
            if(currentSchar == '"') {
    std::string word;

    ++i;
    currentSchar = input[i];

    while(i < input.size() && currentSchar != '"') {

        word += currentSchar;

        ++i;

        if(i < input.size())
            currentSchar = input[i];
    }

    --i;
    --i;

    tokens.push_back({STRING, word});
    currentWord.clear();
}
            if(currentSchar == '\'') {
    std::string word1;

    ++i;
    currentSchar = input[i];

    while(i < input.size() && currentSchar != '\'') {

        word1 += currentSchar;

        ++i;

        if(i < input.size())
            currentSchar = input[i];
    }

    --i;
    --i;

    tokens.push_back({CHAR, word1});
    currentWord.clear();
}
            if(isdigit(currentSchar)) {
    std::string currentWord2;

    while(i < input.size() && isdigit(input[i])) {

        currentSchar = input[i];
        currentWord2 += currentSchar;

        ++i;
    }

    --i;
    --i;

    tokens.push_back({INT, currentWord2});
    currentWord.clear();
}
if(currentWord == "true" || currentWord == "false") {

    tokens.push_back({BOOL, currentWord});
    currentWord.clear();
}
        }
    };
    
    
          
