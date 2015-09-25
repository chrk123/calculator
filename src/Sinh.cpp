#include <math.h>
#include <iostream>

#include "Sinh.h"

using namespace std;

Sinh::Sinh(Expression* e) : UnOp(e)
{
    //ctor
}

Sinh::~Sinh()
{
    //dtor
}

double Sinh::evaluate() {
    return sinh(exp->evaluate());
}
void Sinh::print() {
    cout << "sinh ( ";
    exp->print();
    cout << " ) ";
}
