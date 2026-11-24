// 苹果和虫子
#include<iostream>
using namespace std;

int main()
{
    int n,x,y,s;
    cin>>n>>x>>y;
    if (y%x==0)
    {
        s=n-y/x;
    }
    else
    {
        s=n-(y/x)-1;
    }
    if (n<=(y/x))
    {
        s=0;
    }
    cout<<s;
}
