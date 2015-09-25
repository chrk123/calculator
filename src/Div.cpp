#include <iostream>

#include "Div.h"

using namespace std;

Div::Div(Expression* l,Expression* r) : BinOp(l,r)
{
    //ctor
}

Div::~Div()
{
    //dtor
}

double Div::evaluate() {
    return leftExp->evaluate() / rightExp->evaluate();
}

void Div::print() {
    cout << " ( ";
    leftExp -> print();
    cout << " ) /";
    cout << " ( ";
    rightExp -> print();
    cout << " ) ";
}
