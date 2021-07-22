#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main(){

    unordered_map<string, vector<string>> phonebook;

    phonebook["Rahul"].push_back("9474"); // adding the key with various values which is definitely going to get collided
    phonebook["Rahul"].push_back("9748");
    phonebook["Rahul"].push_back("9236");
    phonebook["Rahul"].push_back("9224");
    phonebook["Kajal"].push_back("7003");
    phonebook["Kajal"].push_back("7238");
    phonebook["Kajal"].push_back("7889");
    phonebook["Kajal"].push_back("7567");
    phonebook["Kajal"].push_back("7000");

    for(auto s : phonebook){ // looping through all the names
        cout<<s.first<<" -> ";
        for(auto n : s.second){ // looping thorugh alll the phone numbers of that partiular name
            cout<<n<<", ";
        }
        cout<<endl;
    }

    // search operation

    string name;
    cout<<"ENTER THE NAME TO SEARCH:";
    cin>>name;

    if(phonebook.count(name) == 0){ 
        cout<<"ABSENT";
    }
    else{
        for(string s : phonebook[name]){ // phonebook[name] gives you the values
            cout<<s<<" ";
        }
    }

    return 0;
}