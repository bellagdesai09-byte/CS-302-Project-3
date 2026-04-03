//Song.cpp
#include "Song.h"
// ========Constructors========
//Default constructor initializes to safe empty values
Song::Song() {
    this->title = "";
    this->artist = "";
    this->year = 0;
}

Song::Song(string title, string artist, int year){
    this->title = title;
    this->artist = artist;
    this->year = year;

}
// ==========Getters==========
string Song::getTitle()const {
    return this->title;
}
string Song::getArtist() const {
    return this->artist;
}

int Song::getYear() const {
    return this->year;
}
//=========Setters==========
void Song::setTitle(const string& newTitle){
    title = newTitle;
}

void Song::setArtist(const string& newArtist){
    artist = newArtist;
}
void Song::setYear(int newYear){
    year = newYear;
}
void Song::display(ostream& out) const {
// Formats the output so the traversals print cleanly in the terminal
    out << title << " by " << artist << "(" << year << ")" <<endl;
}

// --- Comparable<Song> Implementations ---

bool Song::operator<(const Song& other) const{
    //The BST uses this to determine if it should go down the left branch.
    // We compare by title to maintain alphabetical order.
    return this->title < other.title;
}

bool Song::operator==(const Song& other) const {
    //The BST uses this to determine if it has found the exact target node.
    return this->title == other.title;
}