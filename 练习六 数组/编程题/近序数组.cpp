// 近序数组
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
	bool flag=false;
	if (n>4)
	{
		for (int i=1;i<n;i++)
		{
			bool pre=true;
			bool nex=true;
			if (i>=3)
			{
				int cur_pre=num[1]-num[0];
				for (int j=2;j<i;j++)
				{
					if ((((cur_pre>0)&&(num[j]-num[0]>=cur_pre))||((cur_pre<0)&&(num[j]-num[0]<=cur_pre)))||cur_pre==0)
					{
						cur_pre=num[j]-num[0];
					}
					else
					{
						pre=false;
						break;
					}
				}
			}
			if (i<=n-3)
			{
				int cur_nex=num[i+1]-num[i];
				for (int j=i+2;j<n;j++)
				{
					if ((((cur_nex>0)&&(num[j]-num[i]>=cur_nex))||((cur_nex<0)&&(num[j]-num[i]<=cur_nex)))||cur_nex==0)
					{
						cur_nex=num[j]-num[0];
					}
					else
					{
						nex=false;
						break;
					}
				}
			}
			if (pre&&nex)
			{
				flag=true;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	if ((flag)||(n<=4))
	{
		cout<<"Yes";
	}
	else if ((flag==false)&&(n>4))
	{
		cout<<"No";
	}
}
