// 实现分数形式的有理数存储
#include <iostream>
using namespace std;

class Rational
{
//私有数据成员声明：分子,分母；    

private:
int fz;
int fm;


    public:
        Rational(int fz,int fm);//带参构造函数 （声明）
        Rational(); //普通构造函数（声明）
        Rational(const Rational& r);////拷贝构造函数（声明）         
        ~Rational();//析构函数 
        void show();

    protected:
};

//插入 带参构造函数实现 的代码

Rational::Rational(int fz,int fm)
{
this->fz=fz;
this->fm=fm;
}

Rational::Rational()
{
    this->fm=2;
    this->fz=1;
}
//插入 拷贝构造函数实现 的代码

Rational::Rational(const Rational& r)
{
this->fz=r.fz;
this->fm=r.fm;
}

Rational::~Rational()
{
}
void Rational::show()
{
    cout<<fz<<"/"<<fm<<endl; 
}
int main() {
    Rational r1;
    r1.show();
    Rational r2(3,4);
    r2.show();
    Rational r3(r2);    
    r3.show();    
    return 0;
}
