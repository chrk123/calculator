#include <math.h>
#include <iostream>

#include "Asin.h"

using namespace std;

Asin::Asin(Expression* e) : UnOp(e)
{
    //ctor
}

Asin::~Asin()
{
    //dtor
}

double Asin::evaluate() {
    return asin(exp->evaluate());
}
void Asin::print() {
    cout << "asin ( ";
    exp->print();
    cout << " ) ";
}
