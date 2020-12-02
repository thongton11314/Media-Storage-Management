#include "command_history.h"

History::History() {
	this->type = HISTORY;
	this->customerID = DEFAULT_ID;
}

History::~History() {
}

bool History::setData(ifstream& infile) {
	infile.ignore();
	infile >> this->customerID;
	if (infile.fail()) {
		cout << "Customer ID is invalid" << endl;
		infile.clear();
		infile.ignore(99, '\n');
		return false;
	}
	return true;
}

bool History::processHistory(CustomerCollection& cusColl) {
	Customer* cusRetriver = nullptr;

	// found customer
	if (cusColl.retrieveCustomer(this->getCustomerID(), cusRetriver)) {

		// label
		cout << "History of " << this->getCustomerID()
			<< " " << cusRetriver->getFirstName() 
			<< " " << cusRetriver->getLastName() << ':' << endl;

		// empty
		if (cusRetriver->getHistories().empty()) {
			cout << "  " << "Empty!" << endl;
		}

		// has history
		else {
			for (int i = 0; i < cusRetriver->getHistories().size(); i++) {
				cout << "  " << *cusRetriver->getHistories().at(i) << endl;
			}
			return true;
		}
	}

	// customer not found
	else {
		cerr << "Command, customer not found to show history:"
			<< '\n' << "  " << this->fullCommand << endl;
	}
	return false;
}

ostream& History::out(ostream& out) const {
	out << this->type << " " << this->getCustomerID();
	return out;
}

ostream& operator<<(ostream& out, const History& command) {
	out << command.type << " " << command.getCustomerID();
	return out;
}
