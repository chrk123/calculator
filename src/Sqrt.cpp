#include <math.h>
#include <iostream>

#include "Sqrt.h"

using namespace std;

Sqrt::Sqrt(Expression* e) : UnOp(e)
{
    //ctor
}

Sqrt::~Sqrt()
{
    //dtor
}

double Sqrt::evaluate() {
    return sqrt(exp->evaluate());
}
void Sqrt::print() {
    cout << "sqrt ( ";
    exp->print();
    cout << " ) ";
}
