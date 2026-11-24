// 机器人游戏
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int len=s.length();
		int n=0,place=0;
		bool flag=true;
		for (int j=0;j<len;j++)
		{
			if (s[j]>='1'&&s[j]<='9')
			{
				if (n==0)
				{
					n=s[j]-'0';
					place=j;
				}
				else
				{
					if (j-place<=n+(s[j]-'0'))
					{
						flag=false;
						cout<<"unsafe"<<endl;
						break;
					}
					else
					{
						n=s[j]-'0';
						place=j;
					}
				}
			}
		}
		if (flag)
		{
			cout<<"safe"<<endl;
		}
	}
}
