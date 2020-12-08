#include "media_collection.h"

//-----------------------------------------------------------------------------
// default constructor
MediaCollection::MediaCollection() {

    // nested specific type of movie into movie collection
    // set comedy type
    movies.insert(
        pair<MovieType, BSTree<Media>>(MovieType::ComedyType, comedies)
    );

    // set classic type
    movies.insert(
        pair<MovieType, BSTree<Media>>(MovieType::ClassicType, classics)
    );

    // set drama type
    movies.insert(
        pair<MovieType, BSTree<Media>>(MovieType::DramaType, dramas)
    );
    // further nested specific type of media go here...
}

//-----------------------------------------------------------------------------
// destructor
MediaCollection::~MediaCollection() {
}

//-----------------------------------------------------------------------------
// insert
// insert a new media into the system
bool MediaCollection::insert(Media* media) {

    // check movie type
    if (media->getMediaType() == MediaType::DVDMovieType)
        return insertMovie(media);
    // further extention type go here...

    // media type is not exist
    return false;
}

//-----------------------------------------------------------------------------
// insertMovie
// insert a new movie into the system
bool MediaCollection::insertMovie(Media* media) {
    MovieType type = dynamic_cast<Movie*>(media)->getMovieType();

    // insert comedy
    if (type == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).insert(media);
    }

    // insert classic
    else if (type == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).insert(media);
    }

    // insert drama
    else if (type == MovieType::DramaType) {
        return movies.at(MovieType::DramaType).insert(media);
    }

    // movie type is not exist
    else {
        return false;
    }
}

//-----------------------------------------------------------------------------
// retrieve
// retrieve the requested media type from the system
bool MediaCollection::retrieve(const Media& target, Media*& retriever) {

    // check media type
    if (target.getMediaType() == MediaType::DVDMovieType) {
        return retrieveMovie(target, retriever);
    }
    // further extention type go here...

    // media type is not exist
    return false;
}

//-----------------------------------------------------------------------------
// retrieveMovie
// retrieve the requested movie from the system
bool MediaCollection::retrieveMovie(const Media& target, Media*& retriever) {
    MovieType type =  dynamic_cast<const Movie&>(target).getMovieType();

    // retrieve comedy
    if (type == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).retrieve(target, retriever);
    }

    // retrieve classic
    else if (type == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).retrieve(target, retriever);
    }

    // retrieve drama
    else if (type == MovieType::DramaType) {
        return movies.at(MovieType::DramaType).retrieve(target, retriever);
    }

    // movie type is not exist
    else {
        return false;
    }
}

//-----------------------------------------------------------------------------
// remove
// remove the selective media type from the system
bool MediaCollection::remove(const Media& target) {

    // check media type
    if (target.getMediaType() == MediaType::DVDMovieType)
        return removeMovie(target);
    // further extention type go here...

    // media type is not exist
    return false;
}

//-----------------------------------------------------------------------------
// removeMovie
// remove the selective movie from the system
bool MediaCollection::removeMovie(const Media& target) {

    // retrieve comedy
    if (dynamic_cast<const Movie&>(target).getMovieType() 
        == MovieType::ComedyType) {
        return movies.at(MovieType::ComedyType).remove(target);
    }

    // retrieve classic
    else if (dynamic_cast<const Movie&>(target).getMovieType() 
        == MovieType::ClassicType) {
        return movies.at(MovieType::ClassicType).remove(target);
    }

    // retrieve drama
    else if (dynamic_cast<const Movie&>(target).getMovieType() 
        == MovieType::DramaType) {
        return movies.at(MovieType::DramaType).remove(target);
    }

    // movie type is not exist
    else {
        return false;
    }
}

//-----------------------------------------------------------------------------
// display
// Display all media to the system
void MediaCollection::display() const {
    movies.at(MovieType::ComedyType).display();
    movies.at(MovieType::DramaType).display();
    movies.at(MovieType::ClassicType).display();
}

//-----------------------------------------------------------------------------
// getTotalMedia
// return the total number of media in the system
int MediaCollection::getTotalMedia() const {
    return getTotalMovie();
}

//-----------------------------------------------------------------------------
// getTotalMovie
// return the number of movie to the system
int MediaCollection::getTotalMovie() const {
    int total = movies.at(MovieType::ComedyType).getTotalNode()
        + movies.at(MovieType::DramaType).getTotalNode()
        + movies.at(MovieType::ClassicType).getTotalNode();
    return total;
}
