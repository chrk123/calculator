#include <iostream>

#include "Parser.h"

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
        else {
            consume();
            temp = new Tan(argument());
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
