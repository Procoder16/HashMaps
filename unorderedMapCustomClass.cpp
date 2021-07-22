#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Student{ // defining the class student as a used defined data type 
    public:
    string firstName;
    string lastName;
    string rollNo;
    
    Student(string fn, string ln, string rn){
        firstName = fn;
        lastName = ln;
        rollNo = rn;
    }

    bool operator == (const Student &s) const{ // operator overloading
                                       // ???                    
        return rollNo == s.rollNo;
    }
};

class hashFn{
    public: 
    size_t operator()(const Student &s) const{  // self defined hash function
                                       // ???
        return s.firstName.length() + s.lastName.length();
    }
};

int main(){

    unordered_map<Student, int, hashFn> student_map;
                                //this is where you give the input of your custom hash function
    Student s1("Soumik", "Mukherjee", "547"); // creating objects of the student class
    Student s2("Rohit", "Sharma", "045");
    Student s3("Soumik", "Ghosh", "078");
    Student s4("Rohit", "Sharma", "329");

    student_map[s1] = 100; //mapping the keys to the values
    student_map[s2] = 97;
    student_map[s3] = 45;
    student_map[s4] = 88;

    //iterate over all students

    for(auto s : student_map){
        cout<<s.first.firstName<<" "<<s.first.lastName<<" and Marks:"<<s.second<<endl;
        // make sure that they are a pair... so first and then firstName
    }   

    return 0;
}