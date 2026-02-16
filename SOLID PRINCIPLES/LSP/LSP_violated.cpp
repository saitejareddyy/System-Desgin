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
        throw logic_error("Withdrawals are not allowed in Fixed Term Account until maturity.");
    }
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void processTransactions(){
        for(auto account: accounts){
            account->deposit(1000);
            //Assuming allcoounts supports withdrawal (LSP violation)
            try {
                account->withdraw(500);
            }
            catch(const logic_error& e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient (accounts);
    client->processTransactions(); // Throws exception when withdrawing from FixedTermAccount
    return 0;
}