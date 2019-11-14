#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "playlist.cpp"

using namespace std;

int main(){
    
    string input = " ";
    playlist list;
    while(getline(cin, input)){
        
        //get user input
        string command = " ";
        command = input[0];
        int play = 0;
        int erase = 0;
        string s = " ";

        //command: insert a song
        if(command == "i"){
            s = input.substr(2);
            song music;
            music.separate(s);
            list.insert(music);
        }

        //command: play a song
        else if(command == "p") {
            string temp = input.substr(2);
            play = stoi(temp);
            list.play(play);
        }

        //command: erase a song
        else if(command == "e"){
            string temp = input.substr(2);
            erase = stoi(temp);
            list.erase(erase);
        }

    }

    return 0;

}