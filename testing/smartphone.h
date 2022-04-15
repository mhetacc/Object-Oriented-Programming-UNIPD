#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include"laptop.h"

class Smartphone : public Laptop {
    unsigned int broadband_gen;  //generazione banda es: 3G, 4G, ...
    double pscore() const;
public:
    Smartphone(int =1);
    void Print () const;
    double Score() const;
    void setGen (int);
};

#endif // SMARTPHONE_H
