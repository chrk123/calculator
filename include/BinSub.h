#ifndef BINSUB_H
#define BINSUB_H

#include "BinOp.h"

class BinSub : public BinOp
{
    public:
        BinSub(Expression*,Expression*);
        virtual ~BinSub();
        double evaluate();
        void print();
};

#endif // BINSUB_H
