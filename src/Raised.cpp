#include <math.h>
#include <iostream>

#include "Raised.h"

using namespace std;

Raised::Raised(Expression* l,Expression* r) : BinOp(l,r)
{
    //ctor
}

Raised::~Raised()
{
    //dtor
}

double Raised::evaluate() {
    return pow(leftExp->evaluate(),rightExp->evaluate());
}

void Raised::print() {
    cout << " ( ";
    leftExp -> print();
    cout << " ) ^";
    cout << " ( ";
    rightExp -> print();
    cout << " ) ";
}
