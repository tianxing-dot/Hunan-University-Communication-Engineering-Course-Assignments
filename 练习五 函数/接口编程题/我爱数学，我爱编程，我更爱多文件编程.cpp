// 我爱数学，我爱编程，我更爱多文件编程
#include "judge.h"
bool prime(int a)
{
	if (a<=1)
		return 0;
	for (int i=2;i*i<=a;i++)
	{
		if (a%i==0)
			return 0;
	}
	return 1;
}
bool plalindrome(int a)
{
	int b=a,c=0,d=0;
	while(a>0)
	{
		d=a%10;
		c=c*10+d;
		a=a/10;
	}
	if (c==b)
		return 1;
	else
		return 0;
}
