#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
class IfStatement
{
    private:
      struct Ifstate
      {
        std::string identifier1,
        std::string op,
        std::string symbol,
        std::string identifier2,
        std::string AND,
        std::string OR,
        std::string NOT,
      };
      int current = 0;
      std::vector<Ifstate> ifstmt;

      IfStatement(Tokens t) : Tokens(t) { }
      
    public:
      Ifstate ParseIfStatement();
      void advance();
      void Consume(std::vector<Token> Tokens);
};

class VariableDeclaration
{
    private:
      struct VariableDecl
      {
        std::vector<std::string> Keywords;
        std::vector<Token> comp::Tokens;
      };
      std::vector <VariableDecl> vardecl;
      int current = 0;

      VariableDecleration(Tokens t) : Tokens(t) { }

    public:
      VariableDecleration ParseVarDecl();
      void advance();
      void Consume(std::vector<Token> Tokens);
};
    
   
