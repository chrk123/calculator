#include "UnOp.h"

UnOp::UnOp(Expression* e) : exp(e)
{
    //ctor
}

UnOp::~UnOp()
{
    delete(exp);
}
