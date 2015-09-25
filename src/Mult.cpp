#include <iostream>
#include "Mult.h"

using namespace std;

Mult::Mult(Expression* l,Expression* r) : BinOp(l,r)
{
    //ctor
}

Mult::~Mult()
{
    //dtor
}

double Mult::evaluate() {
    return leftExp->evaluate() * rightExp -> evaluate();
}

void Mult::print() {
    cout << " ( ";
    leftExp -> print();
    cout << " ) *";
    cout << " ( ";
    rightExp -> print();
    cout << " ) ";
}
