#include"helper.h"
#include"ASTnode.h"
#include"lexer.h"
#include<iostream>
#include<string>
#include<vector>

bool Helper::FindType(int& i, TokenType type) {
    if(tokens[i].type != type) {
        return false;
    }
    ++i;
    return true;
}

bool Helper::FindKeywords(int& i, std::string expected) {
    if(tokens[i].Value != expected) {
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
                Left.Value = tokens[i];
            }
            if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKEywords(">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
            Node Operator;
                Operator.Type = OPERATOR;
                Operator.Value = tokens[i].Value;

            }
            if(FindType(i, IDENTIFIER)) {
                Node Right;
                Right.Type = IDENTIFIER;
                Right.Value = tokens[i].Value;
            }
            Node LogicGates;
            if(FindType(i, AND) || FindType(i,OR)) {
                LogicGates.Type = ANDOR;
                LogicGates.Value = tokens[i].Value;
            }
            while(FindType(i, AND) || FindType(i, OR)) {
                if(FindType(i, IDENTIFIER)) {
                    Node Left;
                    Left.Type = IDENTIFIER;
                    Left.Value = tokens[i].Value;
                }
                if(FindKeywords(i, ">") || FindKeywords(i, "<") || FindKeywords(i, ">=") || FindKeywords(i, "<=") || FindKeywords(i, "==")|| FindKeywords(i, "!=")) {
                    Node Operator;
                    Operator.Type = OPERATOR;
                    Operator.Value = tokens[i].Value;

                }
                if(FindType(i, IDENTIFIER)) {
                    Node Right;
                    Right.Type = IDENTIFIER;
                    Right.Value = tokens[i].Value;
                }
            }
            
            
        }
    }
}




    

