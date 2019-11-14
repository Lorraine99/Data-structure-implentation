#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "quadtree.h"

using namespace std;

//constructor
quadtree::quadtree(){
    root = NULL;
}

//destructor
quadtree::~quadtree(){
    clear(root);
}

node::~node(){
    coord.x = 0.0;
    coord.y = 0.0;
    name = "";
    population = 0;
    cost = 0;
    salary = 0;
    NE = NULL;
    NW = NULL;
    SW = NULL;
    SE = NULL;
}

//public
string quadtree::search(key value){
    return search(value, root);
}

bool quadtree::insert(node *k){
    if(root == NULL){
        root = new node;
        root->coord.x = k->coord.x;
        root->coord.y = k->coord.y;
        root->cost = k->cost;
        root->name = k->name;
        root->population = k->population;
        root->salary = k->salary;
        root->NE = NULL;
        root->NW = NULL;
        root->SE = NULL;
        root->SW = NULL;
        return true;
    }
    else{
        return insert(k, root);
    }
    
}

void quadtree::print(){
    // cout << "p" << endl;
    print(root);
    cout << endl;
}

void quadtree::clear(){
    if(root == NULL){
        return;
    }
    clear(root);
    root = NULL;
}

int quadtree::size(){
    int count = 0;
    
    if(root != NULL){
        count = size(root);
    }

    return count;
}

int quadtree::totalValue(key v, string dir, string attr){
    int result = 0;
    if(root != NULL){
        result = totalValue(v,dir,attr,root);
    }
    return result;
}

int quadtree::minValue(key v, string dir, string attr){
    int result = 0;
    if(root != NULL){
        result = minValue(v,dir,attr,root);
    }
    return result;
}

int quadtree::maxValue(key v, string dir, string attr){
    int result = 0;
    if(root != NULL){
        result = maxValue(v,dir,attr,root);
    }
    return result;
}

//private

//insert a city at a leaf
bool quadtree::insert(node *k, node *r){

    //check if k is already in the tree
    key temp;
    temp.x = k->coord.x;
    temp.y = k->coord.y;
    string check = search(temp, root);
    if(check != "not found"){
        return false;
    }

    if(temp.x >= r->coord.x && temp.y > r->coord.y){
        if(r->NE != NULL){
            return insert(k, r->NE);
        }
        else{
            r->NE = new node;
            r->NE->coord.x = k->coord.x;
            r->NE->coord.y = k->coord.y;
            r->NE->cost = k->cost;
            r->NE->name = k->name;
            r->NE->population = k->population;
            r->NE->salary = k->salary;
            r->NE->NE = NULL;
            r->NE->NW = NULL;
            r->NE->SE = NULL;
            r->NE->SW = NULL;
            return true;
        }
    }
    else if(temp.x < r->coord.x && temp.y >= r->coord.y){
        if(r->NW != NULL){
            return insert(k, r->NW);
        }
        else{
            r->NW = new node;
            r->NW->coord.x = k->coord.x;
            r->NW->coord.y = k->coord.y;
            r->NW->cost = k->cost;
            r->NW->name = k->name;
            r->NW->population = k->population;
            r->NW->salary = k->salary;
            r->NW->NE = NULL;
            r->NW->NW = NULL;
            r->NW->SE = NULL;
            r->NW->SW = NULL;
            return true;
        }
    }
    else if(temp.x <= r->coord.x && temp.y < r->coord.y){
        if(r->SW != NULL){
            return insert(k, r->SW);
        }
        else{
            r->SW = new node;
            r->SW->coord.x = k->coord.x;
            r->SW->coord.y = k->coord.y;
            r->SW->cost = k->cost;
            r->SW->name = k->name;
            r->SW->population = k->population;
            r->SW->salary = k->salary;
            r->SW->NE = NULL;
            r->SW->NW = NULL;
            r->SW->SE = NULL;
            r->SW->SW = NULL;
            return true;
        }
    }
    else if(temp.x > r->coord.x && temp.y <= r->coord.y){
        if(r->SE != NULL){
            return insert(k, r->SE);
        }
        else{
            r->SE = new node;
            r->SE->coord.x = k->coord.x;
            r->SE->coord.y = k->coord.y;
            r->SE->cost = k->cost;
            r->SE->name = k->name;
            r->SE->population = k->population;
            r->SE->salary = k->salary;
            r->SE->NE = NULL;
            r->SE->NW = NULL;
            r->SE->SE = NULL;
            r->SE->SW = NULL;
            return true;
        }
    }
    return false;
}

