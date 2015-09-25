#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
    public:
        virtual ~Expression();
        virtual double evaluate() = 0;
        virtual void print() = 0;
};

#endif // EXPRESSION_H
