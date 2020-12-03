#include "customer.h"
#include "command.h"

//----------------------------------------------------------------------------
// Customer
// Default Constructor
Customer::Customer() {
    firstName = DEFAULT_NAME; 
    lastName = DEFAULT_NAME;  
    id = DEFAULT_ID;          
}

//----------------------------------------------------------------------------
// Customer
// Constructor instantiating customer id
Customer::Customer(int id) {
    this->id = id;  //set new id
}

//----------------------------------------------------------------------------
// Customer
// Constructor instantiating customer id, last name and first name
Customer::Customer(int id, string lastName, string firstName) {
    this->id = id;               
    this->firstName = lastName;  
    this->lastName = firstName;  
}

//----------------------------------------------------------------------------
// Customer
// Copy constructor
Customer::Customer(const Customer & other) {
    firstName = other.firstName; 
    lastName = other.lastName;   
    id = other.id;               
}

//----------------------------------------------------------------------------
// Customer
// Destructor
Customer::~Customer() {

    // clear borrowing
    for (int i = borrowing.size(); i > 0; i--) {
        if (borrowing.back()) {
            delete borrowing.back();
        }
        borrowing.pop_back();
    }

    // clear history
    for (int i = history.size(); i > 0; i--) {
        if (history.back()) {
            delete history.back();
        }
        history.pop_back();
    }
}

//----------------------------------------------------------------------------
// setID
// Modify the customer ID
void Customer::setID(int id) {
    this->id = id;
}

//----------------------------------------------------------------------------
// setFirstName
// Modify the customer first name
void Customer::setFirstName(string first) {
    this->firstName = first;
}

//----------------------------------------------------------------------------
// setLastName
// Modify the customer last name
void Customer::setLastName(string last) {
    this->lastName = last;
}

//----------------------------------------------------------------------------
// setData
// Read and get the customer information from the file
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

//----------------------------------------------------------------------------
// getID
// get and return the ID
int Customer::getId() const {
    return id;
}

//----------------------------------------------------------------------------
// getLastName
// get and return the last name 
string Customer::getLastName() const {
    return lastName;
}

//----------------------------------------------------------------------------
// getFirstName
// get and return the first name
string Customer::getFirstName() const {
    return firstName;
}

//----------------------------------------------------------------------------
// getHistories
// return the history of the customer
const vector<Command*> Customer::getHistories() const {
    return history;
}

//----------------------------------------------------------------------------
// borrowMedia
// Store the customer request
void Customer::borrowMedia(Media * media) {
    borrowing.push_back(media);
}

//----------------------------------------------------------------------------
// returnMedia
// return the media from the customer back to the system
bool Customer::returnMedia(Media * target) {

    bool isReturn = false;    
    for (int i = 0; i < borrowing.size() && isReturn == false; i++) {
        if (*borrowing.at(i) == *target) {
            Media* temp = borrowing.at(i);
            borrowing.at(i) = borrowing.at(borrowing.size() - 1);
            borrowing.at(borrowing.size() - 1) = temp;
            if (borrowing.back()) {
                delete borrowing.back();
            }
            borrowing.pop_back();
            isReturn = true;
        }
    }
    return isReturn;
}

//----------------------------------------------------------------------------
// addHistory
// add the customer request into their history
void Customer::addHistory(Command * command) {
    history.push_back(command);
}

//----------------------------------------------------------------------------
// operator<
// compare customers ID
bool Customer::operator<(const Customer & other) const {
    return id < other.id;
}

//----------------------------------------------------------------------------
// operator<=
// compare customers ID
bool Customer::operator<=(const Customer & other) const {
    return id <= other.id;
}

//----------------------------------------------------------------------------
// operator>
// compare customers ID
bool Customer::operator>(const Customer& other) const {
    return id > other.id;
}

//----------------------------------------------------------------------------
// operator>=
// compare customers ID
bool Customer::operator>=(const Customer & other) const {
    return id >= other.id;
}

//----------------------------------------------------------------------------
// operator==
// compare customers ID
bool Customer::operator==(const Customer & other) const {
    return id == other.id;
}

//----------------------------------------------------------------------------
// operator!=
// compare customers ID
bool Customer::operator!=(const Customer & other) const {
    return id != other.id;
}

//----------------------------------------------------------------------------
// operator<<
// print out the customer ID, last name and first name in order
ostream& operator<<(ostream & out, const Customer& customer) {
    out << customer.id << " " << customer.lastName << " " << customer.firstName;
    return out;
}
