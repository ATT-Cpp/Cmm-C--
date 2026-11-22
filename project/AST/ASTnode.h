#pragma once

#include <string>
#include <vector>

class ASTnode
{
  public:
    enum Node_Properties
    {
    IDENTIFIER,

    DATA_TYPES,

    STRING,
    INT,
    CHAR,
    BOOL,
    AUTO,
    DOUBLE,

    IMPORT,

    OPERATOR,
    ANDOR,

    PROGRAM,

    STRUCT_DECL,
    STRUCT_NAME,
    STRUCT_BODY,

    ENUM_DECL,
    ENUM_NAME,
    ENUM_VALUE,

    FUNCTION_DECL,
    FUNCTION_NAME,
    FUNCTION_ARGS,
    FUNCTION_BODY,

    VARIABLE_DECL,

    IF_STATEMENT,
    FOR_STATEMENT,
    WHILE_STATEMENT,

    RETURN_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,

    MATCH_STATEMENT,
    TYPE,
    };
    struct Node
    {
        Node_Properties Type;
        std::string Value;
        std::vector<Node> Children;
    };

    static ASTnode::Node MakeNode(ASTnode::Node_Properties type, const std::string& value);
};
