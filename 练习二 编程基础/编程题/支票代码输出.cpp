// 支票代码输出
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    int code;
    float money;
    cin >> code >> money;
    cout << setw(8) << setfill('0') << code << endl;
    cout << fixed << setprecision(2) << money <<endl;
    return 0;
}
