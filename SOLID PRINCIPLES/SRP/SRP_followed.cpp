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
};

//2. ShoppingCartPrinter: is only responsible for printing invoices

class ShoppingCartPrinter {
private:
    ShoppingCart * cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoics(){
        cout<<"Shopping Cart Invoices:\n";
        for(auto p: cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

//3. ShoppingCartStorage: Only responsible for saving cart to DB
class ShoppingCartSaving {
private:
    ShoppingCart* cart;

public:
    ShoppingCartSaving(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToDatabase(){
        cout<<"Saving shopping cart to database..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProducts(new Product("Laptop", 1500));
    cart->addProducts(new Product("Keyboard", 500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoics();
    ShoppingCartSaving* db = new ShoppingCartSaving(cart);
    db->saveToDatabase();
    return 0;
}