#ifndef LOG_H
#define LOG_H

#include "UnOp.h"

class Log : public UnOp
{
    double base;

    public:
        Log(Expression *,double);
        virtual ~Log();
        double evaluate();
        void print();
};

#endif // Log_H
