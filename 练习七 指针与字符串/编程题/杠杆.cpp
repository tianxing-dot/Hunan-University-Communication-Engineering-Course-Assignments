// 杠杆
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int len=s.length();
		int j=s.find("^");
		int sum_left=0,sum_right=0;
		for (int s_left=j-1;s_left>=0;s_left--)
		{
			if (s[s_left]>='1'&&s[s_left]<='9')
			{
				sum_left+=(s[s_left]-'0')*(j-s_left);
			}
		}
		for (int s_right=j+1;s_right<len;s_right++)
		{
			if (s[s_right]>='1'&&s[s_right]<='9')
			{
				sum_right+=(s[s_right]-'0')*(s_right-j);
			}
		}
		if (sum_left==sum_right)
		{
			cout<<"balance"<<endl;
		}
		else if (sum_left>sum_right)
		{
			cout<<"left"<<endl;
		}
		else if (sum_left<sum_right)
		{
			cout<<"right"<<endl;
		}
	}
}
