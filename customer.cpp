#include "customer.h"

Customer::Customer() {
    firstName = DEFAULT_NAME;
    lastName = DEFAULT_NAME;
    id = DEFAULT_ID;
}

Customer::Customer(int id) {
    this->id = id;
}

Customer::Customer(int id, string lastName, string firstName) {
    this->id = id;
    this->firstName = lastName;
    this->lastName = firstName;
}

Customer::Customer(const Customer & other) {
    firstName = other.firstName;
    lastName = other.lastName;
    id = other.id;
}

Customer::~Customer() {
}

void Customer::setID(int id) {
    this->id = id;
}

void Customer::setFirstName(string first) {
    this->firstName = first;
}

void Customer::setLastName(string last) {
    this->lastName = last;
}

bool Customer::setData(ifstream & infile) {

    bool valid = true;

    infile >> id;
    if (infile.fail() || id < MINID || id > MAXID) {

        infile.clear();
        char temp;
        while (infile.get(temp) && temp != '\n');
        return false;
    }

    infile >> lastName >> firstName;

    // read until end of statement in file
    if (!valid) {
        infile.clear();
        char temp;
        while (infile.get(temp) && temp != '\n');
        return false;
    }
    return valid;
}
        
int Customer::getId() const {
    return id;
}

string Customer::getLastName() const {
    return lastName;
}

string Customer::getFirstName() const {
    return firstName;
}

const vector<Command*> Customer::getHistories() const {
    return history;
}

void Customer::borrowMedia(Media * media) {
    borrowing.push_back(media);
}

// need to work on media comparision before this
bool Customer::returnMedia(Media * target) {

    /*
    bool isIn = false;
    vector<Media*>::iterator i = borrowing.begin();
    int count = 0;
	while (i != borrowing.end()) {
        if (*(borrowing.at(count)) == *target) {
            borrowing.erase(i);
            isIn = true;
        }
        count++;
        i++;
    }
	return isIn;
    */
    return false;
}

void Customer::addHistory(Command * command) {
    history.push_back(command);
}

bool Customer::operator<(const Customer & other) const {
    return id < other.id;
}

bool Customer::operator<=(const Customer & other) const {
    return id <= other.id;
}

bool Customer::operator>(const Customer& other) const {
    return id > other.id;
}

bool Customer::operator>=(const Customer & other) const {
    return id >= other.id;
}

bool Customer::operator==(const Customer & other) const {
    return id == other.id;
}

bool Customer::operator!=(const Customer & other) const {
    return id != other.id;
}

ostream& operator<<(ostream & out, const Customer& customer) {
    out << customer.id << " " << customer.lastName << " " << customer.firstName;
    return out;
}