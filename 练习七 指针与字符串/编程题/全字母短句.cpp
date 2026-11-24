// 全字母短句
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	char alp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for (int i=0;i<n;i++)
	{
		int num[26]={0};
		string s;
		getline(cin,s);
		int len=s.length();
		for (int j=0;j<len;j++)
		{
			if(s[j]>='A'&&s[j]<='Z')
			{
				s[j]+=32;
			}
			for (int l=0;l<26;l++)
			{
				if (s[j]==alp[l])
				{
					num[l]++;
					break;
				}
			}
		}
		bool flag=true;
		for (int i=0;i<26;i++)
		{
			if (num[i]==0)
			{
				flag=false;
				break;
			}
		}
		if (flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No ";
			for (int i=0;i<26;i++)
			{
				if (num[i]==0)
				{
					char s=alp[i]-32;
					cout<<s<<" ";
				}
			}
			cout<<endl;
		}
	}
}
