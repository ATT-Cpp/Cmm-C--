#include "../../../Include/includes.h"

void JumpBasedStatements::ParseBreakStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != "break") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
}

void JumpBasedStatements::ParseReturnStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != "return") {
        return;
    }

    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size()) {
        return;
    }

    const bool isValid = Compiler::tokens[static_cast<size_t> (i)].TokenType == Compiler::STRING ||
                         Compiler::tokens[static_cast<size_t> (i)].TokenType == Compiler::BOOL ||
                         Compiler::tokens[static_cast<size_t> (i)].TokenType == Compiler::CHAR ||
                         Compiler::tokens[static_cast<size_t> (i)].TokenType == Compiler::INT;
    if (!isValid) {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
}

void JumpBasedStatements::ParseContinueStatement(int &i) {
    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != "continue") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Compiler::tokens.size() ||
        Compiler::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
}
