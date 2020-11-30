#include "media_movie_drama.h"

Drama::Drama() {
    this->type = DRAMA;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

Drama::Drama(const Drama & other) {
    this->type = other.type;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

Drama::~Drama() {}

bool Drama::setData(ifstream & infile) {

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

MovieType Drama::getMovieType() const {
    return this->type;
}

string Drama::getHashKey() const {
    return this->director + " " + this->title;
}

bool Drama::operator<(const Media & other) const {    

    // compare director first
    if (this->getDirector().compare(
        dynamic_cast<const Drama&>(other).getDirector()
    ) != 0)
		return this->getDirector().compare(
            dynamic_cast<const Drama&>(other).getDirector()
        ) < 0;
	
    // then compare title
	if (this->getTitle().compare(
        dynamic_cast<const Drama&>(other).getTitle()
    ) != 0)
		return this->getTitle().compare(
            dynamic_cast<const Drama&>(other).getTitle()
        ) < 0;

    // return false when greater
    return false;
}

bool Drama::operator<=(const Media & other) const {

    // compare director first
    if (this->getDirector().compare(
        dynamic_cast<const Drama&>(other).getDirector()
    ) > 0)
        return false;

    // then compare title
	if (this->getTitle().compare(
        dynamic_cast<const Drama&>(other).getTitle()
    ) > 0)
        return false;

    // return true when less than or equal
    return true;
}

bool Drama::operator>(const Media & other) const {

    // compare director first
    if (this->getDirector().compare(
        dynamic_cast<const Drama&>(other).getDirector()
    ) != 0)
		return this->getDirector().compare(
            dynamic_cast<const Drama&>(other).getDirector()
        ) > 0;
	
    // then compare title
	if (this->getTitle().compare(
        dynamic_cast<const Drama&>(other).getTitle()
    ) != 0)
		return this->getTitle().compare(
            dynamic_cast<const Drama&>(other).getTitle()
        ) > 0;

    // return false when greater
    return false;
}

bool Drama::operator>=(const Media & other) const {

    // compare director first
    if (this->getDirector().compare(
        dynamic_cast<const Drama&>(other).getDirector()
    ) < 0)
        return false;

    // then compare title
	if (this->getTitle().compare(
        dynamic_cast<const Drama&>(other).getTitle()
    ) < 0)
        return false;

    // return true when less than or equal
    return true;
}

bool Drama::operator==(const Media & other) const {
    if ((this->getDirector().compare(dynamic_cast<const Drama&>(other).getDirector()
    ) == 0)
        && (this->getTitle().compare(
            dynamic_cast<const Drama&>(other).getTitle()
        ) == 0)
        && (this->getYear() == dynamic_cast<const Drama&>(other).getYear()))
        return true;
    return false;
}

Media & Drama::operator=(const Media& other) {
    this->type = dynamic_cast<const Drama&>(other).getMovieType();
    this->stock = dynamic_cast<const Drama&>(other).getStock();
    this->director = dynamic_cast<const Drama&>(other).getDirector();
    this->title = dynamic_cast<const Drama&>(other).getTitle();
    this->year = dynamic_cast<const Drama&>(other).getYear();
    return *this;
}

bool Drama::operator!=(const Media & other) const {
    return !(*this == dynamic_cast<const Drama&>(other));
}

void Drama::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->getStock() << ", "
    << this->getDirector() << ", "
    << this->getTitle() << ", "
    << this->getYear();
}

ostream & operator<<(ostream & out, const Drama & movie) {
    movie.print(out);
    return out;
}