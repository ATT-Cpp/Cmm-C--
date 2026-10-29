#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
// ----------------------------------------------
//                     LOOPS
//-----------------------------------------------
class IfStatement //(Todo: implement this class)
{ 
    public:
      void ParseIfStatement(int& i);
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
