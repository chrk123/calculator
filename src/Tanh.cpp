#include <math.h>
#include <iostream>

#include "Tanh.h"

using namespace std;

Tanh::Tanh(Expression* e) : UnOp(e)
{
    //ctor
}

Tanh::~Tanh()
{
    //dtor
}

double Tanh::evaluate() {
    return tanh(exp->evaluate());
}
void Tanh::print() {
    cout << "tanh ( ";
    exp->print();
    cout << " ) ";
}
