#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>
#include "bst.h"

using namespace std;

// table size
const int TABLE_SIZE = 97;

// Class Hashtable:
//  Description:
//   - This class create a hashtable to store key and value within the table
//  Implementation:
//   - Hashtable is impletemnted by using probing technique
//      - Binary Search Tree is used as each bucket
template <typename Key, typename Val>
class Hashtable {
public:

    // constructor
    Hashtable();

    // deconstructor
    ~Hashtable();

    // insert pair
    bool insertKeyValue(Key key, Val * val);
    
    // retrieve value by key
    bool retrieveValue(Key key, Val *& retriever) const;
    
    // get value by key
    const Val * getValue(Key key) const;

    // remove value by key
    bool removeValue(Key key);

    // display all value
    void display() const;
private:

    // bst as each bucket
    BSTree<Val> * table[TABLE_SIZE];        // a map for each bucket

    // make the table empty
    void makeEmpty();
};

//----------------------------------------------------------------------------
// constructor
template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable() {

    // initialize all bucket as nullptr
    for (int i = 0; i < TABLE_SIZE; i++) {
        this->table[i] = nullptr;
    }
}


//----------------------------------------------------------------------------
// destructor
template <typename Key, typename Val>
Hashtable<Key, Val>::~Hashtable() {
    makeEmpty();
}

//----------------------------------------------------------------------------
// insertKeyValue
// insert object which is val into bucket
template <typename Key, typename Val>
bool Hashtable<Key, Val>::insertKeyValue(Key key, Val * val) {
    
    // get hash number
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    // can not be negative
    if (hash < 0) {
        return false;
    }

    // create new tree
    if (table[hash] == nullptr) {
        table[hash] = new BSTree<Val>();
        return table[hash]->insert(val);
    }

    // insert in vailable bucket, and handle collision
    else {

        // if return false, front end incharge of memory management
        return table[hash]->insert(val);
    }
    return false;
}

//----------------------------------------------------------------------------
// retrieveValue
// retrieve the value of the key from the table
template <typename Key, typename Val>
bool Hashtable<Key, Val>::retrieveValue(Key key, Val *& retriever) const {

    // get hash number
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    // can not be negative
    if (hash < 0) {
        return false;
    }

    // empty bucket
    if (table[hash] == nullptr) {
        return false;
    }

    // check value
    else {
        Val* tempRetrive = nullptr;
        const Val tempTarget(key);
        return table[hash]->retrieve(tempTarget, retriever);
    }

    return false;
}

//----------------------------------------------------------------------------
// getValue
// get the value of the key
template <typename Key, typename Val>
const Val * Hashtable<Key, Val>::getValue(Key key) const {

    // get hash number
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    // can not be negative
    if (hash < 0) {
        return nullptr;
    }

    // empty bucket
    if (table[hash] == nullptr) {
        return nullptr;
    }

    // find the bucket at bst root, or need to be traverse the tree
    else {

        Val* tempRetrive = nullptr;
        const Val tempTarget(key);
        if (table[hash]->retrieve(tempTarget, tempRetrive)) {
            return tempRetrive;
        }
        return nullptr;
    }
    return nullptr;
}

//----------------------------------------------------------------------------
// removeValue
// remove the value of the key 
template <typename Key, typename Val>
bool Hashtable<Key, Val>::removeValue(Key key) {

    // get hash number
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    // can not be negative
    if (hash < 0) {
        return false;
    }

    // empty bucket
    if (table[hash] == nullptr) {
        return false;
    }
    else {
        Val* tempRetrive = nullptr;
        const Val tempTarget(key);
        return table[hash]->remove(tempTarget);
    }
}

//----------------------------------------------------------------------------
// display
// display the hashtable 
template<typename Key, typename Val>
void Hashtable<Key, Val>::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            table[i]->display();
        }
    }
}

//----------------------------------------------------------------------------
// makeEmpty
// clear the hashtable 
template <typename Key, typename Val>
void Hashtable<Key, Val>::makeEmpty() {
    
    // delete the bucket
    for (int i = 0; i < TABLE_SIZE; i++) {

        // delete tree
        if (this->table[i] != nullptr) {
            this->table[i]->makeEmpty();

            // delete bucket
            delete this->table[i];
            this->table[i] = nullptr;
        }
    }
}
#endif //!_HASTABLE_