#include "command_inventory.h"

Inventory::Inventory() {
    this->type = INVENTORY;
}

Inventory::~Inventory() {
}

void Inventory::processInventory(MediaCollection&) {
}

ostream& operator<<(ostream& out, const Inventory& command) {
    out << command.type;
    return out;
}
