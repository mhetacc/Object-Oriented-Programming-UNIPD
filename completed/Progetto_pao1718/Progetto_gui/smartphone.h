#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include"laptop.h"

class Smartphone : public Laptop {
private:
    unsigned int broadband_gen;  //generazione banda es: 3G, 4G, ...
    double pscore() const;
public:
    Smartphone(CentralProcessingUnit =0, GraphicProcessingUnit =0, RandomAccessMemory =0, SecondaryMemory =0, double =0,int =0, int =0, Screen =0,int =1);
    void Print () const;
    QString getPrint() const;
    double Score() const;
    void setGen (int);
};

#endif // SMARTPHONE_H
