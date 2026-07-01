#include<bits/stdc++.h>
using namespace std;


class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger {
public: 
    void prepare() override{
        cout<<"preparing basic Burger with bun"<<endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Standard Burger with Bun"<<endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing Permium Burger with bun"<<endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout<<"Preparing basic wheat burger with bun"<<endl;
    }
};

class StandardWheatBurger : public Burger {
public: 
    void prepare() override {
        cout<<"Preparing standard wheat burger with bun"<<endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override{
        cout<<"Preparing premium wheat burger with bun"<<endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        } else if(type == "standard"){
            return new StandardBurger();
        } else if(type == "premium"){
            return new PremiumBurger();
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicWheatBurger();
        } else if(type == "standard"){
            return new StandardWheatBurger();
        } else if(type == "premium"){
            return new PremiumWheatBurger();
        }
    }
};

int main(){
    string type = "standard";
    BurgerFactory* myFactory = new KingBurger();
    Burger* burger = myFactory->createBurger(type);
    burger->prepare();
 
    return 0;
}