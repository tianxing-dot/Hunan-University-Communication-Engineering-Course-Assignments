// 加密与解密
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int len=s.length();
	for (int i=1;i<=len;i++)
	{
		if (len%i==0)
		{
			reverse(s.begin()+0,s.begin()+i);
		}
	}
	cout<<s;
}
