#include <iostream>

#include "UnSub.h"

using namespace std;

UnSub::UnSub(Expression* e) : UnOp(e)
{
    //ctor
}

UnSub::~UnSub()
{
    //dtor
}

double UnSub::evaluate() {
    return -(exp->evaluate());
}
void UnSub::print() {
    cout << "- ( ";
    exp->print();
    cout << " ) ";
}
