#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class node{
    public:
    int v;
    node* next;
};

class linkedList{
    private:
    node *front;
    node *back;

    public:
    linkedList();
    ~linkedList();

    void insert(int key);
    bool search(int key);
    bool remove(int key);
};

class chaining{
    private:
    vector<linkedList*> table;

    public:
    chaining();
    ~chaining();

    int hf(const int key);
    void setSize(const int size);
    bool insert(const int key);
    int search(const int key);
    bool remove(const int key);

};
