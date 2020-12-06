#include "media.h"

//-----------------------------------------------------------------------------
// destructor
Media::~Media() {}

//-----------------------------------------------------------------------------
// setStock
// modify the number of stock in the system
void Media::setStock(unsigned int amount) {
    this->stock = amount;
}
	
//-----------------------------------------------------------------------------
// getStock
// return the amount of stock in the system
int Media::getStock() const {
    return this->stock;
}

//-----------------------------------------------------------------------------
// addStock
// increase the number of stock in the system
void Media::addStock(unsigned int amount) {
    this->stock += amount;
}

//-----------------------------------------------------------------------------
// reduceStock
// reduce the amount of stock in the system
bool Media::reduceStock(int amount) {
    if (this->stock - amount < 0)
        return false;
    else
        this->stock -= amount;
    return true;
}

//-----------------------------------------------------------------------------
// operator<<
// print out the media to the system
ostream& operator<<(ostream & out, const Media & media) {
    media.print(out);
    return out;
}