// MusicLibrary.cpp
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary() {
    //BST constructor is automatically called
}

MusicLibrary::~MusicLibrary(){
    // Clean up memory when program ends
clear();
}

// --- Core Methods ---

bool MusicLibrary::add(const Song& newSong) {
    // Pass the insertion logic down to generic tree
    return libraryTree.add(newSong);
}

bool MusicLibrary::remove(const Song& aSong) {
    return libraryTree.remove(aSong);
}

int MusicLibrary::getNumberOfNodes() const {
    return libraryTree.getNumberOfNodes();
}
bool MusicLibrary::isEmpty() const {
    return libraryTree.isEmpty();
}
// --- Search Methods ---
Song MusicLibrary::getEntry(const Song& anEntry) const {
    return libraryTree.getEntry(anEntry);
}
bool MusicLibrary::contains(const Song& aSong) const { 
    return libraryTree.contains(aSong);
}
// --- Traversals ---
void MusicLibrary::inorderTraverse(void visit(Song&)) const {
    // Pass the traversal logic down to the generic tree
    libraryTree.inorderTraverse(visit);
}
void MusicLibrary::preorderTraverse(void visit(Song&)) const {
    libraryTree.preorderTraverse(visit);
}
void MusicLibrary::postorderTraverse(void visit(Song&)) const {
    libraryTree.postorderTraverse(visit);
}
// ---Other Methods---
int MusicLibrary::getHeight() const { 
    return libraryTree.getHeight(); 
}
bool MusicLibrary::isBalanced() const { 
    return libraryTree.isBalanced(); 
}
void MusicLibrary::clear() {
    libraryTree.clear();
}



