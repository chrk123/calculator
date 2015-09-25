#ifndef ATAN_H
#define ATAN_H

#include "UnOp.h"

class Atan : public UnOp
{
    public:
        Atan(Expression *);
        virtual ~Atan();
        double evaluate();
        void print();
};

#endif // TAN_H
