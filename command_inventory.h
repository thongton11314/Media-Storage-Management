#ifndef _COMMAND_INVENTORY_
#define _COMMAND_INVENTORY_
#include "command.h"

// Class Inventory:
//  Description:
//   - Children class of command
//  Implementation:
//   - Create inventory:
//     - Create an inventory for the system
class Inventory : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Inventory&);

public:

    // constructor
    Inventory();

    // deconstructor
    ~Inventory();

    // show inventory in here
    void processInventory(MediaCollection&);
};
#endif //!_COMMAND_INVENTORY_