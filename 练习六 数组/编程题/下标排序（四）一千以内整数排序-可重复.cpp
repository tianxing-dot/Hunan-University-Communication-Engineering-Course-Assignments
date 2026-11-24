// 下标排序（四）一千以内整数排序-可重复
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int m[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>m[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (m[i]<m[j])
			{
				int s=m[i];
				m[i]=m[j];
				m[j]=s;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<m[i];
		if (i!=n-1)
		{
			cout<<" ";
		}
	}
}
