#include <iostream>

#include "Tokenizer.h"

Tokenizer::Tokenizer()
{
    //ctor
}

Tokenizer::~Tokenizer()
{
    //dtor
}

void Tokenizer::add(string str,int type) {

    tokenInfo info(str,type);
    tokenInfos.push_back(info);

}

Tokenizer::tokenInfo::tokenInfo(string str,int type) {

    this->type = type;

    string regexp = "^(";
    regexp += str;
    regexp += ")";

    expr.assign(regexp);
}

Tokenizer::tokenInfo::~tokenInfo() {

}

token::token(string str, int i) {
    type = i;
    sequence = str;
}

token::token() {
}

vector<token> Tokenizer::tokenize(string str) {

    vector<token> result;
    smatch match;

    //indicates if we've found a matching token during a single run
    bool matched;

    while(!str.empty()) {

        matched = false;

        for(auto& info : tokenInfos) {
            if(regex_search(str,match,info.expr)) {
                token t(match.str(0),info.type);
                result.push_back(t);
                //remove the matching token from the input string
                str = regex_replace(str,info.expr,"");
                matched = true;
                break;
            }
        }

        if(!matched) {
                //temporary until better exception is found
            throw runtime_error("could not match any token on: "+str);
        }
    }

    return result;
}
