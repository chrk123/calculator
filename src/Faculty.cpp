#include <math.h>
#include <iostream>

#include "Faculty.h"

using namespace std;

Faculty::Faculty(Expression* exp) : UnOp(exp)
{
    //ctor
}

Faculty::~Faculty()
{
    //dtor
}

int Faculty::fac(int n) {
  if(n == 0 || n == 1)
    return 1;

  return ( fac(n-1) * n );
}

double Faculty::evaluate() {

    double temp = exp->evaluate();
    if(temp < 0 || floor(temp) != temp)
      throw runtime_error("faculty is only defined for natural numbers!");

    return (double) fac(temp);
}

void Faculty::print() {
    cout << " ( ";
    exp -> print();
    cout << " )! ";
}
