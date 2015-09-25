#include <math.h>
#include <iostream>

#include "Sin.h"

using namespace std;

Sin::Sin(Expression* e) : UnOp(e)
{
    //ctor
}

Sin::~Sin()
{
    //dtor
}

double Sin::evaluate() {
    return sin(exp->evaluate());
}
void Sin::print() {
    cout << "sin ( ";
    exp->print();
    cout << " ) ";
}
