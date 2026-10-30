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

class WhileStatement {//(Todo: implement this class)
    public:
        void ParseWhileStatement(int& i);
};

class ForStatement {//(Todo: implement this class)

    public:
        void ParseForStatement(int& i);
        void ParseArguments(int& i);
};

class VariableDeclaration//(Todo: implement this class)
{

    public:
      void ParseVarDecl(int& i);
};
