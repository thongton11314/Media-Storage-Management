// hashtable must be implement by developer. For the collision, can use library data stucture.

#ifndef _HASTABLE_
#define _HASTABLE_
#include <string>
#include <map>

using namespace std;

const int TABLE_SIZE = 97;

// add comment here
template <typename Key, typename Val>
class Hashtable {
public:
    Hashtable();
    Hashtable(const Hashtable & other);
    ~Hashtable();
    bool insertKeyValue(Key key, Val * val);
    bool retrieveValue(Key key, Val *& retriever) const;
    const Val * getValue(Key key) const;
    bool removeValue(Key key);

private:
    // .insert(pair<Key, Val>(key, val));
    map<Key, Val> * table[TABLE_SIZE];      // a map for each bucket
    int numberToHashValue(Key keyHash);     // number to hash value
    void makeEmpty();                       // make the table empty
    // add more code here, use hash table
};

// implementation is bellow

template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable() {
    
}

template <typename Key, typename Val>
Hashtable<Key, Val>::Hashtable(const Hashtable & other) {
    
}

template <typename Key, typename Val>
Hashtable<Key, Val>::~Hashtable() {
    makeEmpty();
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::insertKeyValue(Key key, Val * val) {
    return false;
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::retrieveValue(Key key, Val *& retriever) const {
    return false;
}

template <typename Key, typename Val>
const Val * Hashtable<Key, Val>::getValue(Key key) const {
    return nullptr;
}

template <typename Key, typename Val>
bool Hashtable<Key, Val>::removeValue(Key key) {
    return false;
}

template <typename Key, typename Val>
int Hashtable<Key, Val>::numberToHashValue(Key keyHash) {
    return NULL;
}

template <typename Key, typename Val>
void Hashtable<Key, Val>::makeEmpty() {
    
}

#endif //!_HASTABLE_