// add comments here

#ifndef _COMMAND_RETURN_
#define _COMMAND_RETURN_
#include "command.h"

// add comments here
class Return : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Return&);

public:
    Return();
    ~Return();

    // setter
    // initialize data
    bool setData(ifstream & inFile);

    // function
    void process(MediaCollection&, CustomerCollection&);
    bool procesReturn(Media*, Customer*); // part of process function

private:
    virtual ostream& out(ostream &) const;
};

#endif //!_COMMAND_RETURN_