#include "lexer.h"
#include "Helper/helper.h"
#include <algorithm>
#include<vector>
#include<iostream>
#include<cctype>
#include <string>
void Compiler::Lexer(std::string input) {
    std::string currentWord;
    char currentSchar;
    int i = 0;

    for(int i = 0; i < input.size(); ++i) {

        currentSchar = input[i];
        const bool isSymbol = std::find(Symbol.begin(), Symbol.end(), std::string(1, currentSchar)) != Symbol.end();
        if(!isspace(currentSchar) && !isSymbol) {
            currentWord += currentSchar;
        }
        else {
            if(std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end()) {
                tokens.push_back({KEYWORD, currentWord});
            }
            else if(std::find(Symbol.begin(), Symbol.end(), currentWord) != Symbol.end()) {
                tokens.push_back({SYMBOLS, currentWord});
            }
            else if(!currentWord.empty()) {
                tokens.push_back({IDENTIFIER, currentWord});
            }
            currentWord.clear();
            if(isSymbol) {
                tokens.push_back({SYMBOLS, std::string(1, currentSchar)});
            }
        }



        if(currentSchar == '"') {
            std::string word;

            ++i;

            while(i < input.size() && input[i] != '"') {
                word += input[i];
                ++i;
            }

            tokens.push_back({STRING, word});
            currentWord.clear();
        }

        if(currentSchar == '\'') {
            std::string word1;

            ++i;

            while(i < input.size() && input[i] != '\'') {

                word1 += input[i];

                ++i;

                if(i < input.size())
                    currentSchar = input[i];
            }
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
            tokens.push_back({INT, currentWord2});
            currentWord.clear();
            --i;
        }
        if(currentWord == "true" || currentWord == "false") {

            tokens.push_back({BOOL, currentWord});
            currentWord.clear();
            currentWord += input[i];
        }

    }

    if(std::find(Keywords.begin(), Keywords.end(), currentWord) != Keywords.end()) {
        tokens.push_back({KEYWORD, currentWord});
    }
    else if(std::find(Symbol.begin(), Symbol.end(), currentWord) != Symbol.end()) {
        tokens.push_back({SYMBOLS, currentWord});
    }
    else if(!currentWord.empty()) {
        tokens.push_back({IDENTIFIER, currentWord});
    }
}
