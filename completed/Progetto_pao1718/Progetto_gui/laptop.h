#ifndef LAPTOP_H
#define LAPTOP_H
#include"tower.h"
#include"screen.h"
#include<iostream>

class Laptop : public Tower {
    Screen screen;  //ha pixelXpixel e dimensione pollici diagonale
    int battery; //mAh
    int weight; //in grammi
    double pscore () const;
public:
    double Score() const;
    Laptop (CentralProcessingUnit =0, GraphicProcessingUnit =0, RandomAccessMemory =0, SecondaryMemory =0, double =0,int =0, int =0, Screen =0);

    void Print() const;
    QString getPrint() const;

    void setBattery (int);
    void setResolution (int, int);
    void setDimension (double);


    QString modifyBattery (int);
    QString modifyDimension (int);

    void setWeight (int);
    QString modifyWeight (int);
};
#endif // LAPTOP_H
