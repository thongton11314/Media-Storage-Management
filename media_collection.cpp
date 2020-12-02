#include "media_collection.h"

MediaCollection::MediaCollection() {

    // set comedy type
    movieCollection.insert(
        pair<MovieType, BSTree<Media>>(COMEDY, comedyCollection)
    );

    // set classic type
    movieCollection.insert(
        pair<MovieType, BSTree<Media>>(CLASSIC, classicCollection)
    );

    // set drama type
    movieCollection.insert(
        pair<MovieType, BSTree<Media>>(DRAMA, dramaCollection)
    );
}

MediaCollection::~MediaCollection() {}

bool MediaCollection::insert(Media* media) {

    // check media type
    if (media->getMediaType() == MOVIE)
        return insertMovie(media);

    // media type is not exist
    return false;
}

bool MediaCollection::insertMovie(Media* media) {
    MovieType type = dynamic_cast<Movie*>(media)->getMovieType();

    // insert comedy
    if (type == COMEDY) {
        return movieCollection.at(COMEDY).insert(media);
    }

    // insert classic
    else if (type == CLASSIC) {
        return movieCollection.at(CLASSIC).insert(media);
    }

    // insert drama
    else if (type == DRAMA) {
        return movieCollection.at(DRAMA).insert(media);
    }

    // movie type is not exist
    else {
        return false;
    }
}

bool MediaCollection::retrieve(const Media& target, Media*& retriever) {

    // check media type
    if (target.getMediaType() == MOVIE) {
        return retrieveMovie(target, retriever);
    }

    // media type is not exist
    else {
        return false;
    }
}

bool MediaCollection::retrieveMovie(const Media& target, Media*& retriever) {
    MovieType type =  dynamic_cast<const Movie&>(target).getMovieType();

    // retrieve comedy
    if (type == COMEDY) {
        return movieCollection.at(COMEDY).retrieve(target, retriever);
    }

    // retrieve classic
    else if (type == CLASSIC) {
        return movieCollection.at(CLASSIC).retrieve(target, retriever);
    }

    // retrieve drama
    else if (type == DRAMA) {
        return movieCollection.at(DRAMA).retrieve(target, retriever);
    }

    // movie type is not exist
    else {
        return false;
    }
}

bool MediaCollection::remove(const Media& target) {

    // check media type
    if (target.getMediaType() == MOVIE)
        return removeMovie(target);

    // media type is not exist
    return false;
}

bool MediaCollection::removeMovie(const Media& target) {

    // retrieve comedy
    if (dynamic_cast<const Movie&>(target).getMovieType() == COMEDY) {
        return movieCollection.at(COMEDY).remove(target);
    }

    // retrieve classic
    else if (dynamic_cast<const Movie&>(target).getMovieType() == CLASSIC) {
        return movieCollection.at(CLASSIC).remove(target);
    }

    // retrieve drama
    else if (dynamic_cast<const Movie&>(target).getMovieType() == DRAMA) {
        return movieCollection.at(DRAMA).remove(target);
    }

    // movie type is not exist
    else {
        return false;
    }
}

void MediaCollection::display() const {
    movieCollection.at(COMEDY).display();
    movieCollection.at(DRAMA).display();
    movieCollection.at(CLASSIC).display();
}

int MediaCollection::getTotalMedia() const {
    return getTotalMovie();
}

int MediaCollection::getTotalMovie() const {
    int total = movieCollection.at(COMEDY).getTotalNode()
        + movieCollection.at(CLASSIC).getTotalNode()
        + movieCollection.at(DRAMA).getTotalNode();
    return total;
}