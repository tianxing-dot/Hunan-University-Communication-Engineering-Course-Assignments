// 三个数
#include <iostream>
using namespace std;
int main()

{
	int x1,x2,x3,x4,t,a,b,c,d;
    cin>>x1>>x2>>x3>>x4;
    if(x1<=x2)
    {
        t=x1;x1=x2;x2=t;
    }
    if(x1<=x3)
    {
        t=x1;x1=x3;x3=t;
    }if(x1<=x4)
    {
        t=x1;x1=x4;x4=t;
    }
    a=x1-x2;b=x1-x3;c=x1-x4;
    if(c<=b)
    {
        t=c;c=b;b=t;
    }
    if(c<=a)
    {
        t=c;c=a;a=t;
    }
    if(b<=a)
    {
        t=b;b=a;a=t;
    }
    cout<<a<<" "<<b<<" "<<c;
}
