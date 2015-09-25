#include <iostream>
#include "BinAdd.h"

using namespace std;

BinAdd::BinAdd(Expression* l, Expression* r) :
    BinOp(l,r) {}

BinAdd::~BinAdd()
{
    //dtor
}

double BinAdd::evaluate() {
    return leftExp->evaluate() + rightExp->evaluate();
}

void BinAdd::print() {
    cout << " ( ";
    leftExp -> print();
    cout << " ) +";
    cout << " ( ";
    rightExp -> print();
    cout << " ) ";
}
