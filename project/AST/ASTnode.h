#pragma once

#include <vector>
#include <string>

class ASTnode {
    public:
        enum Node_Properties {
            DATA_TYPES,
            STRING,
            INT,
            CHAR,
            BOOL,
            IMPORT,
            IDENTIFIER,
            OPERATOR,
            ANDOR,
            STRUCT_DECL,
            ENUM_DECL,
            FUNCTION_DECL,
            VARIABLE_DECL,
            IF_STATEMENT,
            FOR_STATEMENT,
            WHILE_STATEMENT,
            RETURN_STATEMENT,
            BREAK_STATEMENT,
            CONTINUE_STATEMENT,
            MATCH_STATEMENT,
        };
        struct Node {
            Node_Properties Type;
            std::string Value;
            std::vector<Node> Children;
        };
};
