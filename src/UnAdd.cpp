#include <iostream>

#include "UnAdd.h"

using namespace std;

UnAdd::UnAdd(Expression* e) : UnOp(e)
{
    //ctor
}

UnAdd::~UnAdd()
{
    //dtor
}

double UnAdd::evaluate() {
    return exp->evaluate();
}

void UnAdd::print() {
    cout << "+ ( ";
    exp->print();
    cout << " ) ";
}
