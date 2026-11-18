#include "../../../Include/includes.h"

Helper help;
void FunctionDeclaration::ParseFunctionDeclaration(int& i) {
    if (!help.FindKeywords(i, "fn") ||
        !help.Universal(i, {true, true}) ||
        Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }

    Arguments = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, Compiler::tokens[static_cast<size_t> (i)].Value);
    ++i;
    ParseArguments(i);
    ParseFunctionBody(i);
}

void FunctionDeclaration::ParseFunctionBody(int& i) {
    if (!help.Universal(i, {true, true, true, "["})) {
        return;
    }

    ++i;

    VariableDeclaration variableDeclaration;
    ControlFlowStatement controlFlow;
    IterationStatement iteration;
    JumpBasedStatements jumpStatements;
    Enum enumDeclaration;
    Struct structDeclaration;
    int loopIndex = 0;

    while (help.Universal(i, {true, true}) &&
           !help.Universal(i, {true, true, true, "]"})) {
        const int previousIndex = i;
        const std::string& currentValue = Compiler::tokens[static_cast<size_t> (i)].Value;

        if (currentValue == "var") {
            variableDeclaration.ParseVarDecl(i);
        } else if (currentValue == "fn") {
            ParseFunctionDeclaration(i);
        } else if (currentValue == "enum") {
            enumDeclaration.ParseEnumDeclaration(i);
        } else if (currentValue == "struct") {
            structDeclaration.ParseStructDeclaration(i);
        } else if (currentValue == "if") {
            controlFlow.ParseIfStatement(i);
        } else if (currentValue == "else") {
            if (static_cast<size_t>(i) + 1 < Compiler::tokens.size() &&
                Compiler::tokens[static_cast<size_t>(i) + 1].Value == "if") {
                ++i;
                controlFlow.ParseIfStatement(i);
            } else {
                controlFlow.ParseElseStatement(i);
            }
        } else if (currentValue == "while") {
            iteration.ParseWhileStatement(i, loopIndex);
        } else if (currentValue == "for") {
            iteration.ParseForCondition(i, "");
        } else if (currentValue == "return") {
            jumpStatements.ParseReturnStatement(i);
        } else if (currentValue == "break") {
            jumpStatements.ParseBreakStatement(i);
        } else if (currentValue == "continue") {
            jumpStatements.ParseContinueStatement(i);
        } else if (currentValue == "[") {
            help.parseBlock(i);
        } else {
            ++i;
        }

        if (help.Universal(i, {true, true, true, "]"}) &&
            (currentValue == "if" || currentValue == "else" || currentValue == "while" ||
             currentValue == "[")) {
            ++i;
        }

        if (i <= previousIndex) {
            return;
        }
    }

    if (help.Universal(i, {true, true, true, "]"})) {
        ++i;
    }
}
void FunctionDeclaration::ParseArguments(int& i)
{
    if (!help.Universal(i, {true, true})) {
        return;
    }
    if (help.Universal(i, {false, false, true, "["})) {
        return;
    }
    if (!help.Universal(i, {false, false, true, "("})) {
        return;
    }
    ++i;

    if (!help.Universal(i, {true, true})) {
        return;
    }

    if (help.Universal(i, {false, false, true, ")"})) {
        ++i;
        return;
    }

    if (!help.Universal(i, {false, false, true, "var"})) {
        return;
    }

    ParseVariableDeclFunc(i);

    if (!help.Universal(i, {false, false, true, ")"})) {
        return;
    }
    ++i;

}

void FunctionDeclaration::ParseVariableDeclFunc(int& i)
{
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if (!help.Universal(i, {false, false, true, "var"})) {
        return;
    }
    ++i;

    if (!help.Universal(i, {true, true})) {
        return;
    }

    const bool isType =
        help.Universal(i, {false, false, true, "auto"}) ||
        help.Universal(i, {false, false, true, "int"}) ||
        help.Universal(i, {false, false, true, "bool"}) ||
        help.Universal(i, {false, false, true, "string"}) ||
        help.Universal(i, {false, false, true, "char"});
    if (!isType) {
        return;
    }

    VariableDeclFunc.Type = ASTnode::DATA_TYPES;
    ++i;

    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if (Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }

    VariableDeclFunc.Value = Compiler::tokens[static_cast<size_t> (i)].Value;
    ++i;
}
