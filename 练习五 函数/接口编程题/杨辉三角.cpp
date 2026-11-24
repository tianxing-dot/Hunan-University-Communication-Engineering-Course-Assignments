// 杨辉三角
#include "yang.h"
using namespace std;
void PrintBlank(int num)
{
	for (int m=1;m<=num;m++)
	{
		cout<<" ";
	}
}
void PrintCombine(int n)
{
	int first=1;
	for (int p=0;p<n;p++)
	{
		if (p==0)
		{
			cout<<first<<" ";
			continue;
		}
		else
		{
			int next=first*(n-p)/p;
			first=next;
			cout<<next<<" ";
		}
	}
}
