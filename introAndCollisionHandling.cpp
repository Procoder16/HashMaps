#include<bits/stdc++.h> // standard header files are declared using <> 
#include "hashtable.h" // user-defined header files are declared using "" 

// here we are importing are self made header file class called hashtable.h

using namespace std;

int main(){

    HashTable<int> price_menu;
    // here we are making an instance of the self defined data structure

    price_menu.insert("Burger", 120); // inserting nodes in the hash table using the user defined function
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print(); // calling the print function to print the hashtable

    int *price = price_menu.search("Noodles");

    if(price == NULL){
        cout<<"NOT FOUND";
    }
    else{
        cout<<"THE PRICE IS "<<*price<<endl; // using *price because the function returns a pointer to the function, so * would give its value 
    }

    price_menu.erase("Noodles");  // removing the key noodles
    cout<<"NEW HASHTABLE AFTER REMOVAL:"<<endl;
    price_menu.print();
    cout<<endl;

    //Map

    //Insert
    price_menu["Dosa"] = 60;
    //Update
    price_menu["Dosa"] += 10;
    //search
    cout<<"Price of Dosa ";
    cout<<price_menu["Dosa"] << endl;

    return 0;
}