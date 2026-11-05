#include "../../Lexer/Core/lexer.h"
#include <iostream>
#include <string>
#include <vector>
class ControlFlowStatement
{
  public:
    inline void ParseIfStatement(int &i, int &b);
    inline void ParseElseStatement(int &i, int &b);
    inline void ParseElseIfStatement(int &i, int &b);
};

class IterationStatement
{
  public:
    void ParseWhileStatement(int &i, int &b);
    void ParseForStatement(int &i, int &b);
    void ParseForCondition(int &i, int &b);
};

class JumpBasedStatements
{

  public:
    void ParseBreakStatement(int &i, int &b);
    void ParseReturnStatement(int &i, int &b);
    void ParseContinueStatement(int &i, int &b);
};

class VariableDeclaration
{

  public:
    void ParseVarDecl(int &i);
    void ParseDataTypes(int &i);
};
