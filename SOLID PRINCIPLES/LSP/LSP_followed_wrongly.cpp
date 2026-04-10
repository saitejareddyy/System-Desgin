#include<bits/stdc++.h>
using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account {
private:
    double balance;
public:
    SavingsAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Deposited $"<<amount<<" to Savings Account. New Balance: $"<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"Withdrew $"<<amount<<" from Savings Account. New Balance: $"<<balance<<endl;
        }
        else{
            cout<<"Insufficient funds in Savings Account. Current Balance: $"<<balance<<endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;
public:
    CurrentAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Deposited $"<<amount<<" to Current Account. New Balance: $"<<balance<<endl;
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"Withdrew $"<<amount<<" from Current Account. New Balance: $"<<balance<<endl;
        }
        else{
            cout<<"Insufficient funds in Current Account. Current Balance: $"<<balance<<endl;
        }
    }
};

class FixedTermAccount : public Account {
private:
    double balance;
public:
    FixedTermAccount(){
        balance = 0;
    }

    void deposit(double amount){
        balance += amount;
        cout<<"Deposited $"<<amount<<" to Fixed Term Account. New Balance: $"<<balance<<endl;
    }

    void withdraw(double amount){
        throw logic_error("Withdrawals are not allowed from Fixed Term Account until maturity.");
    }
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accouts){ 
        this->accounts = accouts;
    }
    void processTransactions(){
        for(auto acc: accounts){
            acc->deposit(1000);
            
            //Checking account type explicitly 

            if(typeid(*acc) == typeid(FixedTermAccount)){
                cout<<"Skipping withdrawl for Fixed Term Account.\n";
            }
            else{
                try{
                    acc->withdraw(500);
                }
                catch(const logic_error& e){
                    cout<<"Exception: "<<e.what()<<endl;
                }
            }
        }
    }

};

int main(){
    vector<Account*> accounts;
    SavingsAccount* savings = new SavingsAccount();
    CurrentAccount* current = new CurrentAccount();
    FixedTermAccount* fixed = new FixedTermAccount();
    accounts.push_back(savings);
    accounts.push_back(current);
    accounts.push_back(fixed);
    BankClient* client = new BankClient(accounts);
    client->processTransactions();
    delete client;
    delete savings;
    delete current;
    delete fixed;
    return 0; 
}


//### If the client includes a Fixed Deposit account and tries to withdraw from it, an error is thrown, which violates the Liskov Substitution Principle (LSP).

//### To handle this situation, we could modify the client code by adding an if-else condition to prevent withdrawals from FixedDepositAccount:

    //1. This may work, but abstraction suggests the client should not need to know what happens inside methods or classes.
    
    //2. It is bad practice and leads to tight coupling.
    
    //3. In the future, if we add another account type with different restrictions, we would again need to modify the client code.
    
    //4. Most importantly, this situation breaks the Open–Closed Principle (OCP).
