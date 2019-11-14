#include <iostream>
#include <stdlib.h>
#include <vector>
#include "playlist.h"

using namespace std;

//song
song::song(){
    name = " ";
    artist = " ";
}

song::~song(){}

void song::separate(const string s){
    int position = s.find(";");
    name = s.substr(0,position);
    artist = s.substr(position+1);
}

//overload ==
bool song::operator==(const song s){
    int n = 0;
    int a = 0;

    if(name != s.name){
        n = 1;
    }

    if(artist != s.artist){
        a = 1;
    }

    if(n != 0 || a != 0) {
        return false;
    }

    return true;
}

string song::getName(){
    return name;
}

string song::getArtist(){
    return artist;
}

//playlist
playlist::playlist(){
    song s;
    list.push_back(s);
}

playlist::~playlist(){
    list.erase(list.begin(),list.end());
}

void playlist::insert(song s){
    bool check = search(s);
    if(check){
        cout << "can not insert " << s.getName() << ";" << s.getArtist() << endl;
        return;
    }   
    list.push_back(s);
    cout << "success" << endl;   
}

//search a song by song
bool playlist::search(const song s){
    for(int i = 1; i < list.size(); i++){
        if(list[i] == s){
            return true;
        }
    }
    return false;
}

//play a song
void playlist::play(int n){
    if(n >= list.size() || n <= 0){
        cout << "could not play " << n << endl;
        return;
    }
    cout << "played " << n << " " << list[n].getName() << ";" << list[n].getArtist() << endl;
}

//delete a song from the list
void playlist::erase(int n){
    if(n >= list.size() || n <= 0){
        cout << "could not erase " << n << endl;
        return;
    }
    list.erase(list.begin()+n);
    cout << "success" << endl;
}