#include "../../../Include/includes.h"

void JumpBasedStatements::ParseBreakStatement(int &i) {
    BreakStatementNode = ASTnode::MakeNode(ASTnode::BREAK_STATEMENT, "");
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != "break") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
    BreakStatementNode.Value = "break";
}

void JumpBasedStatements::ParseReturnStatement(int &i) {
    ReturnStatementNode = ASTnode::MakeNode(ASTnode::RETURN_STATEMENT, "");
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != "return") {
        return;
    }

    ++i;
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size()) {
        return;
    }

    const bool isValid = Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::STRING ||
                         Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::BOOL ||
                         Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::CHAR ||
                         Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::INT ||
                         Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::DOUBLE ||
                         Lexer::tokens[static_cast<size_t> (i)].TokenType == Lexer::IDENTIFIER;
    if (Lexer::tokens[static_cast<size_t> (i)].Value == ";") {
        ++i;
        ReturnStatementNode.Value = "return";
        return;
    }
    if (!isValid) {
        return;
    }
    const std::string returnValue = Lexer::tokens[static_cast<size_t> (i)].Value;
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
    ReturnStatementNode.Value = "return";
    ReturnStatementNode.Children.push_back(ASTnode::MakeNode(ASTnode::DATA_TYPES, returnValue));
}

void JumpBasedStatements::ParseContinueStatement(int &i) {
    ContinueStatementNode = ASTnode::MakeNode(ASTnode::CONTINUE_STATEMENT, "");
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != "continue") {
        return;
    }
    ++i;

    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size() ||
        Lexer::tokens[static_cast<size_t> (i)].Value != ";") {
        return;
    }
    ++i;
    ContinueStatementNode.Value = "continue";
}
