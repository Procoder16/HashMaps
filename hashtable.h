#include<bits/stdc++.h>
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

    int hashFn(string key){
        int idx = 0;
        int p = 1;
        for(int j = 0; j < key.length(); j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx % table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    void rehash(){
        Node<T>** oldTable = table;  // making a pointer that points to the old table
        int oldTableSize = table_size;
        table_size = 2*table_size; // approximation find the next prime no
        table = new Node<T>*[table_size];

        //initialising the new table with NULL

        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }

        current_size = 0;

        //shift the elemenst from table to the new table

        for(int i = 0; i < oldTableSize; i++){
            Node<T>*temp = oldTable[i];
            while(temp!=NULL){
                insert(temp -> key, temp -> value);
                temp = temp -> next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete [] oldTable;
    }

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
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);
        // Insert at the head of the linked list with id = idx
        n -> next = table[idx];
        table[idx] = n;
        current_size++;

        //rehash
        float load_factor = current_size/(1.0*table_size);
        if(load_factor > 0.7){ // 0.7 here is the threshold value that we can define
            rehash();
        }
    }

    void print(){
        for(int i = 0; i < table_size; i++){
            cout<<"Bucket "<<i<<"->";
            Node<T> *temp = table[i];
            while(temp != NULL){
                cout<<temp -> key<<"->";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }

    T* search(string key){  // we are using T* because if the key is not found, then we would return NULL and cannot be the return type T
        int idx = hashFn(key); // it gives the idx of the key in the table according to the definition 
        Node<T>* temp = table[idx];
        while(temp != NULL){
            if(temp -> key == key){
                return &temp -> value;  // we are returning the address as the return type is T*
            }
        }
        return NULL;
    }

    void erase(string key){
        int idx = hashFn(key);
        Node<T>* temp = table[idx];
        if(temp -> key == key){  // checking for the head node only
            Node<T>* todelete = temp;
            table[idx] = temp -> next;
            delete todelete;
        }
        while(temp -> next != NULL && temp -> next -> key != key){  //checking for the rest of the list
            if(temp -> next-> key == key){
                Node<T>* todelete = temp -> next;
                temp -> next = temp -> next -> next;
                delete todelete;
            }
            temp = temp -> next;
        }
    }

};
