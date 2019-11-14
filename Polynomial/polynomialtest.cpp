#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

#include "polynomial.cpp"

int main(){
    
    string input = " ";
    Polynomial empty;
    Polynomial current;
    Polynomial second;
    Polynomial expect;
    while(getline(cin, input)){

        //size of coeff array
        int size = 1;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == 59){
                size++;
            }
        }

        double coeff[size];
        int j = 0;
        for(int i = 0; i < size; i++){
            coeff[i] = 0.0;
        }

        istringstream s(input);
        string word = " ";
        string command = " ";
        int init = 0;
        if(input[0] == 'i'){
            while(s >> word){
                int i = 0;
                if(word[i] >= '0' && word[i] <= '9'){
                    init = stoi(word);
                }
                else if(word[0] >= 97 && word[0] <= 122){
                    command = word;
                }
            }
        }
        else{
            while(s >> word){
                int i = 0;
                int check = 0;
                while(i < word.size()){
                    if(word[i] == '.'){
                        check = 1;
                    }
                    i++;
                }

                //"." is found => coeff
                if(check){
                    double temp = stod(word);
                    coeff[j] = temp;
                    j++;
                }
                else if(word[0] >= 97 && word[0] <= 122){
                    command = word;
                }
            }
        }

        //perform commands
        bool check = true;

        if(command == "init"){
            empty.init(init);
            cout << "success" << endl;
        }

        else if(command == "coeff_p1"){
            current = empty.coeff(coeff);
            cout << "success" << endl;
        }

        else if(command == "coeff_p2"){
            second = empty.coeff(coeff);
            cout << "success" << endl;
        }

        else if(command == "get"){
            empty.init(size);
            expect = empty.coeff(coeff);
            check = current.compare(expect);
            if(check){
                cout << "success" << endl;
            }
            else{
                cout << "failure" << endl;
            }
        }

        else if(command == "eval"){
            check = current.eval(coeff[0], coeff[1]);
            if(check){
                cout << "success" << endl;
            }
            else{
                cout << "failure" << endl;
            }
        }

        else if(command == "add"){
            empty.init(size);
            expect = empty.coeff(coeff);
            Polynomial sum = current.add(second);
            check = sum.compare(expect);
            if(check){
                cout << "success" << endl;
            }
            else{
                cout << "failure" << endl;
            }
        }

        else if(command == "mult"){
            empty.init(size);
            expect = empty.coeff(coeff);
            Polynomial product = current.add(second);
            check = product.compare(expect);
            if(check){
                cout << "success" << endl;
            }
            else{
                cout << "failure" << endl;
            }
        }
    }
    return 0;
}