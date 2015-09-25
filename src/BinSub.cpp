#include <iostream>
#include "BinSub.h"

using namespace std;

BinSub::BinSub(Expression* l,Expression* r) : BinOp(l,r)
{
    //ctor
}

BinSub::~BinSub()
{
    //dtor
}

double BinSub::evaluate() {
    return leftExp->evaluate() - rightExp->evaluate();
}

void BinSub::print() {
    cout << " ( ";
    leftExp -> print();
    cout << " ) -";
    cout << " ( ";
    rightExp -> print();
    cout << " ) ";
}
