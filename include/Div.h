#ifndef DIV_H
#define DIV_H

#include "BinOp.h"

class Div : public BinOp
{
    public:
        Div(Expression*,Expression*);
        virtual ~Div();
        double evaluate();
        void print();
};

#endif // DIV_H
