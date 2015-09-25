#ifndef BINOP_H
#define BINOP_H

#include "Expression.h"

class BinOp : public Expression
{
    public:
        virtual ~BinOp();
        Expression* getLeftExp();
        Expression* getRightExp();
    protected:
        BinOp(Expression*,Expression*);
        Expression* leftExp;
        Expression* rightExp;
};

#endif // BINOP_H
