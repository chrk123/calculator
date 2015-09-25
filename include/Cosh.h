#ifndef COSH_H
#define COSH_H

#include "UnOp.h"

class Cosh : public UnOp
{
    public:
        Cosh(Expression*);
        virtual ~Cosh();
        double evaluate();
        void print();
};

#endif // COSH_H
