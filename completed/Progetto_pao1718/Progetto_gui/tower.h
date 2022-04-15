#ifndef TOWER_H
#define TOWER_H
#include"computer.h"

class Tower : public Computer {
private:
    double pscore() const;
public:
    double Score () const;
    Tower(CentralProcessingUnit =0, GraphicProcessingUnit =0, RandomAccessMemory =0, SecondaryMemory =0, double =0);
};

#endif // TOWER_H
