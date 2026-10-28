#include"helper.h"
#include"ASTnode.h"
#include"lexer.h"
#include<iostream>
#include<string>
#include<vector>

bool Helper::FindType(int& i, TokenType type) {
    if(tokens[i].type != type) {
        ++i;
        return false;
    }
    ++i;
    return false;
}

bool Helper::FindKeywords(int& i, std::string expected) {
    if(tokens[i].Value != expected) {
        ++i;
        return false;
    }
    ++i;
    return true;
}
bool Helper::FindSymbol(int& i, std::string expected) {
    if(expect != ">" || expected != "<" || expected != ">=" || expected != "<=" || expected != "!=") {
        ++i;
        return false;
    }
    ++i;
    return true;
}

Node Helper::parseCondition(int& i) {
    Node ConditionNode;
    if(FindType(i, LPARENTHESES)) {
        while(!FindType(i, RPARENTHESES)) {
            if(FindType(i, IDENTIFIER)) {
                Node Left;
                Left.Type = IDENTIFIER;
                Left.value = tokens[i];
            }
            if(FindSymbol(i, "))
        }
    }
}

    }
}

    }
}