//search a city according to coordinate
string quadtree::search(key value, node *leaf){

    string result = "not found";

    //not found
    if(leaf == NULL){
        return result;
    }
    
    if(value.x == leaf->coord.x && value.y == leaf->coord.y){
        result = leaf->name;
        return result;
    }
    else if(value.x >= leaf->coord.x && value.y >= leaf->coord.y){
        return search(value, leaf->NE);
    }
    else if(value.x < leaf->coord.x && value.y >= leaf->coord.y){
        return search(value, leaf->NW);
    }
    else if(value.x <= leaf->coord.x && value.y < leaf->coord.y){
        return search(value, leaf->SW);
    }
    else if(value.x > leaf->coord.x && value.y <= leaf->coord.y){
        return search(value, leaf->SE);
    }

}

//inorder traversal
void quadtree::print(node *r){
    if(r != NULL){
        print(r->NE);
        print(r->NW);
        cout << r->name << " ";
        print(r->SW);
        print(r->SE);
    }
}

//delete all the node
void quadtree::clear(node *r){
    if(r != NULL){
        clear(r->NE);
        clear(r->NW);
        clear(r->SE);
        clear(r->SW);
        delete r;
    }

}

//return the number of node in current tree
int quadtree::size(node *r){

    int count = 1;
    if(r->NE != NULL){
        count += size(r->NE);
    }
    if(r->NW != NULL){
        count += size(r->NW);
    }
    if(r->SW != NULL){
        count += size(r->SW);
    }
    if(r->SE != NULL){
        count += size(r->SE);
    }

    return count;
}


