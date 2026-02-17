#include<bits/stdc++.h>
using namespace std;

class NonWithdrawableAccount {
public:
    virtual void deposit(double amount) = 0;
    virtual ~NonWithdrawableAccount() = default;
};

class WithdrawableAccount: public NonWithdrawableAccount {
public:
    virtual void withdraw(double amount) = 0;
    virtual ~WithdrawableAccount() = default;
};

class SavingsAccount : public WithdrawableAccount {
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

class CurrentAccount : public WithdrawableAccount {
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

class FixedTermAccount : public NonWithdrawableAccount {
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
};

class BankClient {
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<NonWithdrawableAccount*> nonWithdrawableAccounts;
public:
    BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<NonWithdrawableAccount*> nonWithdrawableAccounts){
        this->withdrawableAccounts = withdrawableAccounts;
        this->nonWithdrawableAccounts = nonWithdrawableAccounts;
    }
    
    void processTransaction(){
        for(auto acc: withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(auto acc: nonWithdrawableAccounts){
            acc->deposit(2000);
        }
    }
}; 

int main(){
    vector<NonWithdrawableAccount*> nonWithdrawableAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;
    SavingsAccount* savings = new SavingsAccount();
    CurrentAccount* current = new CurrentAccount();
    FixedTermAccount* fixed = new FixedTermAccount();

    withdrawableAccounts.push_back(savings);
    withdrawableAccounts.push_back(current);
    nonWithdrawableAccounts.push_back(fixed);

    BankClient client(withdrawableAccounts, nonWithdrawableAccounts);
    client.processTransaction();

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