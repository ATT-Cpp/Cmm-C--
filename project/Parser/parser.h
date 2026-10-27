#include "Lexer/lexer.h"
#include<iostream>
#include<vector>
#include<string>
// ----------------------------------------------
//                     LOOPS
//-----------------------------------------------
class IfStatement
{ 
    private:
      enum ifstmt {
          LIDENTIFIER,
          LOGICOP //
          RIDENTIFIER,
          LOGICGATES, 
      };
      struct ifstm {
          ifstmt if;
          std::string value;
      }
      std::vector <ifstm> IF;
    public:
      void ParseIfStatement(int& i);
};

class WhileStatement {
    private:
        struct whilestmt {
            std::string Lidentifier,
            std::string logicOp,
            std::string Ridentifier,
            std::string logicGates,
        };
        std::vector <whilestmt> WH;

    public:
        void ParseWhileStatement(int& i);
};

class ForStatement {
    private:
        struct forstmt {
            std::string Lidentifier,
            std::string logicOp,
            std::string Ridentifier,
            std::string logicGates,
            std::string decreincrement,
            std::string declaration,
        };

    public:
        void ParseForStatement(int& i);
        void ParseArguments(int& i);
};

class VariableDeclaration
{
    private:
    struct vardecl {
        std::string Lindentifier,
        std::string String;
        int num;
        float decimal;
        bool TF;
        char charecter;  
    };
    std::vector <vardecl> VD;

    public:
      void ParseVarDecl(int& i);
};
