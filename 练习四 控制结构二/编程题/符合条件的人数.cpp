// 符合条件的人数
#include <iostream>
using namespace std;

int main()
{
	int n=0,high=0,man=0,woman=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>high;
		if (high>=178&&high<=180)
			man++;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>high;
		if (high>=168&&high<=170)
			woman++;
	}
	cout<<man<<" "<<woman;
}
