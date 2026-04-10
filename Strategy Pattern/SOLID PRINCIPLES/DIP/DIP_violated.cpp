#include<bits/stdc++.h>
using namespace std;    

class MongoDBDatabase {
public:
    void saveToDB(string data){
        cout<<"Executing MongoDB Function : db.user.insert({name: '" << data <<"'})"<<endl;
    }
};

class MySQLDatabase {
public:
    void saveToDB(string data){
        cout<<"Executing MySQL Function : INSERT INTO user (name) VALUES ('" << data <<"')"<<endl;
    }
};

class UserService { // High-level module (Tightly coupled)
private:
    MongoDBDatabase* mongoDb;
    MySQLDatabase* SqlDb;
public:
    void storeUserToSql(string user){
        // MySQL - specific code
        SqlDb->saveToDB(user);
    }
    void storeUserToMongo(string user){
        // MongoDB - specific code
        mongoDb->saveToDB(user);
    }
};

int main(){
    UserService service;
    service.storeUserToSql("Saitejja");
    service.storeUserToMongo("Revanth");
    return 0;
}