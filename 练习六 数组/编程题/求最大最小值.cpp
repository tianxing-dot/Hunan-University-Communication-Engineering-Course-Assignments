// 求最大最小值
#include<iostream>
using namespace std;

int main()
{
	int n=0,max_num=0,min_num=0;
	cin>>n;
	int num[n]={0};
	for (int i=0;i<n;i++)
	{
		cin>>num[i];
		if (i==0)
		{
			max_num=num[0];
			min_num=num[0];
		}
		else
		{
			if (max_num<num[i])
			{
				max_num=num[i];
			}
			if (min_num>num[i])
			{
				min_num=num[i];
			}
		}
	}
	cout<<max_num<<" "<<min_num;
	 
}
