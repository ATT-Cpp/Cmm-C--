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
        if(std::find(keywords.begin(), keywords.end(), currentWord) != keywords.end()) {
            tokens.push_back({KEYWORD, currentWord});
            currentWord.clear();
        }
        if(std::find(Symbol.begin(), Symbol.end(), currentWord) != Symbol.end()) {
            tokens.push_back({SYMBOLS, currentWord})
                currentWord.clear();
        }

        if(currentSchar == '"') {
            std::string word;
            while(i < input.size() && input[i] != '"') {
                word += input[i];
                ++i;
                tokens.push_back({STRING, word1})
                currentWord.clear();
            }
         }
        --i;

        if(currentSchar == '\'') {
            std::string word1;
            while(i < input.size() && currentSchar != '\0') {
                word1+=input[i];
                ++i;
                tokens.push_back({Char, word1});
            currentWord.clear();
            }
        }
        --i;

        if(isdigit(currentSchar)) {
            std::string currentWord2;
            while(i < input.size() && isdigit(input[i])) {
                currentWord2 += input[i];
                ++i;
                tokens.push_back({INT, currentWord2})
                    currentWord.clear();
            }
        }
        --i;

        if(currentWord == "true" || currentWord == "false") {
            std::string ToF;
            while(i < input.size() &&
            (currentWord == "true" || currentWord == "false")) {
                ToF += input[i];
                ++i;
                tokens.push_back({BOOL, CurrentWord});
                currentWord.clear();
            }
        }
        --i;
    }
};


      
