#include <iostream>
#include <vector>
#include <string>

using namespace std;

class song{

    private:
    string name;
    string artist;

    public:
    song();
    ~song();

    //separate name and artist
    void separate(const string s);

    //overload ==
    bool operator==(const song s);

    //get name
    string getName();

    //get artist
    string getArtist();
    
};

class playlist{

    private:
    vector<song> list;
    
    //search a song by song
    bool search(const song s);

    public:
    playlist();
    ~playlist();

    //insert a song
    void insert(song s);
    
    //play a song
    void play(int n);

    //delete a song
    void erase(int n);

};