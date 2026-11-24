// 飞来飞去
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		string s;
		cin>>s;
		int time_num[2]={0};
		for (int j=1;j<num;j++)
		{
			if (s[j-1]!=s[j])
			{
				if (s[j-1]=='T')
				{
					time_num[0]++;
				}
				else
				{
					time_num[1]++;
				}
			}
		}
		if (time_num[1]>time_num[0])
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
