class Ifstatement
{
public:

    bool Parseifstmt(int& i)
    {
        if(tokens[i].type != KEYWORD ||
           tokens[i].keywords != "if")
        {
            return false;
        }
        ++i;

        if(tokens[i].type != LPARENTHESES)
        {
            return false;
        }
        ++i;

        while(tokens[i].type != RPARENTHESES)
        {
            ifstmt temp;

            if(tokens[i].type == NOT)
            {
                ++i;
            }

            if(tokens[i].type != INDENTIFIER)
            {
                return false;
            }

            temp.LIDENTIFIER = tokens[i].keywords;
            ++i;

            if(tokens[i].type != EQUALTO &&
               tokens[i].type != NOTEQUALTO &&
               tokens[i].type != GREATERTHEN &&
               tokens[i].type != GREATERTHENOREQUALTO &&
               tokens[i].type != LESSTHEN &&
               tokens[i].type != LESSTHENOREQUALTO)
            {
                return false;
            }

            temp.logicOp = tokens[i].keywords;
            ++i;

            if(tokens[i].type != INDENTIFIER)
            {
                return false;
            }

            temp.RIDENTIFIER = tokens[i].keywords;
            ++i;

            temp.logicGate = "";

            if(tokens[i].type == AND ||
               tokens[i].type == OR)
            {
                temp.logicGate = tokens[i].keywords;
            }

            IF.push_back(temp);

            if(tokens[i].type == AND ||
               tokens[i].type == OR)
            {
                ++i;
            }
        }

        ++i; 

        return true;
    }
};
