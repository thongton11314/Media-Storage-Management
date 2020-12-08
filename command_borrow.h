#ifndef _COMMAND_BORROW_
#define _COMMAND_BORROW_
#include "command_borrow_or_return.h"

// Class Borrow:
//  Description:
//   - The children of command
//  Implementation:
//   - Create borrow:
//     - Create a borrowing request for the customer.
class Borrow : public BorrowOrReturn {

    // print out full command
    friend ostream& operator<<(ostream&, const Borrow&);

public:

    // constructor
    Borrow();

    // deconstructor
    ~Borrow();

    // process
    bool processBorrow(MediaCollection&, CustomerCollection&);

private:
    virtual ostream& out(ostream&) const override;
};
#endif //!_COMMAND_BORROW_