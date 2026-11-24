// 音乐DJ和回响贝斯
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int len=s.length();
	int i=0;
	bool flag=false;
	while(i<len)
	{
		if (s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
		{
			if (flag)
			{
				cout<<" ";
				flag=false; 
			}
			i+=3;
			continue;
		}
		else
		{
			cout<<s[i];
			i++;
			flag=true;
		}
	}
}
