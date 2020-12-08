#ifndef _COMMAND_RETURN_
#define _COMMAND_RETURN_
#include "command_borrow_or_return.h"

// Class Return:
//  Description:
//   - Children class of command
//  Implementation:
//   - Create return:
//     - Create a return request for the customer
class Return : public BorrowOrReturn {

    // print out full command
    friend ostream& operator<<(ostream&, const Return&);

public:

    // constructor
    Return();
    
    // deconstructor
    ~Return();

    // process
    bool processReturn(MediaCollection&, CustomerCollection&);

private:
    virtual ostream& out(ostream&) const override;
};
#endif //!_COMMAND_RETURN_