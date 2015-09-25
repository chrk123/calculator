#ifndef TANH_H
#define TANH_H

#include "UnOp.h"

class Tanh : public UnOp
{
    public:
        Tanh(Expression *);
        virtual ~Tanh();
        double evaluate();
        void print();
};

#endif // TANH_H
