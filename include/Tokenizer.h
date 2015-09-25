#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <regex>
#include <vector>
#include <string>

using namespace std;

enum TokenTypes {

    PLUSMINUS=0,
    MULTDIV,
    RAISED,
    FUNCTION,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    NUMBER,
    EPSILON,
    FACULTY
};

struct token {
    int type;
    string sequence;
    token(string,int);
    token();
};

class Tokenizer
{
    public:
        Tokenizer();
        virtual ~Tokenizer();
        void add(string,int);

        vector<token> tokenize(string);

    protected:
    private:
        struct tokenInfo {
            //the regular expression for the token
            regex expr;
            int type;
            tokenInfo(string,int);
            ~tokenInfo();
        };

        vector<tokenInfo> tokenInfos;
};

#endif // TOKENIZER_H
