#include"helper.h"
#include "Lexer/lexer.h"
#include<iostream>
#include<string>
#include<vector>

bool Helper::FindType(int& i, Compiler::Token type) {
    if(Compiler::tokens[i].TokenType != type) {
        return false;
    }
    ++i;
    return true;
}

bool Helper::FindKeywords(int& i, std::string expected) {
    if(Compiler::tokens[i].Value != expected) {
        return false;
    }
    ++i;
    return true;
} 
ASTnode::Node Helper::parseCondition(int& i) {
    ASTnode::Node ConditionNode{};
    ASTnode::Node Left{};
    ASTnode::Node Operator{};
    ASTnode::Node Right{};
    ASTnode::Node LogicGates{};
    if(Compiler::Symbol[i] == "(") {
        while(Compiler::tokens[i].Value != ")") {
            if(FindType(i, Compiler::IDENTIFIER)) {
                Left.Type = ASTnode::IDENTIFIER;
                Left.Value = Compiler::tokens[i].Value;
            }
            if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
                Operator.Type = ASTnode::OPERATOR;
                Operator.Value = Compiler::tokens[i].Value;

            }
            if(FindType(i, Compiler::IDENTIFIER)) {
                Right.Type = ASTnode::IDENTIFIER;
                Right.Value = Compiler::tokens[i].Value;
            }
            ASTnode::Node LogicGates{};
            if(Compiler::Symbol[i] == "&&" || Compiler::Symbol[i] == "||") {
                LogicGates.Type = ASTnode::ANDOR;
                LogicGates.Value = Compiler::tokens[i].Value;
            }
            while(Compiler::Symbol[i] == "&&" || Compiler::Symbol[i] == "||") { {
                if(FindType(i, Compiler::IDENTIFIER)) {
                    Left.Type = ASTnode::IDENTIFIER;
                    Left.Value = Compiler::tokens[i].Value;
                }
                if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
                    Operator.Type = ASTnode::OPERATOR;
                    Operator.Value = Compiler::tokens[i].Value;

                }
                if(FindType(i, Compiler::IDENTIFIER)) {
                    Right.Type = ASTnode::IDENTIFIER;
                    Right.Value = Compiler::tokens[i].Value;
                }
            }
            
            
        }
    }
    ConditionNode.Children.push_back(Left);
    ConditionNode.Children.push_back(Operator);
    ConditionNode.Children.push_back(Right);
    ConditionNode.Children.push_back(LogicGates);
    return ConditionNode;
}
}




    
