#ifndef _COMMANDS_
#define _COMMANDS_
#include "customers_collection.h"
#include "media_collection.h"

// identifer character as command type
enum CommandType {
    BorrowType = 'B',
    ReturnType = 'R',
    HistoryType = 'H',
    InventoryType = 'I',
    DefaultCommandType = '!'
};

// Class Command:
//  Description:
//   - Parent class of BorrowOrReturn, History, Inventory
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
        void setCommandType(CommandType);

        // getter
        int getCustomerID() const;
        CommandType getCommandType() const;

        // function
        // process
        virtual void process(MediaCollection&, CustomerCollection&);

    protected:
        int customerID;
        CommandType commandType;
        string fullCommand;
        virtual ostream& out(ostream &) const;
};
#include "command_borrow_or_return.h"
#include "command_history.h"
#include "command_inventory.h"
#endif // !_COMMANDS_