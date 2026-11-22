#include "../../../Include/includes.h"

Helper help;
void FunctionDeclaration::ParseFunctionDeclaration(int& i) {
    if (!help.FindKeywords(i, "fn") ||
        !help.Universal(i, {true, true}) ||
        Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    FunctionName = ASTnode::MakeNode(
        ASTnode::FUNCTION_NAME, Lexer::tokens[static_cast<size_t> (i)].Value);
    Arguments = ASTnode::MakeNode(ASTnode::FUNCTION_ARGS, "");
    FunctionBody = ASTnode::MakeNode(ASTnode::FUNCTION_BODY, "");
    ++i;
    if(!help.Universal(i, {true, true})) {
        return;
    }
    ParseArguments(i);

    FunctionDeclarationNode.Children.push_back(FunctionName);
    FunctionDeclarationNode.Children.push_back(Arguments);
    ParseFunctionBody(i);
    FunctionDeclarationNode.Children.push_back(FunctionBody);
}

void FunctionDeclaration::ParseFunctionBody(int& i) {
    if (!help.Universal(i, {true, true, true, "["})) {
        return;
    }

    ++i;

    ControlFlowStatement controlFlow;
    JumpBasedStatements jumpStatements;
    Enum enumDeclaration;
    Struct structDeclaration;
    int loopIndex = 0;

    while (help.Universal(i, {true, true}) &&
           !help.Universal(i, {true, true, true, "]"})) {
        const int previousIndex = i;
        const std::string& currentValue = Lexer::tokens[static_cast<size_t> (i)].Value;

        if (currentValue == "var") {
            VariableDeclaration variableDeclaration;
            variableDeclaration.ParseVarDecl(i);
            FunctionBody.Children.push_back(variableDeclaration.VariableDeclarationNode);
        } else if (currentValue == "fn") {
            ParseFunctionDeclaration(i);
        } else if (currentValue == "enum") {
            enumDeclaration.ParseEnumDeclaration(i);
            if (!enumDeclaration.EnumNode.Children.empty()) {
                FunctionBody.Children.push_back(enumDeclaration.EnumNode);
            }
        } else if (currentValue == "struct") {
            structDeclaration.ParseStructDeclaration(i);
            if (!structDeclaration.StructNode.Children.empty()) {
                FunctionBody.Children.push_back(structDeclaration.StructNode);
            }
        } else if (currentValue == "if") {
            controlFlow.ParseIfStatement(i);
            FunctionBody.Children.push_back(controlFlow.ControlFlowStatementNode);
        } else if (currentValue == "else") {
            if (static_cast<size_t>(i) + 1 < Lexer::tokens.size() &&
                Lexer::tokens[static_cast<size_t>(i) + 1].Value == "if") {
                ++i;
                controlFlow.ParseIfStatement(i);
                controlFlow.ControlFlowStatementNode.Value = "else if";
            } else {
                controlFlow.ParseElseStatement(i);
            }
            FunctionBody.Children.push_back(controlFlow.ControlFlowStatementNode);
        } else if (currentValue == "while") {
            IterationStatement iteration;
            iteration.ParseWhileStatement(i, loopIndex);
            FunctionBody.Children.push_back(iteration.WhileStatementNode);
        } else if (currentValue == "for") {
            IterationStatement iteration;
            iteration.ParseForCondition(i, "");
            FunctionBody.Children.push_back(iteration.ForStatementNode);
        } else if (currentValue == "return") {
            jumpStatements.ParseReturnStatement(i);
            if (jumpStatements.ReturnStatementNode.Value == "return") {
                FunctionBody.Children.push_back(jumpStatements.ReturnStatementNode);
            }
        } else if (currentValue == "break") {
            jumpStatements.ParseBreakStatement(i);
            if (jumpStatements.BreakStatementNode.Value == "break") {
                FunctionBody.Children.push_back(jumpStatements.BreakStatementNode);
            }
        } else if (currentValue == "continue") {
            jumpStatements.ParseContinueStatement(i);
            if (jumpStatements.ContinueStatementNode.Value == "continue") {
                FunctionBody.Children.push_back(jumpStatements.ContinueStatementNode);
            }
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
    Arguments.Children.push_back(VariableDeclFunc);
    ++i;

}

void FunctionDeclaration::ParseVariableDeclFunc(int& i)
{
    VariableDeclFunc = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");

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

    const std::string typeValue = Lexer::tokens[static_cast<size_t> (i)].Value;
    VariableDeclFunc.Type = ASTnode::DATA_TYPES;
    VariableDeclFunc.Children.push_back(ASTnode::MakeNode(ASTnode::DATA_TYPES, typeValue));
    ++i;

    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if (Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }

    VariableDeclFunc.Value = Lexer::tokens[static_cast<size_t> (i)].Value;
    ++i;
}
