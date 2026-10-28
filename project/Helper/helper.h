#include "ASTnode.h"
class Helper {
    public:
        bool FindKeyword(int& i, std::string expected);
        bool FindType(int& i, TokenType expected);
        Node parseBlock(int& i);
        Node parseCondition(int& i);
        Node ParseForStatement(int& i);
};
