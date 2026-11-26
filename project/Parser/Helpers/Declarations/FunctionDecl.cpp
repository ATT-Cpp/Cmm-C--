#include "../../../Include/includes.h"

Helper help;
void FunctionDeclaration::ParseFunctionDeclaration(int& i) {
    FunctionDeclarationNode = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, "");
    FunctionName = ASTnode::MakeNode(ASTnode::FUNCTION_NAME, "");
    ReturnType = ASTnode::MakeNode(ASTnode::TYPE, "");
    Arguments = ASTnode::MakeNode(ASTnode::FUNCTION_ARGS, "");
    FunctionBody = ASTnode::MakeNode(ASTnode::FUNCTION_BODY, "");

    if (!help.FindKeywords(i, "fn") ||
        !help.Universal(i, {true, true}) ||
        Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    FunctionName = ASTnode::MakeNode(
        ASTnode::FUNCTION_NAME, Lexer::tokens[static_cast<size_t> (i)].Value);
    ++i;
    if (!ParseArguments(i)) {
        return;
    }

    if (help.FindKeywords(i, "->")) {
        if (!help.Universal(i, {true, true})) {
            return;
        }

        const std::string& typeValue = Lexer::tokens[static_cast<size_t>(i)].Value;
        std::string typeName;
        if (typeValue == "int") {
            typeName = "INT";
        } else if (typeValue == "double") {
            typeName = "DOUBLE";
        } else if (typeValue == "bool") {
            typeName = "BOOL";
        } else if (typeValue == "char") {
            typeName = "CHAR";
        } else if (typeValue == "string") {
            typeName = "STRING";
        } else if (typeValue == "void") {
            typeName = "VOID";
        } else if (typeValue == "auto") {
            typeName = "AUTO";
        } else {
            return;
        }
        ReturnType = ASTnode::MakeNode(ASTnode::TYPE, typeName);
        ++i;
    }

    if (!ParseFunctionBody(i)) {
        return;
    }

    FunctionDeclarationNode.Children.push_back(FunctionName);
    if (!ReturnType.Value.empty()) {
        FunctionDeclarationNode.Children.push_back(ReturnType);
    }
    FunctionDeclarationNode.Children.push_back(Arguments);
    FunctionDeclarationNode.Children.push_back(FunctionBody);
}

bool FunctionDeclaration::ParseFunctionBody(int& i) {
    if (!help.Universal(i, {true, true, true, "["})) {
        return false;
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
            if (variableDeclaration.VariableDeclarationNode.Children.size() >= 3) {
                FunctionBody.Children.push_back(variableDeclaration.VariableDeclarationNode);
            }
        } else if (currentValue == "fn") {
            FunctionDeclaration nestedFunction;
            nestedFunction.ParseFunctionDeclaration(i);
            if (nestedFunction.FunctionDeclarationNode.Children.size() >= 3) {
                FunctionBody.Children.push_back(nestedFunction.FunctionDeclarationNode);
            }
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
            if (!controlFlow.ControlFlowStatementNode.Value.empty()) {
                FunctionBody.Children.push_back(controlFlow.ControlFlowStatementNode);
            }
        } else if (currentValue == "else") {
            if (static_cast<size_t>(i) + 1 < Lexer::tokens.size() &&
                Lexer::tokens[static_cast<size_t>(i) + 1].Value == "if") {
                ++i;
                controlFlow.ParseIfStatement(i);
                if (!controlFlow.ControlFlowStatementNode.Value.empty()) {
                    controlFlow.ControlFlowStatementNode.Value = "else if";
                }
            } else {
                controlFlow.ParseElseStatement(i);
            }
            if (!controlFlow.ControlFlowStatementNode.Value.empty()) {
                FunctionBody.Children.push_back(controlFlow.ControlFlowStatementNode);
            }
        } else if (currentValue == "while") {
            IterationStatement iteration;
            iteration.ParseWhileStatement(i, loopIndex);
            if (!iteration.WhileStatementNode.Value.empty()) {
                FunctionBody.Children.push_back(iteration.WhileStatementNode);
            }
        } else if (currentValue == "for") {
            IterationStatement iteration;
            iteration.ParseForCondition(i, "");
            if (!iteration.ForStatementNode.Value.empty()) {
                FunctionBody.Children.push_back(iteration.ForStatementNode);
            }
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
            FunctionBody.Children.push_back(help.parseBlock(i));
        } else {
            ++i;
        }

        if (i <= previousIndex) {
            return false;
        }
    }

    if (help.Universal(i, {true, true, true, "]"})) {
        ++i;
        return true;
    }
    return false;
}
bool FunctionDeclaration::ParseArguments(int& i)
{
    if (!help.Universal(i, {true, true})) {
        return false;
    }
    if (help.Universal(i, {false, false, true, "["})) {
        return true;
    }
    if (help.Universal(i, {false, false, true, "->"})) {
        return true;
    }
    if (!help.Universal(i, {false, false, true, "("})) {
        return false;
    }
    ++i;

    if (help.Universal(i, {false, false, true, ")"})) {
        ++i;
        return true;
    }

    while (true) {
        if (!help.Universal(i, {false, false, true, "var"})) {
            return false;
        }

        ParseVariableDeclFunc(i);
        if (VariableDeclFunc.Value.empty()) {
            return false;
        }
        Arguments.Children.push_back(VariableDeclFunc);

        if (help.FindKeywords(i, ",")) {
            continue;
        }
        if (help.FindKeywords(i, ")")) {
            return true;
        }
        return false;
    }
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
        help.Universal(i, {false, false, true, "double"}) ||
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
