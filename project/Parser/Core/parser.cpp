#include "../../Include/includes.h"

void Parser::parser(int& i) {
    if (i < 0 || static_cast<size_t>(i) >= Lexer::tokens.size())
    {
        return;
    }

    const int previousIndex = i;
    const std::string currentValue = Lexer::tokens[static_cast<size_t>(i)].Value;

    if (currentValue == "var")
    {
        VariableDeclaration declaration;
        declaration.ParseVarDecl(i);
        if (declaration.VariableDeclarationNode.Children.size() >= 3)
        {
            Program.Children.push_back(declaration.VariableDeclarationNode);
        }
    }
    else if (currentValue == "import")
    {
        ImportDeclaration declaration;
        declaration.ParseImportDeclaration(i, "");
        if (!declaration.ImportDeclarationNode.Children.empty())
        {
            Program.Children.push_back(declaration.ImportDeclarationNode);
        }
    }
    else if (currentValue == "fn")
    {
        FunctionDeclaration declaration;
        declaration.ParseFunctionDeclaration(i);
        if (declaration.FunctionDeclarationNode.Children.size() >= 3)
        {
            Program.Children.push_back(declaration.FunctionDeclarationNode);
        }
    }
    else if (currentValue == "enum")
    {
        Enum declaration;
        declaration.ParseEnumDeclaration(i);
        if (!declaration.EnumNode.Children.empty())
        {
            Program.Children.push_back(declaration.EnumNode);
        }
    }
    else if (currentValue == "struct")
    {
        Struct declaration;
        declaration.ParseStructDeclaration(i);
        if (declaration.StructNode.Children.size() == 2)
        {
            Program.Children.push_back(declaration.StructNode);
        }
    }
    else if (currentValue == "if")
    {
        ControlFlowStatement declaration;
        declaration.ParseIfStatement(i);
        if (!declaration.ControlFlowStatementNode.Value.empty())
        {
            Program.Children.push_back(declaration.ControlFlowStatementNode);
        }
    }
    else if (currentValue == "else")
    {
        ControlFlowStatement declaration;
        if (static_cast<size_t>(i) + 1 < Lexer::tokens.size() &&
            Lexer::tokens[static_cast<size_t>(i) + 1].Value == "if")
        {
            ++i;
            declaration.ParseIfStatement(i);
            if (!declaration.ControlFlowStatementNode.Value.empty())
            {
                declaration.ControlFlowStatementNode.Value = "else if";
            }
        }
        else
        {
            declaration.ParseElseStatement(i);
        }
        if (!declaration.ControlFlowStatementNode.Value.empty())
        {
            Program.Children.push_back(declaration.ControlFlowStatementNode);
        }
    }
    else if (currentValue == "while")
    {
        IterationStatement declaration;
        int loopIndex = 0;
        declaration.ParseWhileStatement(i, loopIndex);
        if (!declaration.WhileStatementNode.Value.empty())
        {
            Program.Children.push_back(declaration.WhileStatementNode);
        }
    }
    else if (currentValue == "for")
    {
        IterationStatement declaration;
        declaration.ParseForCondition(i, "");
        if (!declaration.ForStatementNode.Value.empty())
        {
            Program.Children.push_back(declaration.ForStatementNode);
        }
    }
    else if (currentValue == "return")
    {
        JumpBasedStatements declaration;
        declaration.ParseReturnStatement(i);
        if (declaration.ReturnStatementNode.Value == "return")
        {
            Program.Children.push_back(declaration.ReturnStatementNode);
        }
    }
    else if (currentValue == "break")
    {
        JumpBasedStatements declaration;
        declaration.ParseBreakStatement(i);
        if (declaration.BreakStatementNode.Value == "break")
        {
            Program.Children.push_back(declaration.BreakStatementNode);
        }
    }
    else if (currentValue == "continue")
    {
        JumpBasedStatements declaration;
        declaration.ParseContinueStatement(i);
        if (declaration.ContinueStatementNode.Value == "continue")
        {
            Program.Children.push_back(declaration.ContinueStatementNode);
        }
    }

    if (i <= previousIndex)
    {
        ++i;
    }
}