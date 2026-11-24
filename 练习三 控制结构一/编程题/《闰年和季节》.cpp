// 《闰年和季节》
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int year,month;
    string a,b;
    cin>>year>>month;
    if ((year%4==0 && year%100!=0)||(year%400==0))
    {
        a="Leap year";
    }
    else
    {
        a="Common year";
    }
    if (month>=3&&month<=5)
    {
        b="Spring";
    }
    else if(month>=6&&month<=8)
    {
        b="Summer";
    }
    else if(month>=9&&month<=11)
    {
        b="Fall";
    }
    else
    {
        b="Winter";
    }
    cout<<a<<","<<b<<endl;
    return 0;
}
