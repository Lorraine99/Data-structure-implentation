#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class linearProbing{
    private:
    vector<int> table;
    
    public:
    linearProbing();
    ~linearProbing();
    int size;
    int hf(const int key);
    void setSize(const int s);
    bool insert(const int key);
    int search(const int key);
    bool remove(const int key);

};