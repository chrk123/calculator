#ifndef UNADD_H
#define UNADD_H

#include "UnOp.h"

class UnAdd : public UnOp
{
    public:
        UnAdd(Expression*);
        virtual ~UnAdd();
        double evaluate();
        void print();
};

#endif // UNADD_H
