// 第m趟冒泡排序的结果
#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int num[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n-1-i;j++)
		{
			if (num[j]>num[j+1])
			{
				int d=num[j];
				num[j]=num[j+1];
				num[j+1]=d;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<num[i]<<" ";
	}
}
