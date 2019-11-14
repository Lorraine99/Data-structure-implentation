#include <iostream>
#include <stdlib.h>
#include "unordered.h"

using namespace std;

//linked list
linkedList::linkedList(){
    front = NULL;
    back = NULL;
}

linkedList::~linkedList(){
    node *pre = front;
    node *curr = front;
    while(pre != NULL){
        curr = pre->next;
        delete pre;
        pre = curr;
    }
}

void linkedList::insert(int key){

    node *temp = new node;
    temp -> v = key;
    temp -> next = NULL;

    if(front == NULL){
        front = temp;
        back = temp;
    }

    else{
        back -> next = temp;
        back = temp;
    }
}

bool linkedList::search(int key){

    if(front == NULL){
        return false;
    }

    node *curr = front;
    
    while(curr != NULL){
        if(curr->v == key){
            return true;
        }
        curr = curr->next;
    }

    return false;
}

bool linkedList::remove(int key){

    if(front == NULL){
        return false;
    }

    node *curr = front;

    while(curr != NULL){
        if(curr->v == key){
            curr->v = -1;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

//chaining
chaining::chaining(){
    vector<linkedList*> table;
}

chaining::~chaining(){
    table.clear();
}

//set the size of the hash table
void chaining::setSize(const int size){

    table.resize(size);
    linkedList *temp = new linkedList;
    for(int i = 0; i < size; i++){
        table[i] = temp;
    }

}

//hash table
int chaining::hf(const int key){
    return key % (table.size());
}

//insert a key
bool chaining::insert(const int key){

    //check if the key already exist
    int check = search(key);
    if(check >= 0){
        return false;
    }
    
    //find slot
    int p = hf(key);

    //insert into linked list
    table[p]->insert(key);
    return true;

}

//search a key
int chaining::search(const int key){

    int p = hf(key);

    bool check = table[p]->search(key);
    
    if(check){
        return p;
    }

    return -1;
}

//delete a key
bool chaining::remove(const int key){

    int p = hf(key);

    bool check = table[p]->remove(key);
    if(check){
        return true;
    }
    return false;
}