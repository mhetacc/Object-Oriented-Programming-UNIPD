#include "randomaccessmemory.h"

    double RandomAccessMemory::Score () const {return (getClock() + getMem());}

    double RandomAccessMemory::getScore() const {return Score();}

    RandomAccessMemory::RandomAccessMemory(int c, int mem) : BaseComponent(c,mem) {}

    QString RandomAccessMemory::getPrint() const {
        QString s;
        unsigned int mem=getMem();
        double memGB=mem/1024.0;
        QString mm=QString::number(memGB);
        QString clock= QString::number(getClock());
        s=( "La RAM ha: "+ mm + " GB" + ' ' +clock + " MHz");
        return s;
    }

std::ostream& operator<< (std::ostream& os, const RandomAccessMemory& ram) {
    unsigned int mem=ram.getMem();
       double memGB=mem/1024.0;
       return os << "La RAM ha: "<< memGB << " GB" << ' ' << ram.getClock() << " MHz";
    }



