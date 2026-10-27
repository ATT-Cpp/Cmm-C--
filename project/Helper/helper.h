class Helper {
    public:
        bool FindKeyword(int& i, std::string expected);
        bool FindType(int& i, TokenType expected);
        void parseBlock(int& i);
        void parseCondition(int& i);
        void ParseForStatement(int& i);
};
