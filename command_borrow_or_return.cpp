#include "command_borrow_or_return.h"

//-----------------------------------------------------------------------------
// constructor
BorrowOrReturn::BorrowOrReturn() {
	this->customerID = DEFAULT_ID;
	this->mediaType = DefaultMediaType;
	this->movieType = DefaultMovieType;
	this->media = nullptr;
}

//-----------------------------------------------------------------------------
// default constructor
BorrowOrReturn::~BorrowOrReturn() {
	if (this->media != nullptr) {
		delete this->media;
		this->media = nullptr;
	}
}

//-----------------------------------------------------------------------------
// setData
// sets the data from the file including customer ID and media type
bool BorrowOrReturn::setData(ifstream& infile) {

	// create media, and some temporary data
	Media* aMedia = nullptr;

	// use to read data from file
	char tempMedia;
	char tempMovie;
	string tempID;

	// assign comment type to command
	fullCommand = this->commandType;
	fullCommand += ' ';

	// assign customer ID to command
	infile.ignore();
	infile >> tempID;
	fullCommand += tempID;
	fullCommand += ' ';

	// use to convert string to number
	stringstream convert(tempID);
	convert >> this->customerID;

	// if customer id not number or negative
	if (convert.fail() || customerID < 0) {
		processInvalid(infile, tempID, string("customer ID"));
		return false;
	}

	// read media type
	infile.ignore();
	infile >> tempMedia;

	// assign media type to command
	fullCommand += tempMedia;
	fullCommand += ' ';

	// check type of media
	switch (tempMedia) {

	// media is movie
	case DVDMovieType:
		this->mediaType = DVDMovieType;

		// read file
		infile.ignore();
		infile >> tempMovie;

		// assign to movie type to command
		fullCommand += tempMovie;
		fullCommand += ' ';

		// check type of movie
		switch (tempMovie) {

			// create comedy
		case ComedyType:
			processComedy(infile, aMedia);
			break;

			// create classic
		case ClassicType:
			processClassic(infile, aMedia);
			break;

		// create drama
		case DramaType:
			processDrama(infile, aMedia);
			break;

		// invalid movie type
		default:
			processInvalid(infile,
				string().insert(0, 1, tempMovie),
				string("movie type"));
			break;
		}
		break;

	// invalid media type
	default:
		processInvalid(infile,
			string().insert(0, 1, tempMedia),
			string("media type"));
		break;
	}

	// clear the stream pipe
	infile.clear();

	// assign this media
	this->media = aMedia;
	bool isValid = this->media != nullptr ? isValid = true : isValid = false;
	return isValid;
}

//-----------------------------------------------------------------------------
// processComedy
// process create media type movie comedy
void BorrowOrReturn::processComedy(ifstream& infile, Media*& aMedia) {
	this->movieType = ComedyType;
	aMedia = new Comedy();
	string tempTitle;
	int tempYear;

	// set title
	infile.ignore();
	getline(infile >> ws, tempTitle, ',');
	dynamic_cast<Comedy*>(aMedia)->setTitle(tempTitle);

	// set year
	infile.ignore();
	infile >> tempYear;
	dynamic_cast<Comedy*>(aMedia)->setYear(tempYear);

	// add to command
	fullCommand += tempTitle + ", " + to_string(tempYear);
}

//-----------------------------------------------------------------------------
// processClassic
// process create media type movie classic
void BorrowOrReturn::processClassic(ifstream& infile, Media*& aMedia) {
	this->movieType = ClassicType;
	aMedia = new Classic();
	string tempActorFirst;
	string tempActorLast;
	int tempMonth;
	int tempYear;

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
	fullCommand += to_string(tempMonth)
		+ ' ' + to_string(tempYear)
		+ ' ' + tempActorFirst
		+ ' ' + tempActorLast;
}

//-----------------------------------------------------------------------------
// processDrama
// process create media type movie drama
void BorrowOrReturn::processDrama(ifstream& infile, Media*& aMedia) {
	this->movieType = DramaType;
	aMedia = new Drama();
	string tempTitle;
	string tempDirector;

	// set media director
	infile.ignore();
	getline(infile >> ws, tempDirector, ',');
	dynamic_cast<Drama*>(aMedia)->setDirector(tempDirector);

	// set media title
	infile.ignore();
	getline(infile >> ws, tempTitle, ',');
	dynamic_cast<Drama*>(aMedia)->setTitle(tempTitle);

	// add to command
	fullCommand += tempDirector + ", " + tempTitle + ", ";
}

//-----------------------------------------------------------------------------
// processInvalid
// in charge of invalid customer id, media type, movie type
void BorrowOrReturn::processInvalid(ifstream& infile,
	const string& invalid,
	const string& message) {
	string temp;
	infile.ignore();
	getline(infile, temp, '\n');
	this->fullCommand += temp;

	// print out error
	cerr << "Command, invalid " << message << " '" << invalid << "':"
		<< '\n' << "  " << this->fullCommand << endl;
}

//-----------------------------------------------------------------------------
// out
// use to set ostream data
ostream& BorrowOrReturn::out(ostream& out) const {
	out << (char)this->commandType;
	return out;
}

//-----------------------------------------------------------------------------
// operator<<
// print out the command data
ostream& operator<<(ostream& output, const BorrowOrReturn& command) {
	command.out(output);
	return output;
}