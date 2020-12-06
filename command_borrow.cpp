#include "command_borrow.h"

//-----------------------------------------------------------------------------
// constructor
Borrow::Borrow() {
	this->type = BORROW;
	this->customerID = DEFAULT_ID;
	this->mediaType = DEFAULT_TYPE;
	this->movieType = DEFAULT_TYPE;
	this->media = nullptr;
}

//-----------------------------------------------------------------------------
// destructor
Borrow::~Borrow() {
	if (this->media != nullptr) {
		delete this->media;
		this->media = nullptr;
	}
}

//-----------------------------------------------------------------------------
// setData
// sets the data from the file including customer ID and media type
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
		cout << "Command, customer ID is invalid:" 
			<< '\n' << "  " << fullCommand + temp << endl;
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
			infile.ignore();
			getline(infile, temp, '\n');
			this->fullCommand += temp;
			cerr << "Command, invalid movie type '" << this->movieType << "':"
				<< '\n' << "  " << this->fullCommand << endl;
			break;
		}
		break;

	// invalid media type
	default:
		infile.ignore();
		getline(infile, temp, '\n');
		fullCommand += ' ';
		fullCommand += this->mediaType;
		fullCommand += ' ';
		fullCommand += temp;
		cerr << "Command, invalid media type '" << this->mediaType << "': "
			<< '\n' << "  " << fullCommand << endl;
		break;
	}
	infile.clear();
	this->media = aMedia;
	bool isValid = this->media != nullptr ? isValid = true : isValid = false;
	return isValid;
}

//-----------------------------------------------------------------------------
// processBorrow
// checks the inventory and processes the borrow command 
bool Borrow::processBorrow(MediaCollection & meColl, 
			   CustomerCollection & cusColl) {

	Customer* cusRetriever;

	// check customer exist
	if (cusColl.retrieveCustomer(this->getCustomerID(), cusRetriever)) {

		// check command contain media
		if (this->media != nullptr) {

			// check media exist
			Media* meRetriever = nullptr;			
			if (meColl.retrieve(*this->media, meRetriever)) {

				// reduce media strock
				if (meRetriever->reduceStock(1)) {

					// customer borrow media
					cusRetriever->borrowMedia(this->media);
					this->media = nullptr;

					// add customer history
					cusRetriever->addHistory(this);
					return true;
				}

				// out of stock
				else {
					cerr << "Command, media is out of stock:"
						<< '\n' << "  " << this->fullCommand << endl;
				}
			}

			// media is not exist
			else {
				cerr << "Command, media is not in media collection:"
					<< '\n' << "  " << this->fullCommand << endl;
			}
		}

		// command doesn't contain media
		else {
			cerr << "Command, this command doesn't contain media:"
				<< '\n' << "  " << this->fullCommand << endl;
		}
	}

	// customer is not exist
	else {
		cerr << "Command, customer does not exist:"
			<< '\n' << "  " << this->fullCommand << endl;
	}

	// fail borrow
	return false;
}

//----------------------------------------------------------------------------
// out
// use to set out stream data
ostream& Borrow::out(ostream& out) const {
	out << this->fullCommand;
	return out;
}

//----------------------------------------------------------------------------
// operator<<
// print out command borrow data
ostream& operator<<(ostream& out, const Borrow& b) {
	b.out(out);
	return out;
}