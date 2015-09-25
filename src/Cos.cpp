#include <math.h>
#include <iostream>

#include "Cos.h"

using namespace std;

Cos::Cos(Expression* e) : UnOp(e)
{
    //ctor
}

Cos::~Cos()
{
    //dtor
}

double Cos::evaluate() {
    return cos(exp->evaluate());
}

void Cos::print() {
    cout << "cos ( ";
    exp->print();
    cout << " ) ";
}