int quadtree::totalValue(key v, string dir, string attr, node *r){
    if(r == NULL){
        return 0;
    }

    if(v.x == r->coord.x && v.y == r->coord.y){
        if(dir == "NE"){
            if(r->NE != NULL){
                r = r->NE;
                int result = totalValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
              
        }
        else if(dir == "NW"){

            if(r->NW != NULL){
                r = r->NW;
                int result = totalValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SW"){

            if(r->SW != NULL){
                r = r->SW;
                int result = totalValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SE"){

            if(r->SE != NULL){
                r = r->SE;
                int result = totalValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
    }

    else if(v.x >= r->coord.x && v.y > r->coord.y){
        return totalValue(v,dir,attr,r->NE);
    }

    else if(v.x < r->coord.x && v.y >= r->coord.y){
        return totalValue(v,dir,attr,r->NW);
    }

    else if(v.x <= r->coord.x && v.y < r->coord.y){
        return totalValue(v,dir,attr,r->SW);
    }

    else if(v.x > r->coord.x && v.y <= r->coord.y){
        return totalValue(v,dir,attr,r->SE);
    }
}

int quadtree::totalValueHelper(string attr, node *r){

    if(r == NULL){
        return 0;
    }
    
    if(attr == "p"){
        int result = r->population;
        result += totalValueHelper(attr,r->NE);
        result += totalValueHelper(attr,r->NW);
        result += totalValueHelper(attr,r->SE);
        result += totalValueHelper(attr,r->SW);
        return result;
    }
    else if(attr == "r"){
        int result = r->cost;
        result += totalValueHelper(attr,r->NE);
        result += totalValueHelper(attr,r->NW);
        result += totalValueHelper(attr,r->SE);
        result += totalValueHelper(attr,r->SW);
        return result;
    }
    else if(attr == "s"){
        int result = r->salary;
        result += totalValueHelper(attr,r->NE);
        result += totalValueHelper(attr,r->NW);
        result += totalValueHelper(attr,r->SE);
        result += totalValueHelper(attr,r->SW);
        return result;
    }
}

int quadtree::minValue(key v, string dir, string attr, node *r){

    if(r == NULL){
        return 0;
    }

    if(v.x == r->coord.x && v.y == r->coord.y){
        if(dir == "NE"){
            if(r->NE != NULL){
                r = r->NE;
                int result = minValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
              
        }
        else if(dir == "NW"){

            if(r->NW != NULL){
                r = r->NW;
                int result = minValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SW"){

            if(r->SW != NULL){
                r = r->SW;
                int result = minValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SE"){

            if(r->SE != NULL){
                r = r->SE;
                int result = minValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
    }

    else if(v.x >= r->coord.x && v.y > r->coord.y){
        return minValue(v,dir,attr,r->NE);
    }

    else if(v.x < r->coord.x && v.y >= r->coord.y){
        return minValue(v,dir,attr,r->NW);
    }

    else if(v.x <= r->coord.x && v.y < r->coord.y){
        return minValue(v,dir,attr,r->SW);
    }

    else if(v.x > r->coord.x && v.y <= r->coord.y){
        return minValue(v,dir,attr,r->SE);
    }
}

int quadtree::minValueHelper(string attr, node *r){
    
    if(r == NULL){
        // cout << "oops" << endl;
        return INT32_MAX;
    }
    
    if(attr == "p"){
        int result = r->population;
        // cout << result << endl;
        int ne = minValueHelper(attr,r->NE);
        // cout << ne << endl;
        int nw = minValueHelper(attr,r->NW);
        // cout << nw << endl;
        int se = minValueHelper(attr,r->SE);
        // cout << se << endl;
        int sw = minValueHelper(attr,r->SW);
        // cout << sw << endl;
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result > arr[i]){
                result = arr[i];
            }
        }
        // cout << "min is " << result << endl;
        return result;
    }
    else if(attr == "r"){
        int result = r->cost;
        int ne = minValueHelper(attr,r->NE);
        int nw = minValueHelper(attr,r->NW);
        int se = minValueHelper(attr,r->SE);
        int sw = minValueHelper(attr,r->SW);
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result > arr[i]){
                result = arr[i];
            }
        }
        return result;
    }
    else if(attr == "s"){
        int result = r->salary;
        int ne = minValueHelper(attr,r->NE);
        int nw = minValueHelper(attr,r->NW);
        int se = minValueHelper(attr,r->SE);
        int sw = minValueHelper(attr,r->SW);
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result > arr[i]){
                result = arr[i];
            }
        }
        return result;
    }

}

//find the max value for attr under v in dir
int quadtree::maxValue(key v, string dir, string attr, node *r){

    if(r == NULL){
        return 0;
    }

    if(v.x == r->coord.x && v.y == r->coord.y){
        if(dir == "NE"){
            if(r->NE != NULL){
                r = r->NE;
                int result = maxValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
              
        }
        else if(dir == "NW"){

            if(r->NW != NULL){
                r = r->NW;
                int result = maxValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SW"){

            if(r->SW != NULL){
                r = r->SW;
                int result = maxValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
        else if(dir == "SE"){

            if(r->SE != NULL){
                r = r->SE;
                int result = maxValueHelper(attr,r);
                return result;
            }
            else{
                return 0;
            }
            
        }
    }

    else if(v.x >= r->coord.x && v.y > r->coord.y){
        return maxValue(v,dir,attr,r->NE);
    }

    else if(v.x < r->coord.x && v.y >= r->coord.y){
        return maxValue(v,dir,attr,r->NW);
    }

    else if(v.x <= r->coord.x && v.y < r->coord.y){
        return maxValue(v,dir,attr,r->SW);
    }

    else if(v.x > r->coord.x && v.y <= r->coord.y){
        return maxValue(v,dir,attr,r->SE);
    }

}

int quadtree::maxValueHelper(string attr, node *r){
    
    if(r == NULL){
        return 0;
    }
    
    if(attr == "p"){
        int result = r->population;
        int ne = maxValueHelper(attr,r->NE);
        int nw = maxValueHelper(attr,r->NW);
        int se = maxValueHelper(attr,r->SE);
        int sw = maxValueHelper(attr,r->SW);
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result < arr[i]){
                result = arr[i];
            }
        }
        return result;
    }
    else if(attr == "r"){
        int result = r->cost;
        int ne = maxValueHelper(attr,r->NE);
        int nw = maxValueHelper(attr,r->NW);
        int se = maxValueHelper(attr,r->SE);
        int sw = maxValueHelper(attr,r->SW);
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result < arr[i]){
                result = arr[i];
            }
        }
        return result;
    }
    else if(attr == "s"){
        int result = r->salary;
        int ne = maxValueHelper(attr,r->NE);
        int nw = maxValueHelper(attr,r->NW);
        int se = maxValueHelper(attr,r->SE);
        int sw = maxValueHelper(attr,r->SW);
        int arr[4] = {ne,nw,se,sw};
        for(int i = 0; i < 4; i++){
            if(result < arr[i]){
                result = arr[i];
            }
        }
        return result;
    }

}