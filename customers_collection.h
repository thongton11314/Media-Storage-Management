// add comments here
#ifndef _CUSTOMER_COLLECTION_
#define _CUSTOMER_COLLECTION_
#include "customer.h"
#include "hashtable.h"

// add commments here
class CustomerCollection {
public:
    CustomerCollection();
    ~CustomerCollection();
    bool insertCustomer(Customer * customer);
    bool retrieveCustomer(const int & id, Customer *& retriever) const;
    bool removeCustomerByID(const int & id);
    const Customer * getACustomer(const int & id) const;
    void display() const;
private:
    Hashtable<int, Customer> collection;
};
#endif //!_CUSTOMER_COLLECTION_