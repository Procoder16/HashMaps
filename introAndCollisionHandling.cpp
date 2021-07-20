#include<iostream>
using namespace std;

template<typename T>  //using a template class
class Node{ // this is a class to define the structure of the Node 

    public:
    string key;
    T value;
    Node<T>* next;

    Node(string key, T val){
        this-> key = key;
        value = val;
        next = NULL;
    }
    ~Node(){  // destructor so that when the node is deleted, it is called(would be a recursive approach)
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{  // class to define the hash table 
    Node<T>** table;
    int current_size;
    int table_size;

    public:
    HashTable(int ts = 7){
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, T value){

    }

    T search(string key){

    }

    void erase(string key){
        
    }

};

int main(){

}