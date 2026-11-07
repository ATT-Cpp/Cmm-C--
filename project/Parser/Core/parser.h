#include "../../Lexer/Core/lexer.h"
#include <iostream>
#include <string>
#include <vector>
class ControlFlowStatement
{
  public:
    inline void ParseIfStatement(int &i);
    inline void ParseElseStatement(int &i);
    inline void ParseElseIfStatement(int &i);
};

class IterationStatement
{
  public:
    void ParseWhileStatement(int &i, int &b);
    void ParseForStatement(int &i, std::string input);
    void ParseForCondition(int &i, std::string input);
};

class JumpBasedStatements
{

  public:
    void ParseBreakStatement(int &i);
    void ParseReturnStatement(int &i);
    void ParseContinueStatement(int &i);
};

class VariableDeclaration
{

  public:
    void ParseVarDecl(int &i);
    void ParseDataTypes(int &i);
    ASTnode::Node VariableDeclarationNode = ASTnode::MakeNode(ASTnode::VARIABLE_DECL, "");
    ASTnode::Node VariableValue = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node VariableName = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
};

class ImportDeclaration {
    public:
        void ParseImportDeclaration(int& i, const std::string& input);
};
