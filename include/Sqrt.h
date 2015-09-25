#ifndef SQRT_H
#define SQRT_H

#include "UnOp.h"

class Sqrt : public UnOp
{
    public:
        Sqrt(Expression *);
        virtual ~Sqrt();
        double evaluate();
        void print();
};

#endif // SQRT_H
