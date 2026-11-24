// 数小木块
#include <iostream>
using namespace std;

int main()
{
	int n=0,sum=0,sum1=0,sum2=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		sum =sum1+sum2+i;
		sum2 +=i;
		sum1 =sum;
	}
	cout<<sum;
}
