// 程序片段题B1
#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
 
    // 获取实部和虚部
    double getReal() const { return real; }
    double getImag() const { return imag; }
 
    
    // 重载乘法运算符
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
 
   
   
friend ostream& operator<<(ostream& out, const Complex& c)
{
out << c.real << " + " << c.imag << "i";
return out;
}
friend istream& operator>>(istream& in, Complex& c)
{
in >> c.real >> c.imag;
return in;
}
Complex operator+(const Complex& other) const {
return Complex(real + other.real, imag + other.imag);
}
Complex operator-(const Complex& other) const {
return Complex(real - other.real, imag - other.imag);
}

 
   
};
 
int main() {
    Complex c1, c2, c3;
 
    // 从标准输入读取两个复数
   
    cin >> c1;    
    cin >> c2;
 
    // 使用重载的运算符进行运算
    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;
 
    c3 = c1 - c2;
    cout << "Difference: " << c3 << endl;
 
    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;
 
    return 0;
}
