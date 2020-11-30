#include "command_borrow.h"

Borrow::Borrow() {
	this->type = BORROW;
	this->customerID = DEFAULT_ID;
	this->mediaType = DEFAULT_TYPE;
	this->movieType = DEFAULT_TYPE;
	this->media = nullptr;
}

Borrow::~Borrow() {
	delete media;
}

// three type/
// B 8000 D F You've Got Mail, 1998
// B 1000 D D Barry Levinson, Good Morning Vietnam,
// B 1000 D C 5 1940 Katherine Hepburn
// Read from customer number until the end
bool Borrow::setData(ifstream& infile) {

	// create media, and some temporary data
	Media* aMedia = nullptr;
	string tempTitle;
	string tempDirector;
	string tempActorFirst;
	string tempActorLast;
	int tempMonth;
	int tempYear;
	string temp;

	// assign comment;
	fullCommand = this->type;

	// set customer ID
	infile.ignore();
	infile >> this->customerID;
	fullCommand += ' ' + to_string(this->customerID);


	// if customer id not number or negative
	if (infile.fail() || customerID < 0) {
		getline(infile, temp, '\n');
		cout << "Customer ID is invalid: " << fullCommand + temp << endl;
		return false;
	}

	// set media
	infile.ignore();
	infile >> this->mediaType;
	switch(this->mediaType) {

	// media is movie
	case MOVIE:
		infile.ignore();
		infile >> this->movieType;

		// assign to command
		fullCommand += ' ';
		fullCommand += this->mediaType;
		fullCommand += ' ';
		fullCommand += this->movieType;

		switch (this->movieType) {

		// create comedy
		case COMEDY:			
			aMedia = new Comedy();

			// set title
			infile.ignore();
			getline(infile >> ws, tempTitle, ',');
			dynamic_cast<Comedy*>(aMedia)->setTitle(tempTitle);

			// set year
			infile.ignore();
			infile >> tempYear;
			dynamic_cast<Comedy*>(aMedia)->setYear(tempYear);

			// add to command
			fullCommand += ' ' + tempTitle + ", " + to_string(tempYear);
			break;

		// create classic
		case CLASSIC:
			aMedia = new Classic();

			// set month
			infile.ignore();
			infile >> tempMonth;
			dynamic_cast<Classic*>(aMedia)->setMonth(tempMonth);

			// set year
			infile.ignore();
			infile >> tempYear;
			dynamic_cast<Classic*>(aMedia)->setYear(tempYear);

			// set actor first name
			infile.ignore();
			infile >> tempActorFirst;
			dynamic_cast<Classic*>(aMedia)->setMajorActorFirst(tempActorFirst);

			// set actor last name
			infile.ignore();
			infile >> tempActorLast;
			dynamic_cast<Classic*>(aMedia)->setMajorActorLast(tempActorLast);

			// add to command
			fullCommand += ' ' + to_string(tempMonth) 
				+ ' ' + to_string(tempYear) 
				+ ' ' + tempActorFirst 
				+ ' ' + tempActorLast;
			break;
		
		// create drama
		case DRAMA:
			aMedia = new Drama();
			
			// set media director
			infile.ignore();
			getline(infile >> ws, tempDirector, ',');
			dynamic_cast<Drama*>(aMedia)->setDirector(tempDirector);

			// set media title
			infile.ignore();
			getline(infile >> ws, tempTitle, ',');
			dynamic_cast<Drama*>(aMedia)->setTitle(tempTitle);

			// add to command
			fullCommand += ' ' + tempDirector + ", " + tempTitle + ", ";
			break;

		// invalid movie type
		default:
			getline(infile, temp, '\n');
			this->fullCommand += temp;
			cerr << "Invalid movie type '" << this->movieType << "': "
				<< this->fullCommand << endl;
			break;
		}
		break;

	// invalid media type
	default:		
		getline(infile, temp, '\n');
		fullCommand += temp;
		cerr << "Invalid media type '" << this->mediaType << "': "
			<< fullCommand << endl;
		break;
	}
	infile.clear();
	this->media = aMedia;
	bool isValid = this->media != nullptr ? isValid = true : isValid = false;
	return isValid;
}

void Borrow::setMedia(Media* media) {
	this->media = media;
}

bool Borrow::setCustomerID(int id) {
	return this->customerID = id;
}

void Borrow::setMediaType(MediaType type) {
	this->mediaType = type;
}

void Borrow::setMovieType(MovieType type) {
	this->mediaType = type;
}

int Borrow::getCustomerID() const {
	return this->customerID;
}

MediaType Borrow::getMediaType() const {
	return this->mediaType;
}

MovieType Borrow::getMovieType() const {
	return movieType;
}

const Media & Borrow::getMedia() const {
	return *this->media;
}

bool Borrow::processBorrow(Media*, Customer*) {
	return false;
}

ostream& Borrow::out(ostream& out) const {
	out << this->fullCommand;
	return out;
}

ostream& operator<<(ostream& out, const Borrow& borrow) {
	borrow.out(out);
	return out;
}
