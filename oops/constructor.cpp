#include<bits/stdc++.h>
using namespace std;

class Customer{
private:
    string name;
    int account_number;
    int balance;
public:

    Customer(string name, int account_number, int balance){
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
    }

    void get_info(){
        cout<<"Name: "<<name<<endl;
        cout<<"AccountNumber: "<<account_number<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};


//Destructor
// It`s an instance member function that is invocked actomatically whenever an object is going to be destroyed
//It`s a last function that is going to be called before an object is destroyed



int main(){
    Customer obj1("saiteja", 123456789, 69);
    obj1.get_info();
    return 0;
}