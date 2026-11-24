// 四个数排序
#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if (a<=b);
	else 
	{
	    e = a;
	    a = b;
	    b = e;
    }
    if (c<=d);
    else
    {
    	e = c;
    	c = d;
    	d = e;
	}
	if (a<=c);
	else
	{
		e = a;
		a = c;
		c = e;
	}
	if (b<=d);
	else
	{
		e = b;
		b = d;
		d = e;
	}
	if (b<=c);
	else
	{
		e = b;
		b = c;
		c = e;
	}
	cout<<d<<" "<<c<<" "<<b<<" "<<a<<endl; 
}
