#include "command.h"

//-----------------------------------------------------------------------------
// constructor
Command::Command() {
	this->commandType = DefaultCommandType;
	this->customerID = DEFAULT_ID;
	this->fullCommand = DefaultCommandType;
}

//-----------------------------------------------------------------------------
// copy constructor 
Command::Command(const Command& other) {
	this->commandType = other.commandType;
	this->customerID = other.customerID;
	this->fullCommand = other.fullCommand;
}

//-----------------------------------------------------------------------------
// destructor 
Command::~Command() {
}

//-----------------------------------------------------------------------------
// setCustomerID
// set user ID
void Command::setCustomerID(int ID) {
	this->customerID = ID;
}

//-----------------------------------------------------------------------------
// setCommandType
// set command type
void Command::setCommandType(CommandType input) {
	this->commandType = input;
}

//-----------------------------------------------------------------------------
// getCustomerID
// get user ID
int Command::getCustomerID() const {
	return this->customerID;
}

//-----------------------------------------------------------------------------
// getCommandType
// get command type
CommandType Command::getCommandType() const {
	return this->commandType;
}

//-----------------------------------------------------------------------------
// process
// process commands
void Command::process(MediaCollection & meColl, CustomerCollection & cusColl) {
	
	// use to check process or not
	bool flag = false;

	// select type of command
	switch (this->commandType) {
	
	// borrow media
	case BorrowType:
		flag = dynamic_cast<Borrow*>(this)->processBorrow(meColl, cusColl);
		break;

	// return media
	case ReturnType:
		flag = dynamic_cast<Return*>(this)->processReturn(meColl, cusColl);
		break;

	// display history
	case HistoryType:
		flag = dynamic_cast<History*>(this)->processHistory(cusColl);
		break;
	
	// check inventory
	case InventoryType:
		dynamic_cast<Inventory*>(this)->processInventory(meColl);
		break;

	// default case
	default:
		cerr << "Command, nothing to process" << endl;
		flag = false;
		break;
	}

	// delete this object
	if (!flag 
		|| this->commandType == HistoryType
		|| this->commandType == InventoryType) {
		delete this;
	}
}

//-----------------------------------------------------------------------------
// out
// use to set ostream data
ostream& Command::out(ostream& out) const {
	out << (char)this->commandType;
	return out;
}

//-----------------------------------------------------------------------------
// operator<<
// print out the command data
ostream& operator<<(ostream& output, const Command& command) {
	command.out(output);
	return output;
}