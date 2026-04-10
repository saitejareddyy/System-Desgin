#include<bits/stdc++.h>
using namespace std;

// --- Strategy Interface for walk ---

class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Walking normally." << endl;
    }
};

class Nowalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Cannot walk." << endl;
    }
};


// --- Strategy Interface for Talk ---

class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}

};

class NormalTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Talking normally." << endl;
    }
};

class NoTalk: public TalkableRobot {
public:
    void talk() override {
        cout<< "Cannot talk." << endl;
    }
};

// --- Strategy Interface for Fly ---

class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout<< "Flying normally." << endl;
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override {
        cout<< "Cannot fly." << endl;
    }
};

class Robot {
protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour ;
public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehaviour = w;
        this->talkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk() {
        walkBehaviour->walk();
    }

    void talk() {
        talkBehaviour->talk();
    }

    void fly() {
        flyBehaviour->fly();
    }

    virtual void projection() = 0;

};


// --- Concrete Robot Types ---

class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "I am a Companion Robot." << endl;
    }
};

class WorkerRobot: public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "I am a Worker Robot." << endl;
    }
};


int main(){
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NormalFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection(); 

    cout<< "--------------------------------" << endl;

    Robot *robot2 = new WorkerRobot(new Nowalk(), new NoTalk(), new NoFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;   
}