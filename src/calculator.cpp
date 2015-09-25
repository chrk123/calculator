#include <iostream>
#include <string>

#include "Tokenizer.h"
#include "Parser.h"
#include "Expression.h"

using namespace std;

int main()
{
    Tokenizer t;

    //adding the tokens for the tokenizer
    t.add("\\+|-",PLUSMINUS);
    t.add("\\*|/",MULTDIV);
    t.add("\\^",RAISED);
    t.add("!",FACULTY);
    //regexp matching is greedy; try sinh/cosh/tanh first
    t.add("sinh|cosh|tanh",FUNCTION);
    t.add("asin|acos|atan",FUNCTION);
    t.add("sin|cos|tan|sqrt",FUNCTION);
    t.add("log\\[[[[:digit:]]+(\\.)?[[:digit:]]*\\]|log",FUNCTION);
    t.add("\\(",OPEN_BRACKET);
    t.add("\\)",CLOSE_BRACKET);
    t.add("[[:digit:]]+(\\.)?[[:digit:]]*",NUMBER);

    string str;

    while(1) {
        cout << "=> ";

        if(!getline(cin,str)) {
          cout << endl;
          return 1;
        }

        str.erase(remove_if(str.begin(),str.end(), ::isspace),str.end());

        if(str.empty())
          continue;

        if(str == "quit")
            break;
        try{
            vector<token> a = t.tokenize(str);
            Parser p(a);
            Expression* exp = p.parse();
            cout << "\t\t== " << exp->evaluate() << endl;;
        } catch (runtime_error& e) {
            cout << "\t\tSyntax error: " << e.what() << endl;;
        }
    }

    return 0;
}
