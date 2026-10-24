#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
class IfStatement
{  
    public:
      void ParseIfStatement();
      void Consume(std::vector<Token> Tokens, int& i, std::string expected);
};

class VariableDeclaration
{
    public:
      void ParseVarDecl();
      void Consume(std::vector<Token> Tokens, int& i, std::string expected);
};

class WhileStatement {
    public:
    void ParseWhileStatement();
    void Consume(std::vector<Token> Tokens, int& i, std::string expected);
};
   
