#include "command_inventory.h"
//----------------------------------------------------------------------------
// Constructor
Inventory::Inventory() {
    this->type = INVENTORY;
}
//----------------------------------------------------------------------------
// Destructor
Inventory::~Inventory() {
}
//----------------------------------------------------------------------------
//processInventory
void Inventory::processInventory(MediaCollection & meColl) {
    cout << "Inventory:" << endl;
    meColl.display();
}
//----------------------------------------------------------------------------
ostream& operator<<(ostream & out, const Inventory & command) {
    out << command.type;
    return out;
}
