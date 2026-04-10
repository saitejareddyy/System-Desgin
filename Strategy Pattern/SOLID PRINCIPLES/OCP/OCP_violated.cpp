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

class ShoppingCart{
private:
    vector<Product*> products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    vector<Product*> getProducts(){
        return products;
    }

    //calculate total price in cart
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
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Shopping Cart Invoices:\n";
        for(auto p: cart->getProducts()){
            cout<<p->name<<" -$"<<p->price<<endl;
        }
        cout<<"Total: $"<<cart->calculateTotal()<<endl;
    }
};

//3. ShoppingCartStorage: Only responsible for saving cart to DB

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving shopping cart to SQL DB..."<<endl;
    }

    void saveToMongoDB(){
        cout<<"Saving shopping cart to MongoDB..."<<endl;
    }

    void saveToFile(){
        cout<<"Saving shopping cart to File..."<<endl;
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart -> addProduct(new Product("Laptop", 1500));
    cart -> addProduct(new Product("Keyboard", 500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToSQLDatabase();
    
    return 0;
}