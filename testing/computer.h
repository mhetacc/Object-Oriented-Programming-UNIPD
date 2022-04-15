#ifndef COMPUTER_H
#define COMPUTER_H
#include"centralprocessingunit.h"
#include"graphicsprocessingunit.h"
#include"randomaccessmemory.h"
#include"secondarymemory.h"
#include<iostream>

class Computer {
    CentralProcessingUnit cpu;
    GraphicProcessingUnit gpu;
    RandomAccessMemory ram;
    SecondaryMemory mem;
    double price;
    double pscore () const;
public:
    double partialScore () const;
    double getPrice () const;

    virtual void Print() const;

    void modifyMemCPU (double);
    void modifyMemGPU (double);
    void modifyMemRAM (double);
    void modifyMemMEM (double);
    void setMemCPU (double);
    void setMemGPU (double);
    void setMemRAM (double);
    void setMemMEM (double);

    void modifyClockCPU (int);
    void modifyClockGPU (int);
    void modifyClockRAM (int);
    void setClockCPU (int);
    void setClockGPU (int);
    void setClockRAM (int);

    void modifyCoresCPU (int);
    void modifyCoresGPU (int);
    void setCoresCPU (int);
    void setCoresGPU (int);

    void setHyperCPU (bool);

    void modifyBandGPU (int);
    void setBandGPU (int);

    void modifyWriteSpeedMEM (int);
    void modifyReadSpeedMEM (int);
    void setWriteSpeedMEM (int);
    void setReadSpeedMEM (int);

    void setGPUpresence (bool);

    void setPrice (double);
    void modifyPrice (double);

    Computer (CentralProcessingUnit =0, GraphicProcessingUnit =0, RandomAccessMemory =0, SecondaryMemory =0, double =0);
    virtual double Score () const =0;
    virtual ~Computer () =default;

};
#endif // COMPUTER_H
