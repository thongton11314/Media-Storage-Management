#include "media.h"

Media::~Media() {}

void Media::setStock(unsigned int amount) {
    this->stock = amount;
}
	
int Media::getStock() const {
    return this->stock;
}

void Media::addStock(unsigned int amount) {
    this->stock += amount;
}

bool Media::reduceStock(int amount) {
    if (this->stock - amount < 0)
        return false;
    else
        this->stock -= amount;
    return true;
}

ostream& operator<<(ostream & out, const Media & media) {
    media.print(out);
    return out;
}