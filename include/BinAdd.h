#ifndef BINADD_H
#define BINADD_H

#include "BinOp.h"

class BinAdd : public BinOp
{
    public:
        BinAdd(Expression*,Expression*);
        virtual ~BinAdd();
        double evaluate();
        void print();

};

#endif // BINADD_H
