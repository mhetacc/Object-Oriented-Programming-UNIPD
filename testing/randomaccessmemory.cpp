#include "randomaccessmemory.h"

    double RandomAccessMemory::Score () const {return (getClock() + getMem());}

    double RandomAccessMemory::getScore() const {return Score();}

    RandomAccessMemory::RandomAccessMemory(int c, int mem) : BaseComponent(c,mem) {}

std::ostream& operator<< (std::ostream& os, const RandomAccessMemory& ram) {
    unsigned int mem=ram.getMem();
       double memGB=mem/1024.0;
       return os << "La RAM ha: "<< memGB << " GB" << ' ' << ram.getClock() << " MHz";
    }



