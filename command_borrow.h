// add comments here

#ifndef _COMMAND_BORROW_
#define _COMMAND_BORROW_
#include "command.h"

// add comments here
class Borrow : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Borrow&);

public:

    // constructor
    Borrow();

    // deconstructor
    ~Borrow();

    // setter
    // initialize data
    bool setData(ifstream & infile);

    // function
    void process(MediaCollection&, CustomerCollection&);
    bool procesReturn(Media*, Customer*); // part of process function

private:
    virtual ostream& out(ostream &) const;
};

#endif //!_COMMAND_BORROW_