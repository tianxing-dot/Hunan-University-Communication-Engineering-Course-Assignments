// 贪心的阿迪
#include<iostream>
using namespace std;

int main()
{
	int n,k,M,D;
	cin>>n>>k>>M>>D;
	int min=(n/k)/D;
	if (n!=min*k*D)
	{
		min++;
	}
	int get[k]={0};
	int time=0;
	int max=0;
	for (int i=min;i<=M;i++)
	{
		int flag=true;
		int n_time=n;
		while(flag)
		{
			get[time]+=i;
			time++;
			n_time-=i;
			if (time==k)
			{
				time=0;
			}
			if (n_time<i)
			{
				flag=false;
			}
		}
		time=0;
		if (max<get[0])
		{
			max=get[0];
		}
		for (int j=0;j<k;j++)
		{
			get[j]=0;
		}
	}
	cout<<max;
}
