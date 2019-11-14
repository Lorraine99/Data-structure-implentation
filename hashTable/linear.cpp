#include <iostream>
#include <stdlib.h>
#include "linear.h"

using namespace std;

//constructors
linearProbing::linearProbing(){
    size = 0;
    table.push_back(0);
}

//deconstructors
linearProbing::~linearProbing(){
    size = 0;
    table.clear();
}

//initialize hash table with a capacity
void linearProbing::setSize(const int s){
    table.resize(s);
    for(int i = 0; i < s; i++){
        table[i] = -1;
    }
    size = s;
}

//hash table
int linearProbing::hf(const int key){
    return key % (table.size());
}

//insert a key
bool linearProbing::insert(const int key){

    //check if the table is full
    if(size == 0){
        return false;
    }

    //check if the key is in the hash table
    int check = search(key);
    if(check >= 0){
        return false;
    }

    int p = hf(key);
    
    //find slot
    int i = 0;
    while(table[p] != -1){
        p++;
        p = hf(p);
    }
    
    table[p] = key;
    size = size - 1;
    return true;
}

//search a key
int linearProbing::search(const int key){

    int p = hf(key);
    int copy = p;
    int i = 0;

    while(i < table.size()){
        if(table[p] == key){
            return p;
        }
        p++;
        i++;
        p = hf(p);
    }
    return -1;
}

//delete a key
bool linearProbing::remove(const int key){

    int p = hf(key);
    int i = 0;
    while(i < table.size()){
        if(table[p] == key){
            table[p] = -1;
            size = size + 1;
            return true;
        }
        i++;
        p++;
        p = hf(p);
    }

    return false;
}