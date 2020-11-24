#include "media_movie.h"

Movie::~Movie() {}

void Movie::setDirector(string director) {
    this->director = director;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setYear(int year) {
    this->year = year;
}

string Movie::getDirector() const {
    return this->director;
}

string Movie::getTitle() const {
    return this->title;
}

int Movie::getYear() const {
    return this->year;
}

string Movie::getMediaType() const {
    return "DVDMovie";
}

// use to use << opertor
ostream& operator<<(ostream & out, const Movie & movie) {
    movie.print(out);
    return out;
}