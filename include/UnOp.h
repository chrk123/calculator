#ifndef UNOP_H
#define UNOP_H

#include "Expression.h"

class UnOp : public Expression
{
    public:
        UnOp(Expression*);
        virtual ~UnOp();
        double evaluate() = 0;
    protected:
        Expression* exp;

};

#endif // UNOP_H
