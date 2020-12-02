#ifndef _COMMAND_FACTORY_
#define _COMMAND_FACTORY_
#include <iomanip>
#include "command.h"
#include "command_borrow.h"
#include "command_return.h"
#include "command_history.h"
#include "command_inventory.h"

class CommandFactory {
public:
    static Command * createCommand(ifstream & infile);
private:
    static Command * createBorrow(ifstream& infile);
    static Command * createReturn(ifstream& infile);
    static Command * createHistory(ifstream& infile);
    static Command * createInventory(ifstream& infile);
    static void errorType(const char & cType, ifstream& infile);
};

#endif //!_COMMAND_FACTORY_