#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
class IfStatement
{
    private:
      int current = 0;

      IfStatement(Tokens t) : Tokens(t) { }
      
    public:
      void ParseIfStatement();
      void Consume(std::vector<Token> Tokens, int& i, std::string expected);
};

class VariableDeclaration
{
    private:
      int current = 0;

      VariableDecleration(Tokens t) : Tokens(t) { }

    public:
      void ParseVarDecl();
      void Consume(std::vector<Token> Tokens);
};
    
   
