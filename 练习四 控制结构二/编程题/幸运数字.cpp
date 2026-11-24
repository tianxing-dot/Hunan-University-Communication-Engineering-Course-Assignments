// 幸运数字
#include <iostream>
using namespace std;

int main()
{
	int n=0,m=0,sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>m;
		if ((m%4==0)||(m%7==0))
			sum += m;
		else
			sum += 0;
	}
	cout<<sum;
}
