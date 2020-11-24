#ifndef _BST_CONTAINER_
#define _BST_CONTAINER_
#include <iostream>
#include <assert.h>

//---------------------------------------------------------------------------
// Class BST
// ADT Binary Search Tree:
//   -- A binary tree is defined as a tree in which no node can have more 
//      than two children. The highest degree of any node is two. This 
//      indicates that the degree of a binary tree is zero, one, or two
//
// Assumption:
//   -- All node in left subtree of a node must be smaller.
//   -- All node in right subtree must be greater.
//   -- It has distinct node and duplicates are not allowed.
//   -- If the passed in node is already in tree, it will be deleted
//
// Implementation:
//   -- Function insert, retrieve, display, makeEmpty will need 
//      sub-function to help it traverse the tree recursively, insertHelper
//      retrieveHelper, displayHelper, emptyHelper will be called.
//---------------------------------------------------------------------------

template <typename T>
class BSTree {
    
public:
    BSTree();          // constructor
    ~BSTree();         // calls makeEmpty which deallocates all memory
    bool insert(T*);   // insert object into the tree
    bool retrieve(const T&, T*&) const;     // retrieve object
    void display() const;   // displays the contents of a tree to cout
    void makeEmpty();       // empty the current tree, deallocates all memory
    bool isEmpty() const;   // returns true if tree is empty

private:
    
    // node that has client data and left,right node
    struct Node {
        T* data;
        Node* right;
        Node* left;
    };

    Node* root;             // root of the tree

    // use for traverse recursively tree, then add node
    // first parameter is new node
    // second is for traversing
    bool insertHelper(T *, Node *&);

    // use for traversing recursive tree, then retrieve the node
    // first parameter is root
    // second is for target
    // third parameter is pointer point to target
    bool retrieveHelper(Node*, const T &, T*&) const;

    // use for traverse recursively tree, then print out data
    void displayHelper(Node *) const;

    // use for traverse recursively tree, then delete every node
    void makeEmptyHelper(Node *&);

};

//----------------------------------------------------------------------------
// constructor
// initialize the root
template<typename T>
BSTree<T>::BSTree() {
    root = nullptr;
}

//----------------------------------------------------------------------------
// deconstructor
// call makeEmpty to delete every node
template<typename T>
BSTree<T>::~BSTree() {
    makeEmpty();
}

//----------------------------------------------------------------------------
// insert
// call the insertHelper to traverse recursively
// the passed in node will be taken and insert in tree
// insert new node to left or right subtree
// if the node is already in tree, return false
template<typename T>
bool BSTree<T>::insert(T * newData) {

    // first node if tree is empty
    if (root == nullptr) {

        // add new client, and assign left and right subtree null pointer
        root = new Node{ newData, nullptr, nullptr };
        assert(root != nullptr); // out of memory
        return true;
    }

    // tree already has root
    else
        return insertHelper(newData, root);
}

//----------------------------------------------------------------------------
// insertHelper
// traverse recursively the tree
// this function is sub-function of insert
template<typename T>
bool BSTree<T>::insertHelper(T * newData, Node *& current) {
    
    // base case
    if (current == nullptr) {
        current = new Node{ newData, nullptr, nullptr };
        assert(current != nullptr); // out of memory
        return true;
    }

    // travere left
    else if (*newData < *current->data) {
        return insertHelper(newData, current->left);
    }

    // traverse right
    else if (*newData > *current->data) {
        return insertHelper(newData, current->right);
    }

    // duplicate is not allowed
    else {
        return false;
    }
}

//----------------------------------------------------------------------------
// retrieve
// retrieve the node that match with target
// call the retrieveHelper to traverse recursively
// return true if retrieve successfully
//        false target not in tree
template<typename T>
bool BSTree<T>::retrieve(const T & target, T *& retriever) const {
    
    // find the target by traversing recursively
    return retrieveHelper(root, target, retriever);
}

//----------------------------------------------------------------------------
// retrieveHelper
// recursively traverse the tree
// this function is sub-function of retrieve
// return true if found the target
//        false if not found the target
template<typename T>
bool BSTree<T>::retrieveHelper(Node* current, 
                            const T & target,
                            T *& retriever) const {
    
    // target not found
    if (current == nullptr) {
        retriever = nullptr;
        return false;
    }

    // travere left-sub tree
    if (target < *current->data) {
        return retrieveHelper(current->left, target, retriever);
    }

    // traverse right-sub tree
    else if (target > *current->data) {
        return retrieveHelper(current->right, target, retriever);
    }

    // target is found
    else {
        retriever = current->data;
        return true;
    }
}

//----------------------------------------------------------------------------
// display
// display the node of tree from left to right
// call the displayHelper to perform traverse recursively
template<typename T>
void BSTree<T>::display() const {

    // display the tree from left to right
    displayHelper(root);
}

// displayHelper
// traverse recursively the tree
// this function is sub-function of display
template<typename T>
void BSTree<T>::displayHelper(Node * current) const {
    
    // base case
    if (current == nullptr)
        return;

    // print from left to right subtree
    else {
        displayHelper(current->left);
        std::cout << *current->data << std::endl;
        displayHelper(current->right);
    }
}

//----------------------------------------------------------------------------
// makeEmpty
// delete every node from the tree
// this function also will be called when deconstructor is called
template<typename T>
void BSTree<T>::makeEmpty() {

    // early exit, tree is empty
    if (root == nullptr)
        return;

    // tree not empty
    // delete every node
    makeEmptyHelper(root);

    // root always null pointer
    root = nullptr;
}

//----------------------------------------------------------------------------
// makeEmptyHelper
// traverse recursively the tree
// this function is sub-function of makeEmpty
template<typename T>
void BSTree<T>::makeEmptyHelper(Node *& current) {
    
    // delete every node
    if (current != nullptr) {
        makeEmptyHelper(current->left);   // traverse left
        makeEmptyHelper(current->right);  // traverse right
        delete current->data;             // delete node data
        delete current;                   // delete node
    }
}

//----------------------------------------------------------------------------
// isEmpty
// check tree is empty or not
template<typename T>
bool BSTree<T>::isEmpty() const {
    return root == nullptr;
}
#endif // !_BST_CONTAINER_