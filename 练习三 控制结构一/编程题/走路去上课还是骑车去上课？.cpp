// 走路去上课还是骑车去上课？
#include<iostream>
using namespace std;

int main()
{
	int a;
	double s1,s2;
	cin>>a;
	s1=a/1.2;
	s2=((a/3.0)+27+23);
	if (s1<s2)
	    cout<<"Walk";
	else if (s1>s2)
		cout<<"Bike";
	else
		cout<<"All";
}
