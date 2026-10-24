#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
class IfStatement
{  
    private:
      struct ifstmt {
          std::string Lidentifier,
          std::string logicOp, //
          std::string Ridentifier,
          std::string logicGates,  
      };
      std::vector <ifstmt> IF;
    public:
      bool ParseIfStatement(int& i);
};

class VariableDeclaration
{
    public:
      void ParseVarDecl(int& i);
};

class WhileStatement {
    private:
    
    public:
    void ParseWhileStatement(int& i);
};
   
