// 小芳找工作
#include<iostream>
using namespace std;
int main()
{
	int t1,t3;
	char t2;
	int ret=0;
	cin>>t1>>t2>>t3;
	if (t1>=5000)
	{
		ret++;
	}
	if (t2=='y')
	{
		ret++;
	}
	if (t3<=2000)
	{
		ret++;
	}
	if (ret>=2)
	{
		cout<<"Accept";
	}
	else
	{
		cout<<"Refuse";
	}
}
