#include"parser.h"
#include"Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>

class VariableDeclaration {
    public:
        bool ParseVarDecl(int&i) {
          if(tokens[i].keywords != "var") {
            return false;
          }
          ++i;

          if(tokens[i].keywords != "auto") {
            ++i;
          }

          if(tokens[i].keywords != "int" || tokens[i].keywords != "float" || tokens[i].keywords != "bool" || tokens[i].keywords != "char" || tokens[i].keywords != "string") {
            return false;
          }
          ++i;

          if(tokens[i].type != IDENTIFER) {
            if(tokens[i].type == KEYWORD) {
              return false;
            }
            return false;
          }
          ++i;

          if(tokens[i].type != EQUALTO) {
            return false;
          }
          ++i;

          
};
