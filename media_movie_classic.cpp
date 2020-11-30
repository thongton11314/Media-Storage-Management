#include "media_movie_classic.h"

Classic::Classic() {
    this->type = CLASSIC;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->majorActorFirst = DEFAULT_PERSON;
    this->majorActorLast = DEFAULT_PERSON;
    this->month =  DEFAULT_NUM;
    this->year = DEFAULT_NUM;
}

Classic::Classic(const Classic & other) {
    this->type = other.type;
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
    infile.ignore();
    infile >> this->majorActorFirst;
    infile.ignore();
    infile >> this->majorActorLast;

    // set month
    infile.ignore();
    infile >> this->month;

    // set year
    infile.ignore();
    infile >> this->year;

    // end of line
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

MovieType Classic::getMovieType() const {
    return this->type;
}

string Classic::getHashKey() const {
    return to_string(month)
        + " " + to_string(year)
        + " " + majorActorFirst
        + " " + majorActorLast;
}

// arithmetic operator, sort by release date and major actor
bool Classic::operator<(const Media & other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear())
        return this->getYear() < dynamic_cast<const Classic&>(other).getYear();

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth())
        return this->getMonth() < dynamic_cast<const Classic&>(other).getMonth();

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) < 0;
}

// arithmetic operator, sort by release date and major actor
bool Classic::operator<=(const Media & other) const {
    if (this->getYear() > dynamic_cast<const Classic&>(other).getYear())
        return false;

    if (this->getMonth() > dynamic_cast<const Classic&>(other).getMonth())
        return false;

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) <= 0;
}

// arithmetic operator, sort by release date and major actor
bool Classic::operator>(const Media & other) const {
    if (this->getYear() != dynamic_cast<const Classic&>(other).getYear())
        return this->getYear() > dynamic_cast<const Classic&>(other).getYear();

    if (this->getMonth() != dynamic_cast<const Classic&>(other).getMonth())
        return this->getMonth() > dynamic_cast<const Classic&>(other).getMonth();

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) > 0;
}

// arithmetic operator, sort by release date and major actor
bool Classic::operator>=(const Media & other) const {
    if (this->getYear() < dynamic_cast<const Classic&>(other).getYear())
        return false;

    if (this->getMonth() < dynamic_cast<const Classic&>(other).getMonth())
        return false;

    return this->getMajorActorFirst().compare(
        dynamic_cast<const Classic&>(other).getMajorActorFirst()
    ) >= 0;
}

// arithmetic operator, sort by release date and major actor
bool Classic::operator==(const Media & other) const {

    const Classic& ptrClassic = dynamic_cast<const Classic&>(other);
    return (this->getYear() == dynamic_cast<const Classic&>(other).getYear())
        && (this->getMonth() == dynamic_cast<const Classic&>(other).getMonth()
        && (this->getMajorActorFirst().compare(
            dynamic_cast<const Classic&>(other).getMajorActorFirst()
        ) == 0));
}

Media & Classic::operator=(const Media& other) {
    this->type = dynamic_cast<const Classic&>(other).getMovieType();
    this->stock = dynamic_cast<const Classic&>(other).getStock();
    this->director = dynamic_cast<const Classic&>(other).getDirector();
    this->title = dynamic_cast<const Classic&>(other).getTitle();
    this->majorActorFirst = dynamic_cast<const Classic&>(other).getMajorActorFirst();
    this->majorActorLast = dynamic_cast<const Classic&>(other).getMajorActorLast();
    this->month = dynamic_cast<const Classic&>(other).getMonth();
    this->year = dynamic_cast<const Classic&>(other).getYear();
    return *this;
}

bool Classic::operator!=(const Media & other) const {
    return !(*this == dynamic_cast<const Classic&>(other));
}

void Classic::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->getStock() << ", "
    << this->getDirector() << ", "
    << this->getTitle() << ", "
    << this->getMajorActorFirst() << " " << this->getMajorActorLast() << ", "
    << this->getMonth() << ", "
    << this->getYear();
}

ostream & operator<<(ostream & out, const Classic & movie) {
    movie.print(out);
    return out;
}