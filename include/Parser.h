#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "Tokenizer.h"
#include "Expression.h"


/*
TERMINAL             meaning            type

PLUSMINUS               + -                 0
MULTDIV                 * /                 1
RAISED                  ^                   2
FUNCTION             sin,cos,tan            3
OPEN_BRACKET            (                   4
CLOSE_BRACKET           )                   5
NUMBER                  any number          6

######
CFG

Taken from the cogitolearning tutorial on parsing:
http://cogitolearning.co.uk/?p=565
Thanks!

ORDERED BY PRECEDENCE, ascending!

plusminus operations should be derived first,
as they are normally the root of the abstract syntax tree

EXPRESSION -> SIGNED_TERM SUM_OP
SUM_OP -> plusminus TERM SUM_OP
SUM_OP -> epsilon

SIGNED_TERM -> plusminus TERM
SIGNED_TERM -> TERM

multdiv operations have a higher precedence and are represented by TERM

TERM -> FACTOR TERM_OP
TERM_OP -> multdiv SIGNED_FACTOR TERM_OP
TERM_OP -> epsilon

SIGNED_FACTOR -> plusminus FACTOR
SIGNED_FACTOR -> FACTOR

FACTOR -> ARGUMENT FACTOR_OP
FACTOR_OP -> raised SIGNED_FACTOR
FACTOR_OP -> epsilon

ARGUMENT -> number
ARGUMENT -> function ARGUMENT
ARGUMENT -> open_bracket EXPRESSION close_bracket

*/

class Parser
{
    Expression* expression();
    Expression* sum_op(Expression*);
    Expression* signed_term();
    Expression* term();
    Expression* term_op(Expression*);
    Expression* signed_factor();
    Expression* factor();
    Expression* factor_op(Expression*);
    Expression* argument();
    void consume();

    deque<token> tokens;
    token lookahead;

    public:
        Parser(const vector<token>&);
        virtual ~Parser();
        Expression* parse();
};

#endif // PARSER_H
