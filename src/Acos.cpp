#include <math.h>
#include <iostream>

#include "Acos.h"

using namespace std;

Acos::Acos(Expression* e) : UnOp(e)
{
    //ctor
}

Acos::~Acos()
{
    //dtor
}

double Acos::evaluate() {
    return acos(exp->evaluate());
}

void Acos::print() {
    cout << "acos ( ";
    exp->print();
    cout << " ) ";
}
