#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string name;
    int age, roll_number;
    string grade;

    public:

    Student(string name, int age, int roll_number, string grade){
        this->name = name;
        this->age = age;
        this->roll_number = roll_number;
        this->grade = grade;
    }

    void get_details(){
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
        cout<<"roll_number: "<<roll_number<<endl;
        cout<<"grade: "<<grade<<endl;
    }
};

int main(){
    Student s1("Saitejja", 22, 85, "8.1GPA");
    s1.get_details();
    return 0;
}