// 细胞分裂
#include <iostream>
using namespace std;
int totalCells(
int
);  //请补充完整的函数声明语句
int main() {
    int n = 0;
    cin >> n;
    cout << totalCells(
n
); //请补充完整的函数调用语句
    return 0;
}
//以下方框中请补充完整的函数定义

int totalCells(int n)
{
int s1=1,s2=2,s3=4,s=0;
if (n==1)
{
return 1;
}
else if (n==2)
{
return 2;
}
else if (n==3)
{
return 4;
}
for (int i=3;i<n;i++)
{
s=s3+s2+s1;
s1=s2;
s2=s3;
s3=s;
}
return s;
}
