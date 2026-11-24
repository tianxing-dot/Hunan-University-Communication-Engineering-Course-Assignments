// 坐标格式化处理
#include<iostream>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3;
    char ch;
    cin>>ch>>x1>>ch>>y1>>ch>>ch>>ch
        >>x2>>ch>>y2>>ch>>ch>>ch>>x3
        >>ch>>y3>>ch;
    cout<<"["<<x1<<","<<y1<<"]"<<'\n'
        <<"["<<x2<<","<<y2<<"]"<<'\n'
        <<"["<<x3<<","<<y3<<"]"<<endl;
    return 0;
}
