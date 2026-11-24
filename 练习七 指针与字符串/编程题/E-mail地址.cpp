// E-mail地址
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int count=0;
	int len=s.length();
	for (int i=0;i<len;i++)
	{
		if (s[i]!='@')
		{
			continue;
		}
		int before_count=0;
		for (int j=i-1;j>=0;j--)
		{
			if (!((s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9')||(s[j]=='_')))
			{
				break;
			}
			if (s[j]>='a'&&s[j]<='z')
			{
				before_count++;
			}
		}
		if (before_count==0)
		{
			continue;
		}
		size_t pot=s.find('.',i+1);
		if ((pot==i+1)||(pot==string::npos))
		{
			continue;
		}
		bool next_before=true;
		for (int j=i+1;j<pot;j++)
		{
			if (!((s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9')||(s[j]=='_')))
			{
				next_before=false;
				break;
			}
		}
		if (!next_before)
		{
			continue;
		}
		if (pot+1>=len)
		{
			continue;
		}
		int next_count=0;
		for (int j=pot+1;j<len;j++)
		{
			if ((s[j]>='a'&&s[j]<='z'))
			{
				next_count++;
			}
			else
			{
				break;
			}
		}
		count+=before_count*next_count;
	}
	cout<<count;
}
