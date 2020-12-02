#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"

const char BORROW = 'B';
const char RETURN = 'R';
const char HISTORY = 'H';
const char INVENTORY = 'I';
const char DEFAULT_TYPE = '!';
const string DEFAULT_FULLCOMMAND = "DEFAULT";

typedef char CommandType;

// add comments here a
class Command {

    // print out fulll command
    friend ostream& operator<<(ostream&, const Command&);

    public:

        // constructor
        Command();

        // copy constructor
        Command(const Command &);

        // deconstructor
        virtual ~Command();

        // setter
        void setCustomerID(int ID);
        void setCommandType(char);

        // getter
        int getCustomerID() const;
        CommandType getCommandType() const;

        // function
        // process
        virtual bool process(MediaCollection&, CustomerCollection&);

    protected:
        int customerID;
        CommandType type;
        string fullCommand;
        virtual ostream& out(ostream &) const;
        // add more data if needed
};
#include "command_borrow.h"
#include "command_return.h"
#include "command_history.h"
#include "command_inventory.h"
#endif // !_COMMANDS_