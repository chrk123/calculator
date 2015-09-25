#include <iostream>

#include "Constant.h"

using namespace std;

Constant::Constant(double v) : value(v)
{
    //ctor
}

Constant::~Constant()
{
    //dtor
}

double Constant::evaluate() {
    return value;
}

void Constant::print() {
    cout << " ( " << value << " ) ";
}
