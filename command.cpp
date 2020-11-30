#include "command.h"

Command::Command() {
	this->type = DEFAULT_TYPE;
	this->fullCommand = DEFAULT_TYPE;
}

Command::Command(const Command& other) {
	this->type = other.type;
}

Command::~Command() {
}

void Command::setCommandType(char input) {
	this->type = input;
}

CommandType Command::getCommandType() const {
	return this->type;
}

void Command::process(MediaCollection& meColl, CustomerCollection& cusColl) {
}

ostream& Command::out(ostream& out) const {
	out << this->type;
	return out;
}

ostream& operator<<(ostream& output, const Command& command) {
	command.out(output);
	return output;
}
