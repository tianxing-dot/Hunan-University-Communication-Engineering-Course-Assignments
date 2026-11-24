// 求一个数的位数
#include <iostream>
using namespace std;

int main()
{
	int n=0,m=0;
	cin>>n;
	for (int i=0;i>=0;i++)
	{
		n=n/10;
		m++;
		if (n>=1)
			continue;
		else
			break;
	}
	cout<<m;
}
