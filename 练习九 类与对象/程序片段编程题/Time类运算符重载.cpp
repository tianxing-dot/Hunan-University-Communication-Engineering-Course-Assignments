// Time类运算符重载
#include <iostream>
using namespace std;
class Time
{public:
   Time(){hour=0;minute=0;sec=0;}
   Time(int h,int m,int s):hour(h),minute(m),sec(s){}
   Time operator++();
   Time operator++(int );   
   friend ostream& operator << (ostream&,Time&);
  private:
   int hour; 
   int minute;
   int sec;
 };


ostream& operator << (ostream& out, Time& t)
{
out << t.hour << ":" << t.minute << ":" << t.sec << endl;
return out;
}
Time Time::operator++()
{
sec++;
if (sec >= 60) {
sec -= 60;
minute++;
if (minute >= 60) {
minute -= 60;
hour++;
if (hour >= 24) {
hour = 0;
}
}
}
return *this;
}

Time Time::operator++(int )
{
Time temp = *this;
sec++;
if (sec >= 60) {
      sec -= 60;
      minute++;
      if (minute >= 60){
          minute -= 60;
          hour++;
          if (hour >= 24) {
              hour = 0;
          }
       }
  }
    return temp;
}


int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  Time time1(a,b,c),time2;
  cout<<time1;
  time2=++time1;
  cout<<time2;
  time2=time1++;
  cout<<time2;
  cout<<time1;
  return 0;
}
