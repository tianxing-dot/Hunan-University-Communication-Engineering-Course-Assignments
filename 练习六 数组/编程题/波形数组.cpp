// 波形数组
#include<iostream>
using namespace std;
int main()
{
	int T,n;
	cin>>T;
	int jieguo[T]={0};
	for (int i=0;i<T;i++)
	{
		cin>>n;
		int num[n]={0};
		for (int j=0;j<n;j++)
		{
			cin>>num[j];
		}
		int flag=true;
		if (n>=3)
		{
			for (int s=1;s<n-1;s++)
			{
				int pre=num[s-1];
				int cur=num[s];
				int next=num[s+1];
				bool get=((cur>pre&&cur>next)||(cur<pre&&cur<next))&&(pre!=cur)&&(cur!=next);
				if (!get)
				{
					flag=false;
					break;
				}
			}
		}
		if (flag)
		{
			jieguo[i]=1;
		}
		else
		{
			jieguo[i]=0;
		}
	}
	for(int i=0;i<T;i++)
	{
		if(jieguo[i]==1)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
} 
/*
2
6
1 2 -5 9 4 5
4
3 5 5 4
*/
