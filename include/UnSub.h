#ifndef UNSUB_H
#define UNSUB_H

#include "UnOp.h"

class UnSub : public UnOp
{
    public:
        UnSub(Expression*);
        virtual ~UnSub();
        double evaluate();
        void print();
};

#endif // UNSUB_H
