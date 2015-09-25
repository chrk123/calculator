#ifndef SINH_H
#define SINH_H

#include "UnOp.h"

class Sinh : public UnOp
{
    public:
        Sinh(Expression*);
        virtual ~Sinh();
        double evaluate();
        void print();
};

#endif // SINH_H
