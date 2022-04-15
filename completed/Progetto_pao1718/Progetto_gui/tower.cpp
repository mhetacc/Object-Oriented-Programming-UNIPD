#include "tower.h"



double Tower::pscore() const {
    return partialScore()/getPrice();
}

double Tower::Score () const {
    return pscore();
}

Tower::Tower(CentralProcessingUnit cpu,
             GraphicProcessingUnit gpu,
             RandomAccessMemory ram,
             SecondaryMemory mem,
             double prc) : Computer(cpu,gpu,ram,mem,prc) {}

