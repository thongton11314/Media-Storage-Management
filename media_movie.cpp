#include "media_movie.h"

//-----------------------------------------------------------------------------
// destructor
Movie::~Movie() {}

//-----------------------------------------------------------------------------
// setDirector
// set the director for the movie
void Movie::setDirector(string director) {
    this->director = director;
}

//-----------------------------------------------------------------------------
// setTitle
// set the title for the movie
void Movie::setTitle(string title) {
    this->title = title;
}

//-----------------------------------------------------------------------------
// setYear
// Set the year for the movie
void Movie::setYear(int year) {
    this->year = year;
}

//-----------------------------------------------------------------------------
// getDirector
// return the director of the movie
string Movie::getDirector() const {
    return this->director;
}

//-----------------------------------------------------------------------------
// getTitle
// return the title of the movie
string Movie::getTitle() const {
    return this->title;
}

//-----------------------------------------------------------------------------
// getYear
// return the year of the movie
int Movie::getYear() const {
    return this->year;
}

//-----------------------------------------------------------------------------
// getMediaType
// return the type of the movie
MediaType Movie::getMediaType() const {
    return MediaType::DVDMovieType;
}

//-----------------------------------------------------------------------------
// operator<<
// operator to print out to system
// use to use << opertor
ostream& operator<<(ostream & out, const Movie & movie) {
    movie.print(out);
    return out;
}