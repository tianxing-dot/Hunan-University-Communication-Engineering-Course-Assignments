// 复数加法
#include  <iostream>
using  namespace  std;
//复数类 
class  intMyComplex{
public:    
       
 
intMyComplex(int r = 0, int i = 0) : real(r), imag(i) {}
intMyComplex operator+(const intMyComplex &c)const
{return intMyComplex(real+c.real,imag+c.imag);}
friend istream& operator>>(istream &in, intMyComplex &c);
friend ostream& operator<<(ostream &out, const intMyComplex &c);


private:
    int  real;
    int  imag;        
}; 

//补充代码

istream& operator>>(istream &in,intMyComplex &c)
{
in>>c.real>>c.imag;
return in;
}
ostream& operator<<(ostream &out,const intMyComplex &c)
{
out<<c.real<<"+"<<c.imag<<"i";
return out;
}


int  main()
{
   intMyComplex a,b;
    cin>>a;
    cin>>b;
    b=a+b; 
    cout<<b;
    return  0;
}
