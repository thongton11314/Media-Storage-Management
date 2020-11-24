#include "customers_collection.h"

CustomerCollection::CustomerCollection() {}

CustomerCollection::~CustomerCollection() {}

bool CustomerCollection::insertCustomer(Customer * customer) {
    return false; 
}

bool CustomerCollection::retrieveCustomer(const int & id, 
                                        Customer *& retriever) const {
    return false; 
}

bool CustomerCollection::removeCustomerByID(const int & id) {
    return false; 
}

const Customer * getACustomer(const int & id) {
    return nullptr;
}