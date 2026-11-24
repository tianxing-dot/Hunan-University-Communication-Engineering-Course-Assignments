// ch3-5 3,5,7整除
#include <iostream>
using namespace std;

int main()
{
	int a,b=0,c=0,d=0;
	cin>>a;
	if (a%3==0)
	{
		b=1;
	}
	if (a%5==0)
	{
		c=1;
	}
	if (a%7==0)
	{
		d=1;	
	}
	if ((b!=1)&&(c!=1)&&(d!=1))
	{
		cout<<"null";
	}
	else
	{
		if (b&&c&&d)
		{
		    cout<<"It's divisible by 3,5,7";
		}
		else if (b&&c)
		{
			cout<<"It's divisible by 3,5";
		}
		else if (b&&d)
		{
			cout<<"It's divisible by 3,7";
		}
		else if (c&&d)
		{
			cout<<"It's divisible by 5,7";
		}
		else if (b)
		{
			cout<<"It's divisible by 3";
		}
		else if (c)
		{
			cout<<"It's divisible by 5";
		}
		else if (d)
		{
			cout<<"It's divisible by 7";
		}
	}
}

