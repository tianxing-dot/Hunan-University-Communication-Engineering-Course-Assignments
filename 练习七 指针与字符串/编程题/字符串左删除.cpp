// 字符串左删除
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int s1_num=s1.length();
	int s2_num=s2.length();
	int num=0;
	bool flag=true;
	if (s1[s1_num-1]!=s2[s2_num-1])
	{
		flag=false;
	}
	else
	{
		num++;
	}
	for (int i=s1_num-2,j=s2_num-2;i>=0,j>=0;i--,j--)
	{
		if (!flag)
		{
			break;
		}
		if (s1[i]!=s2[j])
		{
			flag=false;
		}
		else
		{
			num++;
		}
	}
	int sum=s1_num+s2_num-num-num;
	cout<<sum;
}
