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

int main(){
    Customer obj1("saiteja", 123456789, 69);
    obj1.get_info();
    return 0;
}