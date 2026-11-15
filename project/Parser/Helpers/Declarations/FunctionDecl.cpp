#include "../../../Include/includes.h"

Helper help;

void FunctionDeclaration::ParseArguments(int& i)
{
    if (!help.Universal(i, {true, true})) {
        return;
    }
    if (help.Universal(i, {false, false, true, "["})) {
        return;
    }
    if (!help.Universal(i, {false, false, true, "("})) {
        return;
    }
    ++i;

    if (!help.Universal(i, {true, true})) {
        return;
    }

    if (help.Universal(i, {false, false, true, ")"})) {
        ++i;
        return;
    }

    if (!help.Universal(i, {false, false, true, "var"})) {
        return;
    }

    ParseVariableDeclFunc(i);

    if (!help.Universal(i, {false, false, true, ")"})) {
        return;
    }
    ++i;

}

void FunctionDeclaration::ParseVariableDeclFunc(int& i)
{
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if (!help.Universal(i, {false, false, true, "var"})) {
        return;
    }
    ++i;

    if (!help.Universal(i, {true, true})) {
        return;
    }

    const bool isType =
        help.Universal(i, {false, false, true, "auto"}) ||
        help.Universal(i, {false, false, true, "int"}) ||
        help.Universal(i, {false, false, true, "bool"}) ||
        help.Universal(i, {false, false, true, "string"}) ||
        help.Universal(i, {false, false, true, "char"});
    if (!isType) {
        return;
    }

    VariableDeclFunc.Type = ASTnode::DATA_TYPES;
    ++i;

    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if (Compiler::tokens[i].TokenType != Compiler::IDENTIFIER) {
        return;
    }

    VariableDeclFunc.Value = Compiler::tokens[i].Value;
    ++i;
}
