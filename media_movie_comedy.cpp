#include "media_movie_comedy.h"

Comedy::Comedy() {
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

bool Comedy::setData(ifstream & infile) {

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

Comedy::Comedy(const Comedy & other) {
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

Comedy::~Comedy() {}

char Comedy::getMovieType() const {
    return 'F';
}

bool Comedy::operator<(const Media & other) const {
    const Media * ptrMedia = &other;
    const Comedy * ptrComedy = dynamic_cast<const Comedy*>(ptrMedia);

    // compare title first
    if (this->getTitle().compare(ptrComedy->getTitle()) != 0)
		return this->getTitle().compare(ptrComedy->getTitle()) < 0;  
	
    // then compare year
	return this->getYear() < ptrComedy->getYear();
}

bool Comedy::operator<=(const Media & other) const {
    const Media * ptrMedia = &other;
    const Comedy * ptrComedy = dynamic_cast<const Comedy*>(ptrMedia);

    // compare title first
    if (this->getTitle().compare(ptrComedy->getTitle()) > 0)
		return false; 
	
    // then compare year
	return this->getYear() <= ptrComedy->getYear();
}

bool Comedy::operator>(const Media & other) const {
    const Media * ptr = &other;
    return !(*this < *(dynamic_cast<const Comedy*>(ptr)));
}

bool Comedy::operator>=(const Media & other) const {
    const Media * ptrMedia = &other;
    const Comedy * ptrComedy = dynamic_cast<const Comedy*>(ptrMedia);

    // compare title first
    if (this->getTitle().compare(ptrComedy->getTitle()) < 0)
		return false; 
	
    // then compare year
	return this->getYear() <= ptrComedy->getYear();
}

bool Comedy::operator==(const Media & other) const {
    const Media * ptrMedia = &other;
    const Comedy * ptrComedy = dynamic_cast<const Comedy*>(ptrMedia);
    if ((this->getTitle().compare(ptrComedy->getTitle()) == 0)
        && (this->getYear() == ptrComedy->getYear()))
        return true;
    return false;
}

bool Comedy::Comedy::operator!=(const Media & other) const {
    const Media * ptr = &other;
    return !(*this == *(dynamic_cast<const Comedy*>(ptr)));
}

void Comedy::print(ostream & stream) const {
    cout << this->getMovieType() << ", "
    << this->stock << ", "
    << this->director << ", "
    <<  this->title << ", "
    << this->year << ". ";
}

ostream & operator<<(ostream & out, const Comedy & movie) {
    movie.print(out);
    return out;
}