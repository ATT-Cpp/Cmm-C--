#include "../../Lexer/Core/lexer.h"
class ControlFlowStatement
{
  public:
    inline void ParseIfStatement(int &i);
    inline void ParseElseStatement(int &i);
    inline void ParseElseIfStatement(int &i);
};

class IterationStatement
{
  public:
    inline void ParseWhileStatement(int &i, int &b);
    inline void ParseForStatement(int &i, std::string input);
    inline void ParseForCondition(int &i, std::string input);
    ASTnode::Node ForStatementNode = ASTnode::MakeNode(ASTnode::FOR_STATEMENT, "");
    ASTnode::Node increment = ASTnode::MakeNode(ASTnode::OPERATOR, "++");
    
};

class JumpBasedStatements
{

  public:
    inline void ParseBreakStatement(int &i);
    inline void ParseReturnStatement(int &i);
    inline void ParseContinueStatement(int &i);
};

class VariableDeclaration
{

  public:
    inline void ParseVarDecl(int &i);
    inline void ParseIdentifier(int &i);
    inline void ParseDataType(int& i);
    inline void ParseValue(int& i);
    inline void FunctionAndVariableValue(int& i);
    ASTnode::Node VariableDeclarationNode = ASTnode::MakeNode(ASTnode::VARIABLE_DECL, "");
    ASTnode::Node Identifier = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node DataType = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node Value = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
    ASTnode::Node Program = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
};



class ImportDeclaration {
    public:
        inline void ParseImportDeclaration(int& i, const std::string& input);
        ASTnode::Node Import = ASTnode::MakeNode(ASTnode::IMPORT, "");
        ASTnode::Node LibraryName = ASTnode::MakeNode(ASTnode::STRING, "");
};

class FunctionDeclaration {
    public:
        inline void ParseFunctionDeclaration(int& i);
        inline void ParseFunctionBody(int& i);
        inline void ParseArguments(int& i);
        inline void ParseVariableDeclFunc(int& i);
        ASTnode::Node Function = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, "");
        ASTnode::Node FunctionName = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, "");
        ASTnode::Node Arguments = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, "");
        ASTnode::Node VariableDeclFunc = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
};
class Enum {
    public:
        inline void ParseEnumDeclaration(int& i);
        inline void ParseEnumBody(int& i);
        ASTnode::Node EnumName = ASTnode::MakeNode(ASTnode::STRING, "");
        ASTnode::Node EnumBodyNames = ASTnode::MakeNode(ASTnode::IDENTIFIER, "");
        ASTnode::Node Enum = ASTnode::MakeNode(ASTnode::ENUM_DECL, "");
};
class Struct {
    public:
        inline void ParseStructDeclaration(int& i);
        inline void ParseStructBody(int& i);
        inline void ParseVariableDeclStruct(int& i);
        ASTnode::Node StructName = ASTnode::MakeNode(ASTnode::STRUCT_DECL, "");
        ASTnode::Node VariableDeclStruct = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
};
