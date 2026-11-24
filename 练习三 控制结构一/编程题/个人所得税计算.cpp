// 个人所得税计算
#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if ((a-b)<=5000)
		cout<<"0";
	else if ((a-b-5000)<=3000)
    	cout<<(a-b-5000)*0.03;
    else if ((a-b-5000)<=12000)
    	cout<<((a-b-5000)*0.1-210);
    else if ((a-b-5000)<=25000)
        cout<<((a-b-5000)*0.2-1410);
    else if ((a-b-5000)<=35000)
    	cout<<((a-b-5000)*0.25-2660);
    else if ((a-b-5000)<=55000)
    	cout<<((a-b-5000)*0.3-4410);
    else if ((a-b-5000)<=80000)
    	cout<<((a-b-5000)*0.35-7160);
    else
    	cout<<((a-b-5000)*0.45-15160);
    return 0;
}
