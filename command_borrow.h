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
    bool setData(ifstream& infile);

    // process
    bool processBorrow(MediaCollection&, CustomerCollection&);

private:
    MediaType mediaType;
    MovieType movieType;
    Media * media;
    virtual ostream& out(ostream&) const override;
};

#endif //!_COMMAND_BORROW_