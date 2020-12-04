#include "media_movie.h"

//----------------------------------------------------------------------------
// Movie
// Destructor
Movie::~Movie() {}

//----------------------------------------------------------------------------
// setDirector
// set the director for the movie
void Movie::setDirector(string director) {
    this->director = director;
}

//----------------------------------------------------------------------------
// setTitle
// set the title for the movie
void Movie::setTitle(string title) {
    this->title = title;
}

//----------------------------------------------------------------------------
// setYear
// Set the year for the movie
void Movie::setYear(int year) {
    this->year = year;
}

//----------------------------------------------------------------------------
// getDirector
// Return the director of the movie
string Movie::getDirector() const {
    return this->director;
}

//----------------------------------------------------------------------------
// getTitle
// Return the title of the movie
string Movie::getTitle() const {
    return this->title;
}

//----------------------------------------------------------------------------
// getYear
// Return the year of the movie
int Movie::getYear() const {
    return this->year;
}

//----------------------------------------------------------------------------
// getMediaType
// Return the type of the movie
MediaType Movie::getMediaType() const {
    return MOVIE;
}

//----------------------------------------------------------------------------
// Operator<<
// operator to print out to system
// use to use << opertor
ostream& operator<<(ostream & out, const Movie & movie) {
    movie.print(out);
    return out;
}
