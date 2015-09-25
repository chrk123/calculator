#ifndef TAN_H
#define TAN_H

#include "UnOp.h"

class Tan : public UnOp
{
    public:
        Tan(Expression *);
        virtual ~Tan();
        double evaluate();
        void print();
};

#endif // TAN_H
