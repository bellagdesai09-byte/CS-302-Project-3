//BST.h

#ifndef BST_H
#define BST_H

#include "NotFoundException.h"
#include <iostream>
using namespace std;

/**
 * @struct Node
 * @brief Templated node structure for the BST.
 */
template<class ItemType>
struct Node {
    ItemType data;
    Node<ItemType>* left;
    Node<ItemType>* right;
    //Constructor to easily create new leaf nodes
Node(const ItemType& item) : data(item), left(nullptr), right(nullptr){}
};

/**
 * @class BST
 * @brief Generic Binary Search Tree implementation.
 * Requires ItemType to support Comparable operations (< and ==).
 */
template<class ItemType>
class BST {
protected:
Node<ItemType>* root;
int nodeCount; //Tracks size 
    
 //--- Protected Recursive Helpers ---
// These are doing my actual heavy lifting. I'm hiding them here so clients can't accidentally pass a bad pointer into the tree.

Node<ItemType>* addHelper(Node<ItemType>* nodePtr, const ItemType& newItem){
   // Base case: An empty spot has been found. Create and return the new node.
   if (nodePtr == nullptr){
      return new Node<ItemType>(newItem);
        }
   //Recursive step: Use the < operator to steer left or right.
   if (newItem < nodePtr->data) {
            nodePtr->left = addHelper(nodePtr->left, newItem);
   } else {
   //If it's greater than (or a duplicate), it goes to the right.
   nodePtr->right = addHelper(nodePtr->right, newItem);
   }
      return nodePtr;
   }

   void inorderHelper(void visit(ItemType&), Node<ItemType>* nodePtr) const {
   // Base case; If pointer is null, just return and do nothing.
    if (nodePtr != nullptr){
      inorderHelper(visit, nodePtr->left); //1. Go left
      ItemType item = nodePtr->data;
      visit(item);                         //2. Visit Root (the Action)
      inorderHelper(visit, nodePtr->right); //3. Go right
      }
   } 

bool containsHelper(Node<ItemType>* nodePtr, const ItemType& target) const {
   if (nodePtr == nullptr) {
   return false; // Base case: reached a dead end, it's not here.
      } else if (target == nodePtr->data) {
         return true; // Base case: found it.
      } else if (target < nodePtr->data) {
         return containsHelper(nodePtr->left, target); // Target is smaller, go left
      } else {
         return containsHelper(nodePtr->right, target); // Target is larger, go right
        }
   }

ItemType getEntryHelper(Node<ItemType>* nodePtr, const ItemType& target) const {
   if (nodePtr == nullptr) {
   throw NotFoundException("Item not found in the tree.");
   } else if (target == nodePtr->data) {
      return nodePtr->data;
   } else if (target < nodePtr->data) {
      return getEntryHelper(nodePtr->left, target);
   } else {
      return getEntryHelper(nodePtr->right, target);
   }
   }
    
void preorderHelper(void visit(ItemType&), Node<ItemType>* nodePtr) const {
      if (nodePtr != nullptr) {
      ItemType item = nodePtr->data;
      visit(item);                           //1. Visit Root
      preorderHelper(visit,nodePtr->left);   //2. Go Left 
      preorderHelper(visit, nodePtr->right); //3. Go Right
   }
   }

void postorderHelper(void visit(ItemType&), Node<ItemType>* nodePtr) const {
      if (nodePtr != nullptr) {
      postorderHelper(visit, nodePtr->left);    //1. Go Left
      postorderHelper(visit, nodePtr->right);   //2. Go Right
      ItemType item = nodePtr->data; 
      visit(item);                              //3. Visit Root
   }
   }

// Helper to find the inorder successor (leftmost node of the right subtree)
Node<ItemType>* removeLeftmostNode(Node<ItemType>* nodePtr, ItemType& inorderSuccessor){
      if (nodePtr->left == nullptr) {
         inorderSuccessor = nodePtr->data;
         return removeNode(nodePtr); // Delete the successor node
   } else {
      nodePtr->left = removeLeftmostNode(nodePtr->left, inorderSuccessor);
      return nodePtr;
    }
    }

// Helper that actually deletes the node and reconnects pointers 
Node<ItemType>* removeNode(Node<ItemType>* nodePtr){
   //Case 1: Leaf Node
   if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
      delete nodePtr;
      nodePtr = nullptr;
      return nodePtr;
   }
// Case 2: One Child (Left child only)
   else if (nodePtr->right == nullptr) {
Node<ItemType>* nodeToConnect = nodePtr->left;
      delete nodePtr;
      nodePtr = nullptr;
            return nodeToConnect;
        }
// Case 2: One Child (Right child only)
   else if (nodePtr->left == nullptr) {
   Node<ItemType>* nodeToConnect = nodePtr->right;
   delete nodePtr;
   nodePtr = nullptr;
      return nodeToConnect;
 }
 //Case 3: Two Children
    else { 
   ItemType newNodeValue;
   // Go to the right subtree, find the leftmost node, and save its data
   nodePtr->right = removeLeftmostNode(nodePtr->right, newNodeValue);
   //Replace this node's data with the successor's data
   nodePtr->data = newNodeValue;
     return nodePtr;
   }
   }

