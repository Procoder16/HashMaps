#include<iostream>
#include<map>
#include<string>
using namespace std;

/*
    One thing we should keep in mind that a map stores only unique values. So suppose from the below example, if you update
    m["Banana"] = 40 and then search it, the value would be updated and hence 40 would be printed. 
*/

int main(){

    map<string, int> m;

    //insert
    m.insert(make_pair("Mango", 100)); // one way of inserting

    pair<string, int>p; // second way of inserting
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["Banana"] = 20; //third way of inserting... this will basically create a key of Banana and then map with the value 20


    // Search
    cout<<"ENTER A FRUIT TO SEARCH:";
    string fruit;
    cin>>fruit;

    auto it = m.find(fruit);
    // the find function returns an iterator and goes upto the end of the map which is basically NULL.
    // So, if the iterator returns NULL, that means the find function has reached the end and and was not able to find the element 
    if(it != m.end()){
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl; //m[fruit] will directly give you the value associated with it
    }
    else{
        cout<<"FRUIT NOT PRESENT!!!";
    }
    
    return 0;
}