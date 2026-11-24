// 矩阵相加
#include <iostream>
using namespace std;
class Matrix
{
public:
    
Matrix() {}
Matrix operator+(const Matrix &m) const {
Matrix res;
for (int i = 0; i < 2; ++i) {
  for (int j = 0; j < 3; ++j) {
     res.mat[i][j] = this->mat[i][j] + m.mat[i][j];
     }
    }
   return res;
 }
friend istream& operator>>(istream &in, Matrix &m);
friend ostream& operator<<(ostream &out, const Matrix &m);

private:
    int mat[2][3];
};


istream& operator>>(istream &in, Matrix &m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            in >> m.mat[i][j];
        }
    }
    return in;
}
ostream& operator<<(ostream &out, const Matrix &m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << m.mat[i][j];
            if (j != 2) out << " "; // 每行内元素用空格分隔
        }
        if (i != 1) out << endl; // 行与行用换行分隔
    }
    return out;
}


int main()
{
    Matrix a, b, c;
    cin >> a >> b;
        c=a+b;
    cout<<c;
    return 0;
}
