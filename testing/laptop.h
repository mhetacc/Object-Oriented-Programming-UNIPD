#ifndef LAPTOP_H
#define LAPTOP_H
#include"tower.h"
#include"screen.h"
#include<iostream>

class Laptop : public Tower {
    friend std::ostream& operator <<(std::ostream&, const Laptop&);
    Screen screen;  //ha pixelXpixel e dimensione pollici diagonale
    int battery; //mAh
    int weight; //in grammi
    double pscore () const;
public:
    double Score() const;
    Laptop (int =0, int =0, Screen =0);

    void Print() const;

    void setBattery (int);
    void setResolution (int, int);
    void setDimension (double);

    void modifyBattery (int);
    void modifyDimension (int);

    void setWeight (int);
    void modifyWeight (int);
};
std::ostream& operator <<(std::ostream&, const Laptop&);
#endif // LAPTOP_H
