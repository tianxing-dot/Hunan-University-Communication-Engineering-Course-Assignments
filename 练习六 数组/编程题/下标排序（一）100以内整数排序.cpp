// 下标排序（一）100以内整数排序
#include<iostream>
using namespace std;
int main()
{
	int num[100]={0};
	for (int i=0;i<100;i++)
	{
		cin>>num[i];
	}
	for (int i=0;i<100;i++)
	{
		for (int j=i;j<100;j++)
		{
			if (num[j]>num[i])
			{
				int tem=num[i];
				num[i]=num[j];
				num[j]=tem;
			}
		}
	}
	for (int i=0;i<100;i++)
	{
		cout<<num[i];
		if (i<99)
		{
			cout<<" ";
		}
	}
}
