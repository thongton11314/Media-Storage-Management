#ifndef _COMMAND_BORROW_OR_RETURN_
#define _COMMAND_BORROW_OR_RETURN_
#include "command.h"

// Class BorrowOrReturn:
//  Description:
//   - Child class of Command
//   - Parent class of Borrow, Return
//  Implementation:
//   - read data from file to set command
class BorrowOrReturn : public Command {

	// print out fulll command
	friend ostream& operator<<(ostream&, const BorrowOrReturn&);

public:
    BorrowOrReturn();
    ~BorrowOrReturn();

    // setter
    // use to set data
    bool setData(ifstream&);

protected:
    MediaType mediaType;
    MovieType movieType;
    Media* media;

    // ultility functions for setData function
    void processComedy(ifstream&, Media*&);
    void processClassic(ifstream&, Media*&);
    void processDrama(ifstream&, Media*&);
    void processInvalid(ifstream&, const string&, const string&);

    // use to set data to ostream
	virtual ostream& out(ostream&) const;
};
#include "command_borrow.h"
#include "command_return.h"
#endif //!_COMMAND_BORROW_OR_RETURN_