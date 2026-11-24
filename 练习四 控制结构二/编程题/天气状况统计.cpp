// 天气状况统计
#include <iostream>
using namespace std;

int main()
{
    int N=0,day=0,day1=0,day2=0,day3=0,day4=0,day5=0,day6=0;
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        cin>>day;
        switch(day)
        {
            case 1:day1 ++;break;
            case 2:day2 ++;break;
            case 3:day3 ++;break;
            case 4:day4 ++;break;
            case 5:day5 ++;break;
            case 6:day6 ++;break;
        }
    }
        cout<<"晴天: "<<day1<<endl;
        cout<<"多云: "<<day2<<endl;
        cout<<"阴天: "<<day3<<endl;
        cout<<"小雨: "<<day4<<endl;
        cout<<"中雨: "<<day5<<endl;
        cout<<"大雨: "<<day6<<endl;
    
}
