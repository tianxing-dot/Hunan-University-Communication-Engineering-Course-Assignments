// 最大公约数和最小公倍数
#include <iostream>

using namespace std;

int gcd(int ,int );
int lcm(int ,int );

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<gcd(x, y)<<" "<<lcm(x,y)<<endl;
    return 0;
}

int gcd(int u, int v)            
{

int result=1;
for (int i=1;(i<=u&&i<=v);i++)
{
if ((u%i==0)&&(v%i==0))
{
result=i;
}
}
return result;


}


int lcm(int u,int v)
                                                
{
    return u*v/gcd(u,v);
}
