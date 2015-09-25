#ifndef SIN_H
#define SIN_H

#include "UnOp.h"

class Sin : public UnOp
{
    public:
        Sin(Expression*);
        virtual ~Sin();
        double evaluate();
        void print();
};

#endif // SIN_H
