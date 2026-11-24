// 下标排序（三）字符排序
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char get[n];
	for (int i=0;i<n;i++)
	{
		cin>>get[i];
	}
	char tem='0';
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (get[j]>get[i])
			{
				tem=get[i];
				get[i]=get[j];
				get[j]=tem;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<get[i];
	}
}
