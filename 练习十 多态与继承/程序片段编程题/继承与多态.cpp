// 继承与多态
#include <iostream>
#include <string>
using namespace std; 

class Animal {
public:
   
virtual 
void speak() const {
        cout << "Some animal sound" << endl;
    }
   
virtual ~Animal(){cout<<"Animal destructed"<<endl;}

};

class Dog : public Animal {
public:
    void speak() const  {
        cout << "Woof!" << endl;
    }
    ~Dog(){cout<<"Dog destructed"<<endl;}
};

class Cat : public Animal {
public:
    void speak() const  {
        cout << "Meow!" << endl;
    }
    ~Cat(){cout<<"Cat destructed"<<endl;}
};

int main() {
    int n,m;
    cin>>n;
    Animal* myAnimal=NULL; //基类指针 
    for(int i=0;i<n;i++){
        cin>>m;
        if(m==0) myAnimal = new Animal();//创建基类对象 
        if(m==1) myAnimal = new Dog();//创建Dog对象 
        if(m==2) myAnimal = new Cat();//创建Cat对象 
        myAnimal->speak(); //调用speak函数 
        delete myAnimal;  //释放当前对象            
    }
    return 0;
}
