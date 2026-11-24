// 招聘
#include<iostream>
#include<vector>
using namespace std;
struct power
{
	int K;
	int I;
	int E;
};
int main()
{
	int n;
	cin>>n;
	vector<power> powers(n);
	vector<int> exp(3*n);
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>exp[j+i*n];
		}
	}
	for (int i=0;i<n;i++)
	{
		int k=exp[i],l=exp[i+n],m=exp[i+2*n];
		powers[i]={k,l,m};
	}
	int sum=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (j==i)
			{
				continue;
			}
			const power& c1=powers[i];
			const power& c2=powers[j];
			if ((c1.K<c2.K)&&(c1.E<c2.E)&&(c1.I<c2.I))
			{
				sum++;
				break;
			} 
		}
	}
	cout<<sum;
}
