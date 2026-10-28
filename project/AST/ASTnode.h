#include<vector>
#include <string>

class ASTnode {
    private:
        enum Node_Properties {
            IMPORT,
            STRUCT_DECL,
            ENUM_DECL
            FUNCTION_DECL,
            VARIABLE_DECL
            IF_STATEMENT,
            FOR_STATEMENT,
            WHILE_STATEMENT,
            RETURN_STATEMENT,
            BREAK_STATEMENT,
            CONTINUE_STATEMENT,
            MATCH_STATEMENT,
  
        }
        struct Node {
            Node_Properties Type;
            std::vector Value;
            std::vector <Node> Children;
        }
}
