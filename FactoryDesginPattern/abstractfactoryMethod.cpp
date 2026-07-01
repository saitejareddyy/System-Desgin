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

//--- Product 2 Garlic Bread
class GarlicBread {
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {};
};

class BasicGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing BasicGarlicBread..."<<endl;
    }
};
class StandardGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing Standard GarlicBread..."<<endl;
    }
};

class PremiumGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing Premium GarlicBread..."<<endl;
    }
};

class BasicWheatGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing Basic wheat GarlicBread..."<<endl;
    }
};

class StandardWheatGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing Standard Wheat GarlicBread..."<<endl;
    }
};

class PremiumWheatGarlcBread : public GarlicBread {
public:
    void prepare() override {
        cout<<"Preparing Premium Wheat GarlicBread..."<<endl;
    }
};

class MealFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type) = 0;
};

class SinghBurger : public MealFactory {
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
    GarlicBread* createGarlicBread(string& type){
        if(type == "basic"){
            return new BasicGarlcBread();
        } else if(type == "standard"){
            return new StandardGarlcBread();
        } else if(type == "premium"){
            return new PremiumGarlcBread();
        }
    }
};

class KingBurger : public MealFactory {
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
    GarlicBread* createGarlicBread(string& type){
        if(type == "basic"){
            return new BasicWheatGarlcBread();
        } else if(type == "standard"){
            return new StandardWheatGarlcBread();
        } else if(type == "premium"){
            return new PremiumWheatGarlcBread();
        }
    }
};

int main(){
    string type = "standard";
    MealFactory* myFactory = new SinghBurger();
    Burger* burger = myFactory->createBurger(type);
    GarlicBread* garlicBread = myFactory->createGarlicBread(type);
    burger->prepare();
    garlicBread->prepare();
 
    return 0;
}