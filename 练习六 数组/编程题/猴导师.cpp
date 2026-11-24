// 猴导师
#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int R[n]={0};
	int sum[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>R[i];
	}
	int R1,R2;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (R[i]>R[j])
			{
				sum[i]++;
			}
		}
	}
	for (int i=0;i<k;i++)
	{
		cin>>R1>>R2;
		if (R[R1-1]>R[R2-1])
		{
			sum[R1-1]--;
		}
		if (R[R1-1]<R[R2-1])
		{
			sum[R2-1]--;
		}
	}
	for (int i=0;i<n;i++)
	{
		cout<<sum[i]<<" ";
	}
	
}
