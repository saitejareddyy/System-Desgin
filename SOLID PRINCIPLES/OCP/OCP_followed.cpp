#include<bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

//1.ShoppingCart: Only responsible for cart related business logic.
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

//Abstract class for storage
class Persistence {
private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart) = 0;
};
class  SQLPersistance: public Persistence {
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to SQL DB..."<<endl;
    }
};
class MOngoPersistance: public Persistence {
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to Mongo DB..."<<endl;
    }
};
class FilePersistance: public Persistence {
public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving shopping cart to File..."<<endl;
    }
};
int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Keyboard", 500));
    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();
    Persistence* db = new SQLPersistance();
    Persistence* mongo = new MOngoPersistance();
    Persistence* file = new FilePersistance();
    db->save(cart);
    mongo->save(cart);
    file->save(cart);

    return 0;
}