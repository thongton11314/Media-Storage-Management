#include "customers_collection.h"

CustomerCollection::CustomerCollection() {}

CustomerCollection::~CustomerCollection() {}

bool CustomerCollection::insertCustomer(Customer * customer) {
    return collection.insertKeyValue(customer->getId(), customer);
}

bool CustomerCollection::retrieveCustomer(const int & id, 
                                        Customer *& retriever) {
    return collection.retrieveValue(id, retriever);
}

bool CustomerCollection::removeCustomerByID(const int & id) {
    return collection.removeValue(id);
}

const Customer* CustomerCollection::getACustomer(int id) {
    return collection.getValue(id);
}