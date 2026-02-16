#include<bits/stdc++.h>
using namespace std;

// Product class Representing any items of any Ecommerce
class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProducts(Product* p){
        products.push_back(p);
    }

    const vector<Product* >& getProducts(){
        return products;
    }

    //1. Calculate total price in cart
    double calculateTotal(){
        double total = 0;
        for(auto p: products){
            total += p->price;
        }
        return total;
    }

    //2. Violating SRP:- prints invoics (should be in separate class)
    void printInvoice(){
        cout << "Shopping Cart Invoices:\n";
        for(auto p: products){
            cout<<p->name<<" -$" << p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }

    //3. Violating SRP - Save to DB (Should be a separate class)
    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 1500));
    cart->addProducts(new Product("Keyboard", 500));

    cart->printInvoice();
    cart->saveToDatabase();
    return 0;
}