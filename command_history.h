// add comments here

#ifndef _COMMAND_HISTORY_
#define _COMMAND_HISTORY_
#include "command.h"

// add comments here
class History : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const History&);

public:
    History();
    ~History();

    // setter
    // initialize data
    bool setData(ifstream & inFile);

    // function
    // process customer history
    void processHistory(CustomerCollection&);
    
private:
    virtual ostream& out(ostream &) const;
};

#endif //!_COMMAND_HISTORY_