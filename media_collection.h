// add comments here
#ifndef _MEDIA_COLLECTION_
#define _MEDIA_COLLECTION_
#include <iostream>
#include "media.h"
#include "media_movie.h"
#include "bst.h"

// add comments here
class MediaCollection {
public:
    MediaCollection();
    ~MediaCollection();
    bool insert(Media * media);
    bool retrieve(const Media & target, Media *& retriever);
    const Media * getAMedia(const Media & target);
    void display() const;
private:
    BSTree<Media> collection;
};

#endif //!_MEDIA_COLLECTION_