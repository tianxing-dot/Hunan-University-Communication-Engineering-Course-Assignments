// 三个人比大小
#include<iostream>
using namespace std;

int main()
{
	int a1,b1,c1,a2,b2,c2,a3,b3,c3,s1,s2,s3;
	cin>>a1>>b1>>c1;
	cin>>a2>>b2>>c2;
	cin>>a3>>b3>>c3; 
	s1 = 10000*a1+100*b1+c1;
	s2 = 10000*a2+100*b2+c2;
	s3 = 10000*a3+100*b3+c3;
	if (s1<s2&&s1<s3)
	{
		if(s2<s3)
		    cout<<"ABC";
		else
		    cout<<"ACB";
	}
	else if (s1<s2&&s1>s3)
	{
		cout<<"CAB";
	}
	else if (s3<s2&&s2<s1)
	{
		cout<<"CBA";
	}
	else if (s2<s1&&s1<s3)
	{
		cout<<"BAC";
	}
	else if (s2<s3&&s3<s1)
	{
		cout<<"BCA";
	}
}
