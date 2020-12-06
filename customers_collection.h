#ifndef _CUSTOMER_COLLECTION_
#define _CUSTOMER_COLLECTION_
#include "customer.h"
#include "hashtable.h"

// Class CustomerCollection:
//  Description:
//   - This class control and modify the information of customer in the system
//  Implementation:
//   - Create customer:
//     - Insert, remove and retrieve customer from the system
class CustomerCollection {
public:

    // constructor
    CustomerCollection();

    // deconstructor
    ~CustomerCollection();

    // insert customer
    bool insertCustomer(Customer * customer);

    // retrieve customer
    bool retrieveCustomer(const int & id, Customer *& retriever) const;

    // remove customer by giving customer ID
    bool removeCustomerByID(const int & id);

    // return a constant pointer of customer by giving customer ID
    const Customer * getACustomer(const int & id) const;

    // display all customer
    void display() const;
private:

    // a table to hold all customers
    Hashtable<int, Customer> collection;
};
#endif //!_CUSTOMER_COLLECTION_
