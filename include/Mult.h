#ifndef MULT_H
#define MULT_H

#include "BinOp.h"

class Mult : public BinOp
{
    public:
        Mult(Expression*,Expression*);
        virtual ~Mult();
        double evaluate();
        void print();
    protected:
    private:
};

#endif // MULT_H
