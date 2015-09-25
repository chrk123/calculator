#ifndef FACULTY_H
#define FACULTY_H

#include "UnOp.h"

class Faculty : public UnOp
{
    int fac(int);

    public:
        Faculty(Expression*);
        virtual ~Faculty();
        double evaluate();
        void print();
};

#endif // FACULTY_H
