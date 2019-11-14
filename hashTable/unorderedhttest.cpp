#include <iostream>
#include <stdlib.h>
#include <string>
#include "unorder.cpp"

using namespace std;

int main(){

    string input = " ";
    chaining table;
    while(getline(cin,input)){

        //read user input
        string command = " ";
        command = input[0];
        int para = stoi(input.substr(2));

        if(command == "n"){
            table.setSize(para);
            cout << "success" << endl;
        }

        else if(command == "i"){
            bool check = table.insert(para);
            if(check){
                cout << "success" << endl;
            }
            else if(!check){
                cout << "failure" << endl;
            }
        }

        else if(command == "s"){
            int check = table.search(para);
            if(check == -1){
                cout << "not found" << endl;
            }
            else{
                cout << "found in " << check << endl;
            }
        }

        else if(command == "d"){
            bool check = table.remove(para);
            if(check){
                cout << "success" << endl;
            }
            else if(!check){
                cout << "failure" << endl;
            }
        }
    }


    return 0;
}