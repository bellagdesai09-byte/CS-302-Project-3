//MusicLibrary.h
#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

#include "BinaryTreeInterface.h"
#include "BST.h"
#include "Song.h"

/**
 * @class MusicLibrary
 * @brief Acts as the manager for the song collection.
 * Implements the required interface and uses a BST via composition.
 */
class MusicLibrary : public BinaryTreeInterface<Song>
{
private:
    //Composition: The library "has a" BST that stores Songs
    BST<Song> libraryTree;

public:
    MusicLibrary();
    virtual ~MusicLibrary();

    // --- Core Methods---
    bool isEmpty() const override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    bool add(const Song& newSong) override;
    bool remove(const Song& aSong) override;
    void clear() override;
    bool isBalanced() const override;

    // --- Search Methods ---
    Song getEntry(const Song& anEntry) const override;
    bool contains(const Song& aSong) const override;

    // --- Traversals ---
    void preorderTraverse(void visit(Song&)) const override;
    void inorderTraverse(void visit(Song&)) const override;
    void postorderTraverse(void visit(Song&)) const override;
};
#endif // MUSIC_LIBRARY_H