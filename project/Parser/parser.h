#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
// ----------------------------------------------
//                     LOOPS
//-----------------------------------------------
class ControlFlowStatement //(Todo: implement this class)
{ 
    public:
      inline void ParseIfStatement(int& i, int& b);
      inline void ParseElseStatement(int& i, int& b);
      inline void ParseElseIfStatement(int& i, int& b);
};

class IterationStatement {//(Todo: implement this class)
    public:
        void ParseWhileStatement(int& i, int& b);
        void ParseForStatement(int& i, int& b);
        void ParseForCondition(int& i, int& b);

};

class JumpBasedStatements {//(Todo: implement this class)

    public:
        void ParseBreakStatement(int& i, int& b);
        void ParseReturnStatement(int& i, int& b);
        void ParseContinueStatement(int& i, int& b);
};

class VariableDeclaration//(Todo: implement this class)
{

    public:
      void ParseVarDecl(int& i);
      void ParseDataTypes(int& i);
};
