// 最赚钱的一天
#include <iostream>
using namespace std;

int main()
{
	int n=0,C=0,S=0,money=0,day=1,get=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>C>>S;
		get = S-C;
		if (money==0)
			money = get;
		else if (money!=0&&get>=money)
		{
			money = get;
			day = i;
	    }
	}
	cout<<day;
}
