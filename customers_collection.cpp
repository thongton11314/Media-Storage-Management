#include "customers_collection.h"

//----------------------------------------------------------------------------
// CustomerCollection
// Default constructor
CustomerCollection::CustomerCollection() {}

//----------------------------------------------------------------------------
// CustomerCollection
// Destructor
CustomerCollection::~CustomerCollection() {}

//----------------------------------------------------------------------------
// insertCustomer
// Insert and register the customer to the system
bool CustomerCollection::insertCustomer(Customer * customer) {
    return collection.insertKeyValue(customer->getId(), customer);
}

//----------------------------------------------------------------------------
// retrieveCustomer
// Look and retrieve for the customer in the system
bool CustomerCollection::retrieveCustomer(const int & id, 
                                        Customer *& retriever) const {
    return collection.retrieveValue(id, retriever);
}

//----------------------------------------------------------------------------
// removeCustomerByID
// Remove the customer from the system by their ID
bool CustomerCollection::removeCustomerByID(const int & id) {
    return collection.removeValue(id);
}

//----------------------------------------------------------------------------
// getACustomer
// Find the customer using their ID
const Customer* CustomerCollection::getACustomer(const int & id) const {
    return collection.getValue(id);
}

//----------------------------------------------------------------------------
// display
// Display a list of customers in to the system
void CustomerCollection::display() const {
    collection.display();
}
