#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

#include "polynomial.h"

//constructors
Polynomial::Polynomial(){
    front = NULL;
    back = NULL;
}

void Polynomial::init(const int size){
    front = NULL;
    back = NULL;
    for(int i = 0; i < size; i++){
        insert(0.0);
    }
}

//destructor
Polynomial::~Polynomial(){
    //delete linked list
    node *curr = new node;
    node *temp = new node;
    curr = front;
    temp = front -> next;

    while(temp != NULL){
        delete curr;
        curr = temp;
        temp = curr -> next;
    }
    
    delete curr, temp, front, back;
}

void Polynomial::insert(double x){
    node *temp = new node;
    temp -> coeff = x;
    temp -> next = NULL;

    if(front == NULL){
        front = temp;
        back = temp;
        return;
    }
    else{
        back -> next = temp;
        back = back -> next;
    }
}

Polynomial& Polynomial::coeff(const double currPoly[]){
    node *curr = new node;
    curr = front;
    int i = 0;
    int size = 0;

    size = *(&currPoly + 1) - currPoly;

    while(curr != NULL){
        curr -> coeff = currPoly[i];
        curr = curr -> next;
        i++;
    }

    //delete curr;
    return *this;
}

bool Polynomial::compare(Polynomial& expPoly){
    int s1 = this->getSize();
    int s2 = expPoly.getSize();

    if(s1 != s2){
        return false;
    }

    node *c1 = new node;
    node *c2 = new node;
    c1 = front;
    c2 = expPoly.front;

    int check = 1;
    while(c1 != NULL && c2 != NULL){
        if(c1->coeff != c2->coeff){
            check = 0;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    //delete c1, c2;

    if(check == 1){
        return true;
    }
    else{
        return false;
    }
}

bool Polynomial::eval(const double x, const double expValue){
    node *curr = new node;
    curr = front;

    //polynomial -> array
    int s = getSize();
    double coeff[s];
    for(int i = 0; i < s; i++){
        coeff[i] = 0.0;
    }
    int c = s-1;
    while(curr != NULL && c >= 0){
        coeff[c] = curr->coeff;
        curr = curr->next;
        c--;
    }

    double sum = coeff[0];
    for(int i = 1; i < s; i++){
        sum = sum * x + coeff[i];
    }

    delete curr;

    //compare result with expValue
    if(sum == expValue){
        return true;
    }
    else{
        return false;
    }
}

Polynomial Polynomial::add(Polynomial& secPoly){
    int currSize = this->getSize();
    int secSize = secPoly.getSize();
    double s = 0.0;
    Polynomial sum;
    node *curr = new node;
    node *sec = new node;
    curr = front;
    sec = secPoly.front;

    if(currSize > secSize){
        while(sec != NULL){
            s = curr->coeff + sec->coeff;
            sum.insert(s);
            curr = curr->next;
            sec = sec->next;
        }
        while(curr != NULL){
            s = curr->coeff;
            sum.insert(s);
            curr = curr->next;
        }
    }
    else if(secSize > currSize){
        while(curr != NULL){
            s = curr->coeff + sec->coeff;
            sum.insert(s);
            curr = curr->next;
            sec = sec->next;
        }
        while(sec != NULL){
            s = sec->coeff;
            sum.insert(s);
            sec = sec->next;
        }
    }
    delete curr, sec;
    return sum;
}

Polynomial Polynomial::mult(Polynomial& secPoly){
    int currSize = this->getSize();
    int secSize = secPoly.getSize();
    node *curr = new node;
    node *sec = new node;
    curr = front;
    sec = secPoly.front;

    //put currpoly and secpoly into arrays
    double* currArray = new double[currSize];
    double* secArray = new double[secSize];
    int i = 0;
    while(curr != NULL && i < currSize){
        currArray[i] = curr->coeff;
        i++;
        curr = curr->next;
    }
    int j = 0;
    while(sec != NULL && i < secSize){
        secArray[j] = sec->coeff;
        j++;
        sec = sec->next;
    }

    //multiply two polynomials
    double product [currSize + secSize];
    i = 0;
    j = 0;
    while(i < currSize){
        while(j < secSize){
            product[i + j] += currArray[i] * secArray[j];
        }
        j = 0;
        i++;
    }

    //put product into a linked list
    Polynomial p;
    for(int i = 0; i < currSize + secSize; i++){
        p.insert(product[i]);
    }

    delete [] currArray, secArray;
    delete curr, sec;
    return p;
}

int Polynomial::getSize(){
    node *curr = new node;
    curr = front;
    int size = 0;

    while(curr != NULL){
        size++;
        curr = curr -> next;
    }

    delete curr;
    return size;
}