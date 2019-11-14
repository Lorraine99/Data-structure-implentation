#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include "quadtree.cpp"

using namespace std;

int main(){
    string input;
    quadtree *tree = new quadtree;

    while(getline(cin,input)){

        string command;
        string restInput;
        int space = input.find(" ");
        if(space != -1){
            command = input.substr(0,space);
            restInput = input.substr(space+1);
        }
        else if(space == -1){
            command = input.substr(0);
        }

        vector<string> data;

        if(command == "i"){
            stringstream s(restInput);

            while(s.good()){
                string temp;
                getline(s,temp,';');
                data.push_back(temp);
            }

            double item = 0.0;
            //node to be inserted
            node *t = new node;
            t->name = data[0];

            item = stod(data[1]);
            t->coord.x = item;

            item = stod(data[2]);
            t->coord.y = item;

            item = stoi(data[3]);
            t->population = item;

            item = stoi(data[4]);
            t->cost = item;

            item = stoi(data[5]);
            t->salary = item;
            
            t->NE = NULL;
            t->SE = NULL;
            t->NW = NULL;
            t->SW = NULL;

            bool check = tree->insert(t);
            // tree->print();
            if(check){
                cout << "success" << endl;
            }
            else{
                cout << "failure" << endl;
            }

        }

        else if(command == "s"){
            int position = restInput.find(";");
            string t1 = restInput.substr(0,position);
            string t2 = restInput.substr(position+1);
            data.push_back(t1);
            data.push_back(t2);
            key k;
            k.x = stod(t1);
            k.y = stod(t2);

            string output = tree->search(k);
            if(output == "not found"){
                cout << output << endl;
            }
            else{
                cout << "found " << output << endl;
            }

        }

        else if(command == "print"){
            tree->print();
        }
        
        else if(command == "q_max"){
            stringstream s(restInput);

            while(s.good()){
                string temp;
                getline(s,temp,';');
                data.push_back(temp);
            }

            key v;
            double item = stod(data[0]);
            v.x = item;
            item = stod(data[1]);
            v.y = item;
            int result = tree->maxValue(v,data[2],data[3]);
            if(result == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "max " << result << endl; 
            }
        }

        else if(command == "q_min"){
            stringstream s(restInput);

            while(s.good()){
                string temp;
                getline(s,temp,';');
                data.push_back(temp);
            }

            key v;
            double item = stod(data[0]);
            v.x = item;
            item = stod(data[1]);
            v.y = item;
            int result = tree->minValue(v,data[2],data[3]);
            if(result == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "min " << result << endl; 
            }
        }

        else if(command == "q_total"){
            stringstream s(restInput);

            while(s.good()){
                string temp;
                getline(s,temp,';');
                data.push_back(temp);
            }

            key v;
            double item = stod(data[0]);
            v.x = item;
            item = stod(data[1]);
            v.y = item;
            int result = tree->totalValue(v,data[2],data[3]);
            if(result == 0){
                cout << "failure" << endl;
            }
            else{
                cout << "total " << result << endl; 
            }
        }

        else if(command == "clear"){
            tree->clear();
            cout << "success" << endl;
        }

        else if(command == "size"){
            int num = tree->size();
            cout << "tree size " << num << endl;
        }
    }
    return 0;
}