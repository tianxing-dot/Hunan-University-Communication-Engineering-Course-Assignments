// 继承与多态2
#include <iostream>
#include <string>
using namespace std;

// 抽象类：技能 (Skill)
class Skill {
public:
    // 纯虚函数：使用技能（每个具体技能都必须有自己的实现）
    virtual void cast() const = 0;

    // 纯虚函数：获取技能描述
    virtual string getDescription() const = 0;

    // 虚析构函数（重要！确保派生类对象被正确释放）
    virtual ~Skill() = default;

    // 非纯虚函数，可以有默认实现
    virtual void onCooldown() const {
        cout << "The skill is comming down..." << endl;
    }
};
// 具体技能1：火球术
class Fireball : public Skill {
public:
    void cast() const  {
        cout << "Send a fireball。" << endl;
    }

    string getDescription() const  {
        return "Higher fire magic。";
    }
    //析构函数
    ~Fireball() {cout<<"Fireball destructed"<<endl;    }
};

// 具体技能2：治疗术
class Heal : public Skill {
public:
    void cast() const  {
        cout << "Send sunsine。" << endl;
    }

    string getDescription() const  {
        return "Revive magic。";
    }

    // 可以重写基类的默认行为
 
void onCooldown() const override{
   cout<<"Revive magic skill is comming down..."<<endl;}

    //析构函数
    ~Heal() { cout<<"Heal destructed"<<endl;    }
};
void show(
Skill* sp
){
        sp->cast(); // 调用cast()函数 
        cout << "Description: " << sp->getDescription() << endl;
        sp->onCooldown();
} 
int main() {
    int n,m;
    cin>>n;
    
    Skill**  playerSkills=new Skill*[n];
    for(int i=0;i<n;i++){
        cin>>m;
        if(m==1) playerSkills[i] = new Fireball(); 
        if(m==2) playerSkills[i] = new Heal();
    }
   

    // 模拟技能释放
    for (int i = 0; i < n; ++i) {
        show(playerSkills[i]); 
    }

    // 释放对象 
    for (int i = 0; i < n; ++i) {
        delete playerSkills[i];
    }
    delete[] playerSkills;//释放指针数组 
   
    return 0;
}
