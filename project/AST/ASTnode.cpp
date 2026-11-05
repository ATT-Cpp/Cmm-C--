#include "ASTnode.h"

ASTnode::Node ASTnode::MakeNode(
    ASTnode::Node_Properties type,
    const std::string& value)
{
    ASTnode::Node node{};

    node.Type = type;
    node.Value = value;

    return node;
}