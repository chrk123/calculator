#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expression.h"

class Constant : public Expression
{
    double value;
    public:
        Constant(double);
        virtual ~Constant();
        double evaluate();
        void print();
};

#endif // CONSTANT_H
