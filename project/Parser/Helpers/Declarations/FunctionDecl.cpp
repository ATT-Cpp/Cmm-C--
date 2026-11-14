#include "../../../Include/includes.h"
VariableDeclaration vd;
Helper help;
FunctionDeclaration fd;
ASTnode::Node Arguments = ASTnode::MakeNode(ASTnode::FUNCTION_DECL, "");
ASTnode::Node VariableDeclFunc = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");
void FunctionDeclaration::ParseArguments(int& i) {
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }

    if (!help.Universal(i, {false, false, true, "("})) {
        return;
    }
    ++i;

    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }

    if (!help.Universal(i, {false, false, true, ")"})) {
        return;
    }
    ++i;
  
    while(true) {
        if (!help.Universal(i, {true, true, false, ""})) {
            return;
        }
        if(!help.Universal(i, {false, false, true, "("})) {
            return;
        }
        fd.ParseVariableDecl(i);
        ++i;

        if (!help.Universal(i, {true, true, false, ""})) {
            return;
        }

        if(!help.Universal(i, {false, false, true, ","})) {
            return;
        }
        ++i;

        if (!help.Universal(i, {true, true, false, ""})) {
            return;
        }

        if(!help.Universal(i, {false, false, true, ")"})) {
            return;
        }
        ++i;
    }

}

void FunctionDeclaration::ParseVariableDecl(int& i) {
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(!help.Universal(i, {false, false, true, "var"})) {
        return;
    }
    ++i;
    //END
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(!help.Universal(i, {false, false, true, "auto"}) || !help.Universal(i, {false, false, true, "int"}) || !help.Universal(i, {false, false, true, "bool"}) || !help.Universal(i, {false, false, true, "string"}) || !help.Universal(i, {false , false, true, "char"})) {
        return;
    }
    VariableDeclFunc.Type = ASTnode::DATA_TYPES;
    ++i;
    // END
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(Compiler::tokens[i].TokenType != Compiler::IDENTIFIER) {
        return;
    }
    VariableDeclFunc.Value = Compiler::tokens[i].Value;
    ++i;
    //END
}