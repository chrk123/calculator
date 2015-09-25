#include <math.h>
#include <iostream>

#include "Tan.h"

using namespace std;

Tan::Tan(Expression* e) : UnOp(e)
{
    //ctor
}

Tan::~Tan()
{
    //dtor
}

double Tan::evaluate() {
    return tan(exp->evaluate());
}
void Tan::print() {
    cout << "tan ( ";
    exp->print();
    cout << " ) ";
}
