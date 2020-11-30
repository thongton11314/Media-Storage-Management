#include "media_movie_comedy.h"

Comedy::Comedy() {
    this->type = COMEDY;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

Comedy::Comedy(const Comedy & other) {
    this->type = other.type;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

Comedy::~Comedy() {}

bool Comedy::setData(ifstream& infile) {

    // set up stock
    infile.ignore();
    infile >> this->stock;

    // set up director
    infile.ignore();
    getline(infile >> ws, this->director, ',');

    // set up title
    infile.ignore();
    getline(infile >> ws, this->title, ',');

    // set up year
    infile.ignore();
    string strToYear;
    getline(infile >> ws, strToYear, '\n'); // end of line
    stringstream ss;
    ss << strToYear;
    ss >> this->year;

    return true;
}

MovieType Comedy::getMovieType() const {
    return this->type;
}

string Comedy::getHashKey() const {
    return this->getTitle() + " " + to_string(this->getYear());
}

bool Comedy::operator<(const Media & other) const {

    // compare title first
    if (this->getTitle().compare(
        dynamic_cast<const Comedy&>(other).getTitle()
    ) != 0)
        return this->getTitle().compare(
            dynamic_cast<const Comedy&>(other).getTitle()
        ) < 0;

    // compare year
    return this->getYear() < dynamic_cast<const Comedy&>(other).getYear();
}

bool Comedy::operator<=(const Media & other) const {

    // compare title first
    if (this->getTitle().compare(
        dynamic_cast<const Comedy&>(other).getTitle()
    ) > 0)
        return false;

    // compare year
    return this->getYear() <= dynamic_cast<const Comedy&>(other).getYear();
}

bool Comedy::operator>(const Media & other) const {

    // compare title first
    if (this->getTitle().compare(
        dynamic_cast<const Comedy&>(other).getTitle()
    ) != 0)
        return this->getTitle().compare(
            dynamic_cast<const Comedy&>(other).getTitle()
        ) > 0;

    // compare year
    return this->getYear() > dynamic_cast<const Comedy&>(other).getYear();
}

bool Comedy::operator>=(const Media & other) const {

    // compare title first
    if (this->getTitle().compare(
        dynamic_cast<const Comedy&>(other).getTitle()
    ) < 0)
        return false;

    // compare year
    return this->getYear() >= dynamic_cast<const Comedy&>(other).getYear();
}

bool Comedy::operator==(const Media & other) const {
    return (this->getTitle().compare(
        dynamic_cast<const Comedy&>(other).getTitle()) == 0)
        && (this->getYear() == dynamic_cast<const Comedy&>(other).getYear());
}

bool Comedy::operator!=(const Media & other) const {
    return !(*this == dynamic_cast<const Comedy&>(other));
}

Media & Comedy::operator=(const Media& other) {
    this->type = dynamic_cast<const Comedy&>(other).getMovieType();
    this->stock = dynamic_cast<const Comedy&>(other).getStock();
    this->director = dynamic_cast<const Comedy&>(other).getDirector();
    this->title = dynamic_cast<const Comedy&>(other).getTitle();
    this->year = dynamic_cast<const Comedy&>(other).getYear();
    return *this;
}

void Comedy::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->getStock() << ", "
    << this->getDirector() << ", "
    <<  this->getTitle() << ", "
    << this->getYear();
}

ostream & operator<<(ostream & out, const Comedy & movie) {
    movie.print(out);
    return out;
}