#ifndef TOWER_H
#define TOWER_H
#include"computer.h"

class Tower : public Computer {
    double pscore() const;
public:
    double Score () const;
    Tower();
};

#endif // TOWER_H
