// 计算炮弹坐标
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const float h=3000.0,v=200.0;
	const float g=9.8;
	float a,b,t;
	cin>>t;
	a = v*t;
	b = h-(g*t*t)/2;
	cout<<fixed<<setprecision(1)<<a<<","<<b<<endl;
	return 0;
}
