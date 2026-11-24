// 小熊买糖果
#include <iostream>

using namespace std;
int getCandy(int, int);

int main()
{
    int k, r;
    cin>>k>>r;
 
int result=getCandy(k,r);

    cout<<result<<endl;
    return 0;
}

int getCandy(
int a,int b
)
{
    
if ((a%10==0)||(a%10==b))
{
return 1;
}
else 
{
for (int i=2;;i++)
{
if ((a*i%10==0)||(a*i%10==b))
{
return i;
}
}
}


}
