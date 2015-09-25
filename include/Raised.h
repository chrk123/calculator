#ifndef RAISED_H
#define RAISED_H

#include "BinOp.h"

class Raised : public BinOp
{
    public:
        Raised(Expression*,Expression*);
        virtual ~Raised();
        double evaluate();
        void print();
};

#endif // RAISED_H
