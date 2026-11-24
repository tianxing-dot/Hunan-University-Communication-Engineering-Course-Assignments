// 游泳训练时间计算
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a,b,c,d,e,f,h,m,s;
    char g;
    cin>>a>>g>>b>>g>>c>>d>>g>>e>>g>>f;
    h = d-a;
    m = e-b;
    s = f-c;
    if (m>=0)
    {
        if(s>=0)
        {
            
        }
        else
        {
            m -=1;
            s +=60;
        }
    }
    else
    {
        h -=1;
        m +=60;
        if(s>=0)
        {
            
        }
        else
        {
            m -=1;
            s +=60;
        }
    }
    cout<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
    return 0;
}

