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

void History::setCustomerID(int id) {
	this->customerID = id;
}

int History::getCustomerID() const {
	return this->customerID;
}

void History::processHistory(CustomerCollection&) {
}

ostream& History::out(ostream& out) const {
	out << this->type << " " << this->getCustomerID();
	return out;
}

ostream& operator<<(ostream& out, const History& command) {
	out << command.type << " " << command.getCustomerID();
	return out;
}
