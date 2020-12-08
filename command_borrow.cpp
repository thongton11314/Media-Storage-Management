#include "command_borrow.h"

//-----------------------------------------------------------------------------
// constructor
Borrow::Borrow() {
}

//-----------------------------------------------------------------------------
// destructor
Borrow::~Borrow() {
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