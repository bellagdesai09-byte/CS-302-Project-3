// MusicLibrary.cpp
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary() {
    //BST constructor is automatically called
}

MusicLibrary::~MusicLibrary(){
    //clear() will be implemented tomorrow to handle cleanup
}


bool MusicLibrary::add(const Song& newSong) {
    // Pass the insertion logic down to generic tree
    return libraryTree.add(newSong);
}

void MusicLibrary::inorderTraverse(void visit(Song&)) const {
    // Pass the traversal logic down to the generic tree
    libraryTree.inorderTraverse(visit);
}

int MusicLibrary::getNumberOfNodes() const {
    return libraryTree.getNumberOfNodes();
}
bool MusicLibrary::isEmpty() const {
    return libraryTree.isEmpty();
}

int MusicLibrary::getHeight() const { 
    return 0; 
}
bool MusicLibrary::isBalanced() const { 
    return false; 
}
void MusicLibrary::clear() {}
Song MusicLibrary::getEntry(const Song& anEntry) const {
    return libraryTree.getEntry(anEntry);
}
bool MusicLibrary::contains(const Song& aSong) const { 
    return libraryTree.contains(aSong);
}
void MusicLibrary::preorderTraverse(void visit(Song&)) const {}
void MusicLibrary::postorderTraverse(void visit(Song&)) const {}