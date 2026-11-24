// 古老的语言
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	bool flag=true;
	for (int i=0;i<len-1;i++)
	{
		if (!flag)
		{
			break;
		}
		if (!(s[i]=='a'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='e'||s[i]=='n'))
		{
			if (!(s[i+1]=='a'||s[i+1]=='o'||s[i+1]=='u'||s[i+1]=='i'||s[i+1]=='e'))
			{
				flag=false;
			}
		}
	}
	if (!(s[len-1]=='a'||s[len-1]=='e'||s[len-1]=='i'||s[len-1]=='o'||s[len-1]=='u'||s[len-1]=='n'))
	{
		flag=false;
	}
	if (flag)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}	
}
