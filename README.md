# calculator
An object orientied, tree based, calculator that was built around a recursive descent parser for arithmetical expressions

It is written in C++11 and currently supports the following operations:

**binary operators:** +,\*,-,/,^  
**unary operators:** +,-,!(postfix)
**functions:** *sin,cos,tan,asin,acos,atan,sinh,cosh,tanh,log,log[BASE],sqrt*  

## Examples
  => 2+4\*3  
  == 14<br/><br/>
  => asin sin 0.5  
  == 0.5<br/><br/>
  => (2+4)\*3  
  == 18<br/><br/>
  => sin(1.57079)  
  == 1<br/><br/>
  => log[2]\(2^10)  
  == 10<br/><br/>
  => (log[3.6]\(10) + 43*3 - atan(0.5)) / 2  
  == 65.167<br/><br/>
