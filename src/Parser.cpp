#include <iostream>

#include "Parser.h"
#include "BinAdd.h"
#include "BinSub.h"
#include "Constant.h"
#include "Cos.h"
#include "Sin.h"
#include "Tan.h"
#include "Div.h"
#include "Mult.h"
#include "Raised.h"
#include "UnOp.h"
#include "UnSub.h"
#include "Cosh.h"
#include "Sinh.h"
#include "Tanh.h"
#include "Log.h"
#include "Atan.h"
#include "Acos.h"
#include "Asin.h"
#include "Sqrt.h"

Parser::Parser(const vector<token>& tokens)
{
    for(auto token : tokens)
        this->tokens.push_back(token);
}

Parser::~Parser()
{
    //dtor
}

Expression* Parser::parse() {

    lookahead = tokens.front();
    tokens.pop_front();

    Expression* syntax_tree = expression();

    if(lookahead.type != EPSILON) {
        throw runtime_error("Unexpected symbol found: "+lookahead.sequence);
    }

    return syntax_tree;
}

void Parser::consume() {

    if(tokens.empty()) {
        lookahead = token("epsilon",EPSILON);
    } else {
        lookahead = tokens.front();
        tokens.pop_front();
    }

}

Expression* Parser::expression() {

    return sum_op(signed_term());
}

Expression* Parser::sum_op(Expression* l) {

    if(lookahead.type == PLUSMINUS) {
        if(lookahead.sequence == "+") {
            consume();
            return new BinAdd(l,sum_op(term()));
        } else {
            consume();
            return new BinSub(l,sum_op(term()));
        }

    } else {
        return l;
    }
}

Expression* Parser::signed_term() {

    if(lookahead.type == PLUSMINUS) {
            if(lookahead.sequence == "+") {
                consume();
                return term();
            } else {
                consume();
                return new UnSub(term());
            }

    } else {
        return term();
    }
}

Expression* Parser::term() {

    return term_op(factor());
}

Expression* Parser::term_op(Expression* l) {

    if(lookahead.type == MULTDIV) {
        if(lookahead.sequence == "*") {
            consume();
            return new Mult(l,term_op(signed_factor()));
        } else {
            consume();
            return new Div(l,term_op(signed_factor()));
        }

    } else {
        return l;
    }
}

Expression* Parser::signed_factor() {

    if(lookahead.type == PLUSMINUS) {
        if(lookahead.sequence == "+") {
            consume();
            return factor();
        }
        else {
            consume();
            return new UnSub(factor());
        }

    } else {
        return factor();
    }
}

Expression* Parser::factor() {
    return factor_op(argument());
}

Expression* Parser::factor_op(Expression* l) {

    if(lookahead.type == RAISED) {
        consume();
        return new Raised(l,signed_factor());
    } else {
        return l;
    }
}

Expression* Parser::argument() {

    if(lookahead.type == NUMBER) {

        Expression* temp = new Constant(stod(lookahead.sequence,nullptr));
        consume();
        return temp;
    }
    else if(lookahead.type == FUNCTION) {
        Expression* temp;

        if(lookahead.sequence == "sin") {
            consume();
            temp = new Sin(argument());
        }
        else if(lookahead.sequence == "cos") {
            consume();
            temp = new Cos(argument());
        }
        else if(lookahead.sequence == "tan") {
            consume();
            temp = new Tan(argument());
        }
        else if(lookahead.sequence == "cosh") {
            consume();
            temp = new Cosh(argument());
        }
        else if(lookahead.sequence == "sinh") {
            consume();
            temp = new Sinh(argument());
        }
        else if(lookahead.sequence == "tanh") {
            consume();
            temp = new Tanh(argument());
        }
        else if(lookahead.sequence == "atan") {
            consume();
            temp = new Atan(argument());
        }
        else if(lookahead.sequence == "acos") {
            consume();
            temp = new Acos(argument());
        }
        else if(lookahead.sequence == "asin") {
            consume();
            temp = new Asin(argument());
        }
        else if(lookahead.sequence == "sqrt") {
            consume();
            temp = new Sqrt(argument());
        }
        //Log
        else {
            if(lookahead.sequence.find("[") !=  std::string::npos) {
              string strBase = lookahead.sequence.substr(4,lookahead.sequence.find("]")-1);
              consume();
              temp = new Log(argument(),stod(strBase));
            } else {
              consume();
              temp = new Log(argument(),M_E);
            }
        }

        return temp;

    }
    else if(lookahead.type == OPEN_BRACKET) {

        consume();
        Expression* result = expression();

        if(lookahead.type != CLOSE_BRACKET) {
            throw runtime_error("expected closing brackets, but got "+
                                lookahead.sequence);
        }

        consume();
        return result;
    }
    else
        throw runtime_error("expected argument, got: "+lookahead.sequence);

}
