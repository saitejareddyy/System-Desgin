#include<bits/stdc++.h>
using namespace std;


class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing basic Burger for you..."<<endl;
    }
};

class StandardBurger : public Burger {
public: 
    void prepare() override {
        cout<<"Preparing standard burger for you..."<<endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Premium Burger for you..."<<endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }
        else if(type == "standard"){
            return new StandardBurger();
        }
        else if(type == "premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid Burger type"<<endl;
            return nullptr;
        }
    } 
};

int main(){
    string type = "standard";
    BurgerFactory* myBurgerfactory = new BurgerFactory();
    Burger* burger = myBurgerfactory->createBurger(type);
    burger->prepare();
    return 0;
}