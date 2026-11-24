// 继承与多态-片断
#include <iostream>
#include <string>
using namespace std;

class MagicCreature {
protected:
    string name;
public:
    MagicCreature(string n) : name(n) {}
    
virtual int castMagic()=0;

    virtual ~MagicCreature(){cout<<name<<" completed.\n";};
    string getName() { return name; }
};
class Dragon : 
public MagicCreature
 {
private:
    int flame;
public:
    Dragon(string n, int f) : 
MagicCreature(n),flame(f)
 {}
    int castMagic() override {
        
return 60+flame*3;
 
    }
    
~Dragon() override
{cout<<"Dragon ";}

};

class Phoenix : 
public MagicCreature
 {
private:
    int rebirth;
public:
    Phoenix(string n, int r) : 
MagicCreature(n),rebirth(r)
 {}
    int castMagic() override {
        
return 55+rebirth*4;
 
    }
    
~Phoenix() override
{cout<<"Phoenix ";}

};

class Unicorn : 
public MagicCreature
 {
private:
    int heal;
public:
    Unicorn(string n, int h) : 
MagicCreature(n),heal(h)
 {}
    int castMagic() override {
        
return 50+heal*2;
 
    }
    
~Unicorn() override
{cout<<"Unicorn ";}

};

class Elf : 
public MagicCreature
 {
private:
    int agile;
public:
    Elf(string n, int a) :
MagicCreature(n),agile(a)
 {}
    int castMagic() override {
        
return 45+agile*5;
 
    }
    
~Elf() override
{cout<<"Elf ";}

};

class Werewolf : 
public MagicCreature
 {
private:
    int strength;
public:
    Werewolf(string n, int s) :
MagicCreature(n),strength(s)
 {}
    int castMagic() override {
        
return 40+strength*1;
 
    }
    
~Werewolf() override
{cout<<"Werewolf ";}

};

class Gargoyle : 
public MagicCreature
 {
private:
    int defense;
public:
    Gargoyle(string n, int d) : 
MagicCreature(n),defense(d)
 {}
    int castMagic() override {
        
return 35+defense*6;
 
    }
    
~Gargoyle() override
{cout<<"Gargoyle ";}

    
};

int main() {
    int type, param;
    string name;
    MagicCreature* creature = nullptr;
    while(cin >> type >> name >> param)
    {
        switch (type) {
        case 1: creature = new Dragon(name, param); break;
        case 2: creature = new Phoenix(name, param); break;
        case 3: creature = new Unicorn(name, param); break;
        case 4: creature = new Elf(name, param); break;
        case 5: creature = new Werewolf(name, param); break;
        case 6: creature = new Gargoyle(name, param); break;
        }    
        cout << creature->getName() << "'s Magic score is " <<
creature->castMagic()
<<".";
        delete creature;
    }

    return 0;
}
