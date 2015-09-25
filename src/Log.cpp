#include <math.h>
#include <iostream>

#include "Log.h"

using namespace std;

Log::Log(Expression* e,double b) : UnOp(e),base(b)
{
    //ctor
}

Log::~Log()
{
    //dtor
}

double Log::evaluate() {
    return log(exp->evaluate())/log(base);
}
void Log::print() {
    cout << "log_" << base << "( ";
    exp->print();
    cout << " ) ";
}
