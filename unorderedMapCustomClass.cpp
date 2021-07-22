#include<iostream>
using namespace std;

class Student{
    string firstName;
    string lastName;
    int rollNo;

    public:
    Student(string fn, string ln, int rn){
        firstName = fn;
        lastName = ln;
        rollNo = rn;
    }
};

int main(){

    Student s1("Soumik", "Mukherjee", 547);
    Student s2("Rohit", "Sharma", 45);
    Student s3("Soumik", "Ghosh", 78);
    Student s4("Rohit", "Sharma", 29);

    return 0;
}