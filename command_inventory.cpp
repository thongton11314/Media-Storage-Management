#include "command_inventory.h"

//----------------------------------------------------------------------------
// constructor
Inventory::Inventory() {
    this->type = INVENTORY;
}

//----------------------------------------------------------------------------
// destructor
Inventory::~Inventory() {
}

//----------------------------------------------------------------------------
// processInventory
void Inventory::processInventory(MediaCollection & meColl) {
    cout << "Inventory:" << endl;
    meColl.display();
}

//----------------------------------------------------------------------------
// operator<<
// print out command inventory data
ostream& operator<<(ostream & out, const Inventory & command) {
    out << command.type;
    return out;
}