#ifndef _COMMAND_INVENTORY_
#define _COMMAND_INVENTORY_
#include "command.h"

class Inventory : public Command {

    // print out full command
    friend ostream& operator<<(ostream&, const Inventory&);

public:
    Inventory();
    ~Inventory();

    // show inventory in here
    void processInventory(MediaCollection&);
};

#endif //!_COMMAND_INVENTORY_