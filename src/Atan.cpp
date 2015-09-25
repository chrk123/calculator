#include <math.h>
#include <iostream>

#include "Atan.h"

using namespace std;

Atan::Atan(Expression* e) : UnOp(e)
{
    //ctor
}

Atan::~Atan()
{
    //dtor
}

double Atan::evaluate() {
    return atan(exp->evaluate());
}
void Atan::print() {
    cout << "atan ( ";
    exp->print();
    cout << " ) ";
}
