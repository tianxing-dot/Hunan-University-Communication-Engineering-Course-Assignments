// 奇数步爬楼梯
#include <iostream>
using namespace std;
int stairs(
int n
);  //请补充完整的函数声明语句
int main() {
    int n = 0;
    cin >> n;
    cout << stairs(
n
); //请补充完整的函数调用语句
    return 0;
}
//以下方框中请补充完整的函数定义

int stairs(int n)
{
if (n == 1) return 1;
else if (n == 2) return 1;
else
{
int p1o = 0, p1j = 1;
int p2o = 1, p2j = 1;
int ce,co;
for (int i = 3; i <= n; i++) 
{
ce = p2j + p1j;
co = p2o + p1o;
p1o = p2o;
p1j = p2j;
p2o = ce;
p2j = co;
}
return p2j;
}
}
