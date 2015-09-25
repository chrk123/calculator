#include <math.h>
#include <iostream>

#include "Cosh.h"

using namespace std;

Cosh::Cosh(Expression* e) : UnOp(e)
{
    //ctor
}

Cosh::~Cosh()
{
    //dtor
}

double Cosh::evaluate() {
    return cosh(exp->evaluate());
}

void Cosh::print() {
    cout << "cosh ( ";
    exp->print();
    cout << " ) ";
}
