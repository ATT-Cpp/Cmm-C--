class HelperFunctions {
    public:
        bool FindKeyword(int& i, std::string expected);
        bool FindType(int& i, TokenType expected);
        void parseBlock(int& i);
        void parseCondition(int& i);
};
