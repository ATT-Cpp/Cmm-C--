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
    if(Compiler::tokens[i].Value == "(") {
        while(Compiler::tokens[i].Value != ")") {
            ++i;
            const std::string tokenValue = Compiler::tokens[i].Value;
            if(FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) || FindType(i, Compiler::IDENTIFIER)) { // check identifier
                Left.Type = ASTnode::DATA_TYPES;
                Left.Value = tokenValue;
            }
            const std::string operatorValue = Compiler::tokens[i].Value;
            if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
                Operator.Type = ASTnode::OPERATOR;
                Operator.Value = operatorValue;

            }
            const std::string rightValue = Compiler::tokens[i].Value;
            if(FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) || FindType(i, Compiler::IDENTIFIER)) { //check identifier
                Right.Type = ASTnode::DATA_TYPES;
                Right.Value = rightValue;
            }
            if(Compiler::tokens[i].Value == "&&" || Compiler::tokens[i].Value == "||") {
                LogicGates.Type = ASTnode::ANDOR;
                LogicGates.Value = Compiler::tokens[i].Value;
            }
            while(Compiler::tokens[i].Value == "&&" || Compiler::tokens[i].Value == "||") {
                ++i;
                const std::string tokenValue = Compiler::tokens[i].Value;
                if(FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) || FindType(i, Compiler::IDENTIFIER)) { // check identifier
                    Left.Type = ASTnode::DATA_TYPES;
                    Left.Value = tokenValue;
                }
                const std::string operatorValue = Compiler::tokens[i].Value;
                if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
                    Operator.Type = ASTnode::OPERATOR;
                    Operator.Value = operatorValue;

                }
                const std::string rightValue = Compiler::tokens[i].Value;
                if(FindType(i, Compiler::INT) || FindType(i, Compiler::STRING) || FindType(i, Compiler::BOOL) || FindType(i, Compiler::IDENTIFIER)) { //check identifier
                    Right.Type = ASTnode::DATA_TYPES;
                    Right.Value = rightValue;
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

ASTnode::Node Helper::parseBlock(int& i)  { //finish

    if(Compiler::tokens[i].Value == "[") {
        
        while(Compiler::tokens[i].Value != "]") {
            
            ++i;
            if(Compiler::tokens[i].Value  == "if") {
                Helper helper { };
                helper.parseCondition(i);
            }
            if(Compiler::tokens[i].Value == "while") {
                Helper helper {};
                helper.parseCondition(i);
            }
            //Place holder for future statements
        }
    }
    

}




    
