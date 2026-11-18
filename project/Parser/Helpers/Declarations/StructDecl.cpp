#include "../../../Include/includes.h"
Helper help;
Struct st;

void Struct::ParseStructDeclaration(int& i) {
    if(!help.Universal(i, {true, true, false, ""})) {
        return;
    } 
    if(!help.Universal(i, {false, false, true, "struct"})) {
        return;
    }
    ++i;

    if(!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }
    ++i;

    if(!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(!help.Universal(i, {false, false, true, "["})) {
        return;
    }
    ++i;

    if(!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    while(!help.Universal(i, {false, false, true, "]"})) {
        st.ParseStructBody(i);
    }
    ++i;
}
void Struct::ParseStructBody(int& i) {
    if(!help.Universal(i, {true, true, false, ""})) {
        return;
    }

    while(!help.Universal(i, {false, false, true, "]"})) {
        if(!help.Universal(i, {true, true, false, ""})) {
            return;
        }
        st.ParseVariableDeclStruct(i);
    }
}
void Struct::ParseVariableDeclStruct(int& i) {
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
    if (!help.Universal(i, {false, false, true, "auto"}) &&
        !help.Universal(i, {false, false, true, "int"}) &&
        !help.Universal(i, {false, false, true, "bool"}) &&
        !help.Universal(i, {false, false, true, "string"}) &&
        !help.Universal(i, {false, false, true, "char"})) {
        return;
    }
    VariableDeclStruct.Type = ASTnode::DATA_TYPES;
    ++i;
    // END
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }
    if(Compiler::tokens[static_cast<size_t> (i)].TokenType != Compiler::IDENTIFIER) {
        return;
    }
    VariableDeclStruct.Value = Compiler::tokens[static_cast<size_t> (i)].Value;
    ++i;
    //end
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }

    if(!help.Universal(i, {true, true, true, ";"})) {
        return;
    }
    ++i;
    //END
}