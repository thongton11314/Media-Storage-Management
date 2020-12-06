#ifndef _COMMAND_FACTORY_
#define _COMMAND_FACTORY_
#include <iomanip>
#include "command.h"
#include "command_borrow.h"
#include "command_return.h"
#include "command_history.h"
#include "command_inventory.h"

// Class CommandFactory:
//  Description:
//   - This class read file and create command according from the file
//  Implementation:
//   - Create command factory:
//     - create new return, borrow, history, and inventory commmand
class CommandFactory {
public:

    // read the whole file and start inputting commands from the file
    static Command * createCommand(ifstream & infile);
private:

    // if input from command is B, create a new borrow command
    static Command * createBorrow(ifstream& infile);
    
    // if input from command is R, create a new return command
    static Command * createReturn(ifstream& infile);
    
    // if input from command is H, create a new history command
    static Command * createHistory(ifstream& infile);
    
    // if input from command is Invenrtory, create a new inventory command
    static Command * createInventory(ifstream& infile);
    
    // check for command types that are not in the system
    static void errorType(const char & cType, ifstream& infile);
};
#endif //!_COMMAND_FACTORY_