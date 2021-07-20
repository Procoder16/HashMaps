#include<bits/stdc++.h> // standard header files are declared using <> 
#include "hashtable.h" // user-defined header files are declared using "" 

// here we are importing are self made header file class called hashtable.h

using namespace std;

int main(){

    HashTable<int> price_menu;
    // here we are making an instance of the self defined data structure

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("BurgerPizza", 150);
    price_menu.insert("Noodles", 25);
    price_menu.insert("Coke", 40);

    price_menu.print();

    return 0;
}