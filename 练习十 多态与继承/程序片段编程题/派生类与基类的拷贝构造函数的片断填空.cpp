// 派生类与基类的拷贝构造函数的片断填空
#include"iostream"
using namespace std;
class A 
{    int x; 
  public: A(const A& a){x=a.x;cout<<"A(const A&)\n";} 
  A(){cout<<"A()";} 
  A(int a){x=a;cout<<"A(int a)\n";} 
  void display()
{cout<<x;}
};
class B: public A
{         int y;
    public:
B(int x1,int y1)
:A(x1)
{y=y1;}
        B(const B& b)
:A(b)

        {y = b.y;}
       void display()
{cout<<y<<",";A::display();}
     
}; 
int main(){
B b1(2,10);
B b2(b1); 
b2.display();
}
