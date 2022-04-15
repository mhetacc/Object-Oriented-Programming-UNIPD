#include "tower.h"



double Tower::pscore() const {
    return partialScore()/getPrice();
}

double Tower::Score () const {
    return pscore();
}

Tower::Tower() : Computer() {}

