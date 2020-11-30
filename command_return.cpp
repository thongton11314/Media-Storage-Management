#include "command_return.h"

Return::Return() {
	this->type = BORROW;
	this->customerID = DEFAULT_ID;
	this->mediaType = DEFAULT_TYPE;
	this->movieType = DEFAULT_TYPE;
	this->media = nullptr;
}

Return::~Return() {
}

bool Return::setData(ifstream& infile) {

	// set customer ID
	infile.ignore();
	infile >> this->customerID;

	// if customer id not number
	if (infile.fail()) {
		cout << "Customer ID is invalid" << endl;
		infile.clear();
		infile.ignore(99, '\n');
		return false;
	}

	// if customer id is negative number
	if (customerID < 0) {
		cout << "Customer ID can not be negative" << endl;
		return false;
	}

	// valid continuous reading file
	// create media, and some temporary data
	Media* aMedia = nullptr;
	string tempTitle;
	string tempDirector;
	string tempActor;
	int tempMonth;
	int tempYear;

	// set media
	infile >> mediaType;
	switch (mediaType) {
	case MOVIE:
		infile >> movieType;
		switch (movieType) {

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
			infile >> tempActor;
			dynamic_cast<Classic*>(aMedia)->setMajorActorFirst(tempActor);

			// set actor last name
			infile.ignore();
			infile >> tempActor;
			dynamic_cast<Classic*>(aMedia)->setMajorActorLast(tempActor);
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
			break;
		default:
			cerr << "Invalid movie type " << movieType << endl;
			break;
		}
	default:
		cerr << "Invalid media type " << mediaType << endl;
		break;
	}
	this->media = aMedia;
	bool isValid = this->media != nullptr ? isValid = true : isValid = false;
	return isValid;
}

bool Return::setCustomerID(int id) {
    return false;
}

int Return::getCustomerID() {
    return 0;
}

bool Return::procesReturn(Media*, Customer*) {
    return false;
}

ostream& Return::out(ostream& out) const {
	out << this->type
		<< " " << this->mediaType
		<< " " << this->customerID
		<< " ";
	if (this->media != nullptr) {
		out << *this->media;
	}
	return out;
}

ostream& operator<<(ostream& out, const Return& command) {
    return out;
}
