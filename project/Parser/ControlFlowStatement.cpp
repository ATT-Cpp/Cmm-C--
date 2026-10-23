#include "ASTnode.h"
#include "parser.h"
#include "helper.h"
#include "lexer.h"
// otherfiles classes add here
Helper help;
//end
void ControlFlowStatement::ParseIfStatement(int& i, int& b) {
    if(help.FindKeywords(i, "if")) {
        help.parseCondition(i, b);
        help.parseBlock(i, b);
    }
}

void ControlFlowStatement::ParseElseStatement(int& i, int& b) {
    if(help.FindKeywords(i, "else")) {
        help.parseBlock(i, b);
    }
}

void ControlFlowStatement::ParseElseIfStatement(int& i, int& b) {
    if(help.FindKeywords(i, "else if")) {
        help.parseCondition(i, b);
        help.parseBlock(i, b);
    }
}