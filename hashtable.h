// hashtable must be implement by developer. For the collision, can use library data stucture.

#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>
#include "bst.h"

using namespace std;

const int TABLE_SIZE = 97;

// add comment here
template <typename Key, typename Val>
class Hashtable {
public:
    Hashtable();
    Hashtable(Key key, Val val);
    Hashtable(const Hashtable & other);
    ~Hashtable();
    bool insertKeyValue(Key key, Val * val);
    bool retrieveValue(Key key, Val *& retriever);
    const Val * getValue(Key key);
    bool removeValue(Key key);

private:

    // bst as each bucket
    BSTree<Val> * table[TABLE_SIZE];      // a map for each bucket

    void makeEmpty();                       // make the table empty
    // add more code here, use hash table
};


// implementation is bellow

// constructor
template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable() {

    // initialize all bucket as nullptr
    for (int i = 0; i < TABLE_SIZE; i++) {
        this->table[i] = nullptr;
    }
}

// constuctor
template<typename Key, typename Val>
Hashtable<Key, Val>::Hashtable(Key key, Val val) {
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i])
		{
            delete table[i];
            delete table[i];
            delete table[i];
		}
//need to finish this
	}

	delete Table;
}

// copy constructor
template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable(const Hashtable & other) {
    
}

// dafult constructor
template <typename Key, typename Val>
Hashtable<Key, Val>::~Hashtable() {
    makeEmpty();
}

// insert object which is val into bucket
template <typename Key, typename Val>
bool Hashtable<Key, Val>::insertKeyValue(Key key, Val * val) {
    
    // key cannot be negative
    if (key < 0) {
        return false;
    }

    // get hash number
    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

    // create new tree
    if (table[hash] == nullptr) {
        table[hash] = new BSTree<Val>();
        return table[hash]->insert(val);
    }

    // collision
    else {
        return table[hash]->insert(val);
    }
    return false;
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::retrieveValue(Key key, Val *& retriever) {
    // retrieve object by key from bucket, if collision look into bst
        // return true if successful, otherwise false
    return false; // need to be coded
}

template <typename Key, typename Val>
const Val * Hashtable<Key, Val>::getValue(Key key) {

    const int hash = reinterpret_cast<const int&>(key) % TABLE_SIZE;

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

template <typename Key, typename Val>
bool Hashtable<Key, Val>::removeValue(Key key) {
    // remove object in the bucket, if collision look in to bst
        // return true if remove successful
        // return false if remove fail
    return false; // need to be coded
}

template <typename Key, typename Val>
void Hashtable<Key, Val>::makeEmpty() {
    
    // delete the bucket
    for (int i = 0; i < TABLE_SIZE; i++) {

        // delete tree
        if (this->table[i] != nullptr) {
            this->table[i]->makeEmpty();
        }

        // delete bucket
        delete this->table[i];
        this->table[i] = nullptr;
    }
    
}

#endif //!_HASTABLE_
