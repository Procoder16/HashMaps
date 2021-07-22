#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

/*  
    Unordered Map is basically the STL implementation of Hashtable where the underlying mechanism follows all the concepts of Hashtable like
    hash function, rehashing, collision handling, etc.
    But the implementation is almost similar to the map implementation.
    The best part of unordered_map is that all the predefined functions take O(1) in average case.
    One thing we should keep in mind that a unordered_map stores only unique values. So suppose from the below example, if you update
    m["Banana"] = 40 and then search it, the value would be updated and hence 40 would be printed. 
    The order of the elements isn't lexicographical unlike map as the positioning is determined by the hash index and the hasg function
*/

int main(){

    unordered_map<string, int> m;

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

    // updating the price of the input fruit
    m[fruit] += 25;

    auto it = m.find(fruit);
    // If you don't want to use auto, then the data type of the iterator would be map<string, int> :: iterator it
    // the find function returns an iterator and goes upto the end of the map which is basically NULL.
    // So, if the iterator returns NULL, that means the find function has reached the end and and was not able to find the element 
    if(it != m.end()){
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl; //m[fruit] will directly give you the value associated with it
    }
    else{
        cout<<"FRUIT NOT PRESENT!!!"<<endl;
    }

    m.erase(fruit);

    // Another way of searching for an element is using the count function
    // The count function returns 1 if the key is present, else returns 0

    if(m.count(fruit)){
        cout<<fruit<<" is present in the map.";
    }
    else{
        cout<<fruit<<" not present."<<endl;
    }

    m["Litchi"] = 65;  // adding some more values to the map
    m["Pineapple"] = 40;
    m["Grapes"] = 38;

    //iterating over all the mapped values

    for(auto it = m.begin(); it != m.end(); it++){
        // there are two ways in which we can access the values of the map
        // 1. (*it).first and (*it).second... we are using a * because it is an iterator
        // 2. second way is that we can use it -> first and it -> second
        cout<<it->first<<" -> "<<it -> second<<endl;
    }
    
    return 0;
}