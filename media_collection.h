#ifndef _MEDIA_COLLECTION_
#define _MEDIA_COLLECTION_
#include <iostream>
#include <map>
#include "media.h"
#include "bst.h"

using namespace std;

// Class MediaCollection:
//  Description:
//   - This class control and modify what is in the media
//  Implementation:
//   - Create Media:
//     - Add a new type of media to the collection 
class MediaCollection {
public:

    // constructor
    MediaCollection();

    // deconstructor
    ~MediaCollection();

    // insert media
    bool insert(Media* media);

    // retrieve media
    bool retrieve(const Media& target, Media*& retriever);

    // remove media
    bool remove(const Media& target);

    // display media
    void display() const;

    // get total media
    int getTotalMedia() const;
    
    // get total movie
    int getTotalMovie() const;
private:

    // hold comediesCollection, dramasCollection, classicCollection
    map<MovieType, BSTree<Media>> movieCollection;
    BSTree<Media> comedyCollection;
    BSTree<Media> dramaCollection;
    BSTree<Media> classicCollection;

    // further media type collection extention go here

    // ultility function for insert movie
    bool insertMovie(Media* movie);
    bool retrieveMovie(const Media& target, Media*& retriever);
    bool removeMovie(const Media& target);
};
#endif //!_MEDIA_COLLECTION_