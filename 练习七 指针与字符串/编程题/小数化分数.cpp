// 小数化分数
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

long long yuefen(long long a,long long b)
{
	while (b!=0)
	{
		long long tem=b;
		b=a%b;
		a=tem;
	}
	return a;
}
long long fm_num(int k)
{
	long long start=1;
	for (int i=0;i<k;i++)
	{
		start*=10;
	}
	return start;
 } 
int main()
{
	int N;
	cin>>N;
	for (int i=0;i<N;i++)
	{
		string s;
		cin>>s;
		s=s.substr(2);
		size_t left=s.find('(');
		string no_repeat;
		string repeat;
		if (left!=string::npos)
		{
			no_repeat=s.substr(0,left);
			repeat=s.substr(left+1,s.find(')')-left-1);
		}
		else
		{
			no_repeat=s;
		}
		long long fz,fm;
		int n=no_repeat.size();
		int m=repeat.size();
		if (m==0)
		{
			long long num=atoll(no_repeat.c_str());
			fz=num;
			fm=fm_num(n);
		}
		else
		{
			long long A=no_repeat.empty()?0:atoll(no_repeat.c_str());
			long long B=atoll((no_repeat+repeat).c_str());
			fz=B-A;
			fm=fm_num(n)*(fm_num(m)-1);
		}
		long long g=yuefen(fz,fm);
		fm/=g;
		fz/=g;
		cout<<fz<<"/"<<fm<<endl;
	}
}
