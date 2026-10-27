#include<vector>
#include <string>

class ASTnode {
    private:
        enum Node_Properties {
            IMPORT,
            FUNCTION,
            VARIABLE,
            IFSTATEMENT,
            FORSTATEMENT,
            WHILESTATEMENT,
        }
        struct Node {
            Node_Properties Type;
            std::vector Value;
            std::vector <Node> Children;
        }
}
