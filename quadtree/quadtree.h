#include <string>
using namespace std;

class key{
    public:
    double x;
    double y;
};

class node{
    public:
    ~node();
    key coord;
    string name;
    int population;
    int cost;
    int salary;
    node *NE;
    node *NW;
    node *SW;
    node *SE;
};

class quadtree{

    private:
    node *root;
    bool insert(node *k, node *r);
    string search(key value, node *leaf);
    void print(node *r);
    void clear(node *r);
    int size(node *r);
    int totalValue(key v, string dir, string attr, node *r);
    int totalValueHelper(string attr, node *r);
    int minValue(key v, string dir, string attr, node *r);
    int minValueHelper(string attr, node *r);
    int maxValue(key v, string dir, string attr,node *r);
    int maxValueHelper(string attr, node *r);

    public:
    quadtree();
    ~quadtree();
    string search(key value);
    bool insert(node *k);
    void print();
    void clear();
    int size();
    int totalValue(key v, string dir, string attr);
    int minValue(key v, string dir, string attr);
    int maxValue(key v, string dir, string attr);

};