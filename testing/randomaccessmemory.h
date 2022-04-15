#ifndef RANDOMACCESSMEMORY_H
#define RANDOMACCESSMEMORY_H
#include"basecomponent.h"
#include<iostream>

class RandomAccessMemory : public BaseComponent {
    friend std::ostream& operator<< (std::ostream& , const RandomAccessMemory& );
    double Score () const;
public:
    double getScore() const;
    RandomAccessMemory(int =0, int =0); //eredita setClock setMem ecc

};
std::ostream& operator<< (std::ostream&, const RandomAccessMemory&);
#endif // RANDOMACCESSMEMORY_H
