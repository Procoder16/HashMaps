#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main(){

    unordered_map<string, vector<string>> phonebook;

    phonebook["Rahul"].push_back("9474");
    phonebook["Rahul"].push_back("9748");
    phonebook["Rahul"].push_back("9236");
    phonebook["Rahul"].push_back("9224");
    phonebook["Kajal"].push_back("7003");
    phonebook["Kajal"].push_back("7238");
    phonebook["Kajal"].push_back("7889");
    phonebook["Kajal"].push_back("7567");
    phonebook["Kajal"].push_back("7000");

    for(auto s : phonebook){
        cout<<s.first<<" -> ";
        for(auto n : s.second){
            cout<<n<<", ";
        }
        cout<<endl;
    }

    return 0;
}