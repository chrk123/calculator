#ifndef ACOS_H
#define ACOS_H

#include "UnOp.h"

class Acos : public UnOp
{
    public:
        Acos(Expression*);
        virtual ~Acos();
        double evaluate();
        void print();
};

#endif // SIN_H
