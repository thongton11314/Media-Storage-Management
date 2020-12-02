#include "command.h"

Command::Command() {
	this->type = DEFAULT_TYPE;
	this->customerID = DEFAULT_ID;
	this->fullCommand = DEFAULT_TYPE;
}

Command::Command(const Command& other) {
	this->type = other.type;
	this->customerID = other.customerID;
	this->fullCommand = other.fullCommand;
}

Command::~Command() {
}

void Command::setCustomerID(int ID) {
	this->customerID = ID;
}

void Command::setCommandType(char input) {
	this->type = input;
}

int Command::getCustomerID() const {
	return this->customerID;
}

CommandType Command::getCommandType() const {
	return this->type;
}

// better use binding
bool Command::process(MediaCollection & meColl, CustomerCollection & cusColl) {
	
	bool isProcess = false;

	// select type of command
	switch (this->type) {
	
	// borrow media
	case BORROW:
		isProcess = dynamic_cast<Borrow*>(this)->processBorrow(meColl, cusColl);
		break;

	// return media
	case RETURN:
		isProcess = dynamic_cast<Return*>(this)->processReturn(meColl, cusColl);
		break;

	// display or history
	case HISTORY:
		isProcess = dynamic_cast<History*>(this)->processHistory(cusColl);
		break;
	
	// check inventory
	case INVENTORY:
		dynamic_cast<Inventory*>(this)->processInventory(meColl);
		isProcess = true;
		break;

	// default case
	default:
		cerr << "Command, nothing to process" << endl;
		isProcess = false;
		break;
	}
	return isProcess;
}

ostream& Command::out(ostream& out) const {
	out << this->type;
	return out;
}

ostream& operator<<(ostream& output, const Command& command) {
	command.out(output);
	return output;
}
