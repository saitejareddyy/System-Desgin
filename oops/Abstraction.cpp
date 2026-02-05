#include <bits/stdc++.h>
using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {};
};

class Sportscar: public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    Sportscar(string brand, string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<brand << " " << model << " : Engine starts with a roar"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" : Engine is off! Cannot shift gear"<< endl;
            return;
        }
        currentGear = gear;
        cout<<brand<<" "<<model<<" : shift to gear"<<currentGear<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" : Engine is off! cannot accelerate"<<endl;
            return;
        }
        currentSpeed += 20;
        cout<<brand<<" "<<model<<" : Accelerating to "<< currentSpeed << "km/h"<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<brand<<" "<<model<< " : Breaking! Speed to now " << currentSpeed<<"km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout<<brand<<" "<<model<<" : Engine turned off"<<endl;
    }

};

int main(){

    Car* mycar = new Sportscar("Ford", "Mustang");
    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->accelerate();
    mycar->shiftGear(2);
    mycar->accelerate();
    mycar->brake();
    mycar->stopEngine();
    return 0;
}