#include "command.h"

//-----------------------------------------------------------------------------
// constructor
Command::Command() {
	this->type = DEFAULT_TYPE;
	this->customerID = DEFAULT_ID;
	this->fullCommand = DEFAULT_TYPE;
}
//-----------------------------------------------------------------------------
// copy constructor 
Command::Command(const Command& other) {
	this->type = other.type;
	this->customerID = other.customerID;
	this->fullCommand = other.fullCommand;
}
//-----------------------------------------------------------------------------
// destructor 
Command::~Command() {
}
//-----------------------------------------------------------------------------
// set user ID
void Command::setCustomerID(int ID) {
	this->customerID = ID;
}
//-----------------------------------------------------------------------------
// set command type
void Command::setCommandType(char input) {
	this->type = input;
}
//-----------------------------------------------------------------------------
// get user ID
int Command::getCustomerID() const {
	return this->customerID;
}
//-----------------------------------------------------------------------------
// get command type
CommandType Command::getCommandType() const {
	return this->type;
}
//-----------------------------------------------------------------------------
// better use binding
bool Command::process(MediaCollection & meColl, CustomerCollection & cusColl) {
	
	// use to check process or not
	bool flag = false;

	// select type of command
	switch (this->type) {
	
	// borrow media
	case BORROW:
		flag = dynamic_cast<Borrow*>(this)->processBorrow(meColl, cusColl);
		break;

	// return media
	case RETURN:
		flag = dynamic_cast<Return*>(this)->processReturn(meColl, cusColl);
		break;

	// display or history
	case HISTORY:
		flag = dynamic_cast<History*>(this)->processHistory(cusColl);
		break;
	
	// check inventory
	case INVENTORY:
		dynamic_cast<Inventory*>(this)->processInventory(meColl);
		flag = true;
		break;

	// default case
	default:
		cerr << "Command, nothing to process" << endl;
		flag = false;
		break;
	}
	return flag;
}
//-----------------------------------------------------------------------------
// out
// use to set ostream data
ostream& Command::out(ostream& out) const {
	out << this->type;
	return out;
}
//-----------------------------------------------------------------------------
// operator<<
// print out the command data
ostream& operator<<(ostream& output, const Command& command) {
	command.out(output);
	return output;
}
