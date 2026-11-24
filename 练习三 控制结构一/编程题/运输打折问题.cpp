// 运输打折问题
#include<iostream>
using namespace std;

int main()
{
	int a,s;
	cin>>a>>s;
	if (s<250)
		cout<<s*a;
	else if (s<500)
		cout<<s*a*0.98;
	else if (s<1000)
		cout<<s*a*0.95;
	else if (s<2000)
		cout<<s*a*0.92;
	else if (s<3000)
		cout<<s*a*0.9;
	else
		cout<<s*a*0.85; 
}
