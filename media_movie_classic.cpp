#include "media_movie_classic.h"

Classic::Classic() {
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->majorActorFirst = DEFAULT_PERSON;
    this->majorActorLast = DEFAULT_PERSON;
    this->month =  DEFAULT_NUM;
    this->year = DEFAULT_NUM;
}

Classic::Classic(const Classic & other) {
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->majorActorFirst = other.majorActorFirst;
    this->majorActorLast = other.majorActorLast;
    this->month = other.month;
    this->year = other.year;
}

Classic::~Classic() {}

bool Classic::setData(ifstream & infile) {

    // set up stock
    infile.ignore();
    infile >> this->stock;

    // set up director
    infile.ignore();
    getline(infile >> ws, this->director, ',');

    // set up title
    infile.ignore();
    getline(infile >> ws, this->title, ',');

    // set major actor
    infile >> this->majorActorFirst;
    infile >> this->majorActorLast;

    // set month
    infile.ignore();
    infile >> this->month;

    // set year
    infile.ignore();
    infile >> this->year;

    // end of line
    infile.ignore();
    string eol;
    getline(infile, eol);

    return true;
}

void Classic::setMajorActorFirst(string name) {
    this->majorActorFirst = name;
}

void Classic::setMajorActorLast(string name) {
    this->majorActorLast = name;
}

void Classic::setMonth(int month) {
    this->month = month;
}

int Classic::getMonth() const {
    return this->month;
}

string Classic::getMajorActorFirst() const {
    return this->majorActorFirst;
}

string Classic::getMajorActorLast() const {
    return this->majorActorLast;
}

char Classic::getMovieType() const {
    return 'C';
}

bool Classic::operator<(const Media & other) const {
    const Media * ptrMedia = &other;
    const Classic * ptrClassic = dynamic_cast<const Classic*>(ptrMedia);
    int thisDateToInt = (this->getYear() * 10000) 
                        + (this->getMonth() * 100);
    int otherDateToInt = (ptrClassic->getYear() * 10000) 
                        + (ptrClassic->getMonth() * 100);

    // compare date release
    if (thisDateToInt != otherDateToInt)
        return thisDateToInt < otherDateToInt;

    // compare major actor first name
    if (this->getMajorActorFirst().compare(ptrClassic->getMajorActorFirst()) != 0)
        return this->getMajorActorFirst().compare(ptrClassic->getMajorActorFirst()) < 0;

    // compare major actor last name
    if (this->getMajorActorLast().compare(ptrClassic->getMajorActorLast()) != 0)
        return this->getMajorActorLast().compare(ptrClassic->getMajorActorLast()) < 0;

    return false;
}

bool Classic::operator<=(const Media & other) const {
    const Media * ptrMedia = &other;
    const Classic * ptrClassic = dynamic_cast<const Classic*>(ptrMedia);
    int thisDateToInt = (this->getYear() * 10000) 
                        + (this->getMonth() * 100);
    int otherDateToInt = (ptrClassic->getYear() * 10000) 
                        + (ptrClassic->getMonth() * 100);

    // compare date release
    if (thisDateToInt > otherDateToInt)
        return true;

    // compare major actor first name
    if (this->getMajorActorFirst().compare(ptrClassic->getMajorActorFirst()) > 0)
        return false;

    // compare major actor last name
    if (this->getMajorActorLast().compare(ptrClassic->getMajorActorLast()) > 0)
        return false;

    return true;
}

bool Classic::operator>(const Media & other) const {
    const Media * ptr = &other;
    return !(*this < *(dynamic_cast<const Classic*>(ptr)));
}

bool Classic::operator>=(const Media & other) const {
    const Media * ptrMedia = &other;
    const Classic * ptrClassic = dynamic_cast<const Classic*>(ptrMedia);
    int thisDateToInt = (this->getYear() * 10000) 
                        + (this->getMonth() * 100);
    int otherDateToInt = (ptrClassic->getYear() * 10000) 
                        + (ptrClassic->getMonth() * 100);

    // compare date release
    if (thisDateToInt < otherDateToInt)
        return true;

    // compare major actor first name
    if (this->getMajorActorFirst().compare(ptrClassic->getMajorActorFirst()) < 0)
        return false;

    // compare major actor last name
    if (this->getMajorActorLast().compare(ptrClassic->getMajorActorLast()) < 0)
        return false;

    return true;
}

bool Classic::operator==(const Media & other) const {
    const Media * ptrMedia = &other;
    const Classic * ptrClassic = dynamic_cast<const Classic*>(ptrMedia);
    int thisDateToInt = (this->getYear() * 10000) 
                        + (this->getMonth() * 100);
    int otherDateToInt = (ptrClassic->getYear() * 10000) 
                        + (ptrClassic->getMonth() * 100);
    if ((thisDateToInt == otherDateToInt)
        && (this->getMajorActorFirst().compare(ptrClassic->getMajorActorFirst()) == 0)
        && (this->getMajorActorLast().compare(ptrClassic->getMajorActorLast()) == 0))
        return true;
    return false;
}

bool Classic::operator!=(const Media & other) const {
    const Media * ptr = &other;
    return !(*this == *(dynamic_cast<const Classic*>(ptr)));
}

void Classic::print(ostream & stream) const {
    cout << this->getMovieType() << ", " 
    << this->getStock() << ", "
    << this->getDirector() << ", "
    << this->getTitle() << ", "
    << this->getMajorActorFirst() << " " << this->getMajorActorLast() << ", "
    << this->getMonth() << ", "
    << this->getYear() << ". ";
}

ostream & operator<<(ostream & out, const Classic & movie) {
    movie.print(out);
    return out;
}