#ifndef COS_H
#define COS_H

#include "UnOp.h"

class Cos : public UnOp
{
    public:
        Cos(Expression*);
        virtual ~Cos();
        double evaluate();
        void print();
};

#endif // COS_H
