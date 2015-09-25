#ifndef ASIN_H
#define ASIN_H

#include "UnOp.h"

class Asin : public UnOp
{
    public:
        Asin(Expression*);
        virtual ~Asin();
        double evaluate();
        void print();
};

#endif // sin_H
