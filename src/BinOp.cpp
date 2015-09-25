#include "BinOp.h"

BinOp::BinOp(Expression* left, Expression* right):leftExp(left),rightExp(right)
{
    //ctor
}

BinOp::~BinOp()
{
    delete(leftExp);
    delete(rightExp);
}

Expression* BinOp::getLeftExp(){
    return leftExp;
}

Expression* BinOp::getRightExp(){
    return rightExp;
}
