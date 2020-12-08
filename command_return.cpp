#include "command_return.h"

//-----------------------------------------------------------------------------
// constructor
Return::Return() {
}

//-----------------------------------------------------------------------------
// destructor
Return::~Return() {
}

//-----------------------------------------------------------------------------
// processReturn
bool Return::processReturn(MediaCollection & meColl, 
	CustomerCollection & cusColl) {
	
	Customer* cusRetriever;

	// check customer exist
	if (cusColl.retrieveCustomer(this->getCustomerID(), cusRetriever)) {

		// check command contain media
		if (this->media != nullptr) {

			// check media exist
			Media* meRetriever = nullptr;
			if (meColl.retrieve(*this->media, meRetriever)) {

				// customer return media
				if (cusRetriever->returnMedia(this->media)) {
					
					// erase command media
					delete this->media;
					this->media = nullptr;

					// add more media strock
					meRetriever->addStock(1);

					// add customer history
					cusRetriever->addHistory(this);
					return true;
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

	// fail return
	return false;
}

//-----------------------------------------------------------------------------
// out
// use for set ostream data
ostream& Return::out(ostream& out) const {
	out << this->fullCommand;
	return out;
}

//-----------------------------------------------------------------------------
// operator<<
// use to print out command return data
ostream& operator<<(ostream& out, const Return& r) {
	r.out(out);
	return out;
}