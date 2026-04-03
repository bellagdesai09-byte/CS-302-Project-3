// Song.h
#ifndef SONG_H
#define SONG_H
#include "SongInterface.h"
#include "Comparable.h"
using namespace std;
/**
 * @class Song
 * @brief Represents a single music track in the library.
 * Inhertis from SongInterface for basic properties and Comparable for BST sorting.
 */
class Song : public SongInterface, public Comparable<Song>
{
private:
    string title;
    string artist;
    int year;

public:
    Song();
    Song(string title, string artist, int year);

    string getTitle() const;
    string getArtist() const;
    int getYear() const;

    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setYear(int newYear);

    void display() const override;

    bool operator<(const Song& other) const override;
    bool operator==(const Song& other) const override;

};
#endif