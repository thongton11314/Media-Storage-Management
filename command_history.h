// add comments here

#ifndef _COMMAND_HISTORY_
#define _COMMAND_HISTORY_
#include "command.h"

// Class History:
//  Description:
//   - Children class of command
//  Implementation:
//   - Create history:
//     - Create a history that store all the request from customer.
class History : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const History&);

public:
    History();
    ~History();

    // setter
    // initialize data
    bool setData(ifstream& infile);

    // function
    // process customer history
    bool processHistory(CustomerCollection&);
    
private:
    virtual ostream& out(ostream&) const override;
};
#endif //!_COMMAND_HISTORY_