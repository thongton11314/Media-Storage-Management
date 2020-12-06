#include "customers_collection.h"

//-----------------------------------------------------------------------------
// default constructor
CustomerCollection::CustomerCollection() {}

//-----------------------------------------------------------------------------
// destructor
CustomerCollection::~CustomerCollection() {}

//-----------------------------------------------------------------------------
// insertCustomer
// insert and register the customer to the system
bool CustomerCollection::insertCustomer(Customer * customer) {
    return collection.insertKeyValue(customer->getId(), customer);
}

//-----------------------------------------------------------------------------
// retrieveCustomer
// look and retrieve for the customer in the system
bool CustomerCollection::retrieveCustomer(const int & id, 
                                        Customer *& retriever) const {
    return collection.retrieveValue(id, retriever);
}

//-----------------------------------------------------------------------------
// removeCustomerByID
// remove the customer from the system by their ID
bool CustomerCollection::removeCustomerByID(const int & id) {
    return collection.removeValue(id);
}

//-----------------------------------------------------------------------------
// getACustomer
// find the customer using their ID
const Customer* CustomerCollection::getACustomer(const int & id) const {
    return collection.getValue(id);
}

//-----------------------------------------------------------------------------
// display
// display a list of customer to the system
void CustomerCollection::display() const {
    collection.display();
}