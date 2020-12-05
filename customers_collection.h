// add comments here
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
