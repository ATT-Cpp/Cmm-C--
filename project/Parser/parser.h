#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
class IfStatement
{  
    private:
      struct ifstmt {
          std::string identifier1,
          std::string symbol,
          std::string right
    public:
      void ParseIfStatement();
      void Consume(std::vector<Token> tokens, int& i, std::string expected);
};

class VariableDeclaration
{
    public:
      void ParseVarDecl();
      void Consume(std::vector<Token> tokens, int& i, std::string expected);
};

class WhileStatement {
    public:
    void ParseWhileStatement();
    void Consume(std::vector<Token> tokens, int& i, std::string expected);
};
   