// Helper to navigate the tree to find the target it wants to remove.
   Node<ItemType>* removeValue(Node<ItemType>* nodePtr, const ItemType& target, bool& success){
      if (nodePtr == nullptr) {
      success = false; // Target not found
         return nullptr;
   }
   if (target == nodePtr->data) {
   //Target found! Triggering the actual removal.
      nodePtr = removeNode(nodePtr);
      success = true;
      } else if (target < nodePtr->data) {
            nodePtr->left = removeValue(nodePtr->left, target, success);
      } else {
            nodePtr->right = removeValue(nodePtr->right, target, success);
      }
        return nodePtr;
    }

// Deletes all nodes using a Post-Order traversal
   void destroyTree(Node<ItemType>* nodePtr) {
   if (nodePtr != nullptr) {
      destroyTree(nodePtr->left);
      destroyTree(nodePtr->right);
      delete nodePtr;
   }
   }

int getHeightHelper(Node<ItemType>* nodePtr) const {
   if (nodePtr == nullptr) {
      return 0;
}
   int leftHeight = getHeightHelper(nodePtr->left);
   int rightHeight = getHeightHelper(nodePtr->right);
        
   if (leftHeight > rightHeight) {
      return 1 + leftHeight;
   } else {
   return 1 + rightHeight;
   }
   }

bool isBalancedHelper(Node<ItemType>* nodePtr) const {
   if (nodePtr == nullptr) {
    return true;
  }
 int leftHeight = getHeightHelper(nodePtr->left);
 int rightHeight = getHeightHelper(nodePtr->right);

// Difference in height cannot be more than 1 (using safe math to avoid libraries)
   int diff = leftHeight - rightHeight;
   if (diff < -1 || diff > 1){
       return false;
   }
       return isBalancedHelper(nodePtr->left) && isBalancedHelper(nodePtr->right);
    }

public:
// --- Constructor & Core ---
BST() : root(nullptr), nodeCount(0){}

virtual ~BST(){
    clear();
 }
    
 bool isEmpty() const{
   return root == nullptr;
   }

int getNumberOfNodes() const {
  return nodeCount;
}

// --- Public Interface ---
bool add(const ItemType& newData){
// Kick off the recursive helper starting at the root
   root = addHelper(root, newData);
   nodeCount++;
   return true;
   }

void inorderTraverse(void visit(ItemType&)) const{
   inorderHelper(visit, root);
}

bool contains(const ItemType& target) const {
   return containsHelper(root, target);
}

ItemType getEntry(const ItemType& target) const {
return getEntryHelper(root, target);
}

void preorderTraverse(void visit(ItemType&)) const {
   preorderHelper(visit, root);
}

void postorderTraverse(void visit(ItemType&)) const {
   postorderHelper(visit, root);
}

bool remove(const ItemType& target) {
bool success = false;
root = removeValue(root, target, success);
   if (success) {
       nodeCount--;
   }
      return success;
   }

void clear() {
   destroyTree(root);
   root = nullptr;
   nodeCount = 0;
}

int getHeight() const {
   return getHeightHelper(root);
}

bool isBalanced() const {
   return isBalancedHelper(root);
}
};

#endif //BST_H