#include<bits/stdc++.h>
using namespace std;

class Database {
    virtual void save(string data) = 0;
};

class MongoDBDatabase : public Database {
public:
    void save(string data){
        cout<<"Executing MongoDB Function : db.user.insert({name: '" << data <<"'})"<<endl;
    }
};

class MySQLDatabase : public Database {
public:
    void save(string data){
        cout<<"Executing MySQL Function : INSERT INTO user (name) VALUES ('" << data <<"')"<<endl;
    }
};

class UserService  { // High-level module (Loosely coupled)
private:
    Database* db; // Dependency Injection ;
public:
    UserService(Database* db){
        this->db = db;
    }
    void storeUser(string user){
        db->save(user);
    }
};

int main(){
    MySQLDatabase mysql;
    MongoDBDatabase mongo;

    UserService service1(&mysql); // Injecting MySQL dependency
    service1.storeUser("Saitejja");
    UserService service2(&mongo); // Injecting MongoDB dependency
    service2.storeUser("Revanth");
    return 0;
}