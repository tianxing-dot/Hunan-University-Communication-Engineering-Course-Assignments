// 下标排序（二）一千以内整数排序
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int num[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (num[j]>num[i])
			{
				int tem=num[i];
				num[i]=num[j];
				num[j]=tem;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<num[i];
		if (i<n-1)
		{
			cout<<" ";
		}
	}
}
