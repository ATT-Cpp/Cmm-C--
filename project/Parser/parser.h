#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
// ----------------------------------------------
//                     LOOPS
//-----------------------------------------------
class IfStatement
{ 
    public:
      void ParseIfStatement(int& i);
};

class WhileStatement {
    public:
        void ParseWhileStatement(int& i);
};

class ForStatement {

    public:
        void ParseForStatement(int& i);
        void ParseArguments(int& i);
};

class VariableDeclaration
{

    public:
      void ParseVarDecl(int& i);
};
