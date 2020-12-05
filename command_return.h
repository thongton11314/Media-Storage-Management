// add comments here

#ifndef _COMMAND_RETURN_
#define _COMMAND_RETURN_
#include "command.h"

// Class Return:
//  Description:
//   - Children class of command
//  Implementation:
//   - Create return:
//     - Create a return request for the customer.
class Return : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Return&);

public:

    // constructor
    Return();
    
    // deconstructor
    ~Return();

    // setter
    bool setData(ifstream& infile);

    // process
    bool processReturn(MediaCollection&, CustomerCollection&);

private:
    MediaType mediaType;
    MovieType movieType;
    Media* media;
    virtual ostream& out(ostream&) const override;
};

#endif //!_COMMAND_RETURN_
