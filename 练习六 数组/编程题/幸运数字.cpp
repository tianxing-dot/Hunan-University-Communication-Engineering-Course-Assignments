// 幸运数字
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a=0;
	int sum=0;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		if ((a%4==0)||(a%7==0))
		{
			sum+=a;
		}
	}
	cout<<sum;
}
