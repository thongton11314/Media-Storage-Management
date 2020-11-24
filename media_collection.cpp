#include "media_collection.h"

MediaCollection::MediaCollection() {}

MediaCollection::~MediaCollection() {}

bool MediaCollection::insert(Media * movie) {
    return collection.insert(movie);
}

bool MediaCollection::retrieve(const Media& target, Media *& retriever) {
    return collection.retrieve(target, retriever);
}

const Media * MediaCollection::getAMedia(const Media & target) {
    return nullptr;
}

void MediaCollection::display() const {
    collection.display();
}