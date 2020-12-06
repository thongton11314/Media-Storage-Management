#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"

// define constant
const char BORROW = 'B';
const char RETURN = 'R';
const char HISTORY = 'H';
const char INVENTORY = 'I';
const char DEFAULT_TYPE = '!';
const string DEFAULT_FULLCOMMAND = "DEFAULT";

// identifer character as command type
typedef char CommandType;

// Class Command:
//  Description:
//   - Parent class of Borrow, Return, History, Inventory
//   - This class create command based on the customer requested
//  Implementation:
//   - Create command:
//     - Create a command for customer based on their request
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
};
#include "command_borrow.h"
#include "command_return.h"
#include "command_history.h"
#include "command_inventory.h"
#endif // !_COMMANDS_