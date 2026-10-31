#include"../../Include/includes.h"

Helper help;
void ControlFlowStatement::ParseIfStatement(int& i, int& b) {
    if(help.FindKeywords(i, "if")) {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseStatement(int& i, int& b) {
    if(help.FindKeywords(i, "else")) {
        help.parseBlock(i);
    }
}

void ControlFlowStatement::ParseElseIfStatement(int& i, int& b) {
    if(help.FindKeywords(i, "else if")) {
        help.parseCondition(i);
        help.parseBlock(i);
    }
}