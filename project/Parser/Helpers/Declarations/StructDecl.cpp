#include "../../../Include/includes.h"
Helper help;
Struct st;

void Struct::ParseStructDeclaration(int& i) {
    StructNode = ASTnode::MakeNode(ASTnode::STRUCT_DECL, "");
    StructName = ASTnode::MakeNode(ASTnode::STRUCT_NAME, "");
    StructBody = ASTnode::MakeNode(ASTnode::STRUCT_BODY, "");

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
    if(Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    StructName.Value = Lexer::tokens[static_cast<size_t> (i)].Value;
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
    st.StructBody = ASTnode::MakeNode(ASTnode::STRUCT_BODY, "");
    while(!help.Universal(i, {false, false, true, "]"})) {
        st.ParseStructBody(i);
    }
    ++i;
    StructBody = st.StructBody;
    StructNode.Children.push_back(StructName);
    StructNode.Children.push_back(StructBody);
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
    VariableDeclStruct = ASTnode::MakeNode(ASTnode::DATA_TYPES, "");

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
    if(Lexer::tokens[static_cast<size_t> (i)].TokenType != Lexer::IDENTIFIER) {
        return;
    }
    VariableDeclStruct.Value = Lexer::tokens[static_cast<size_t> (i)].Value;
    ++i;
    //end
    if (!help.Universal(i, {true, true, false, ""})) {
        return;
    }

    if(!help.Universal(i, {true, true, true, ";"})) {
        return;
    }
    ++i;
    StructBody.Children.push_back(VariableDeclStruct);
    //END
}