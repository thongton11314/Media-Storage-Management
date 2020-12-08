#include "media_movie_drama.h"

//----------------------------------------------------------------------------
// default constructor
Drama::Drama() {
    this->movieType = MovieType::DramaType;
    this->stock = DEFAULT_STOCK;
    this->title = DEFAULT_TITLE;
    this->director = DEFAULT_PERSON;
    this->year = DEFAULT_NUM;
}

//----------------------------------------------------------------------------
// copy constructor
Drama::Drama(const Drama & other) {
    this->movieType = other.movieType;
    this->stock = other.stock;
    this->title = other.title;
    this->director = other.director;
    this->year = other.year;
}

//----------------------------------------------------------------------------
// destructor
Drama::~Drama() {}

//----------------------------------------------------------------------------
// setData
// read and store the movie in the system from the file
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

//----------------------------------------------------------------------------
// getMovieType
// return the movie type
MovieType Drama::getMovieType() const {
    return this->movieType;
}

//----------------------------------------------------------------------------
// operator<
// movie comparison operator
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

//----------------------------------------------------------------------------
// operator<=
// movie comparison operator
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

//----------------------------------------------------------------------------
// operator>
// movie comparison operator
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

//----------------------------------------------------------------------------
// operator>=
// movie comparison operator
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

//----------------------------------------------------------------------------
// operator==
// movie comparison operator
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

//----------------------------------------------------------------------------
// operator=
// movie comparison operator
Media & Drama::operator=(const Media& other) {
    this->movieType = dynamic_cast<const Drama&>(other).getMovieType();
    this->stock = dynamic_cast<const Drama&>(other).getStock();
    this->director = dynamic_cast<const Drama&>(other).getDirector();
    this->title = dynamic_cast<const Drama&>(other).getTitle();
    this->year = dynamic_cast<const Drama&>(other).getYear();
    return *this;
}

//----------------------------------------------------------------------------
// operator!=
// movie comparison operator
bool Drama::operator!=(const Media & other) const {
    return !(*this == dynamic_cast<const Drama&>(other));
}

//----------------------------------------------------------------------------
// print
// print out the movie information
void Drama::print(ostream & stream) const {
    cout << (char)this->getMovieType() << ", "
    << this->getStock() << ", "
    << this->getDirector() << ", "
    << this->getTitle() << ", "
    << this->getYear();
}

//----------------------------------------------------------------------------
// operator<<
// print out to the system operator
ostream & operator<<(ostream & out, const Drama & movie) {
    movie.print(out);
    return out;
}