#include "secondarymemory.h"
#include<cmath>
#include<iostream>



    double SecondaryMemory::Score() const {
        return (write_speed+read_speed+getMem());
    }

    double SecondaryMemory::getScore() const {
        return Score();
    }

    void SecondaryMemory::modifyWrite (int w){
        if(w<0 && std::abs(w)>=write_speed) std::cerr<<" modify Error, valore inserito rende velocita' scrittura negativa "; //controlla che sia una modifica "sicura"
        else write_speed+=w;
    }

    void SecondaryMemory::modifyRead (int r){
        if(r<0 && std::abs(r)>=read_speed) std::cerr<<" modify Error, valore inserito rende velocita' lettura negativa ";
        else read_speed+=r;
    }

    void SecondaryMemory::setWrite(int w){
        if(w>0)
        write_speed=w;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    void SecondaryMemory::setRead(int r){
        if(r>0)
        read_speed=r;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    SecondaryMemory::SecondaryMemory(int c, double mem, int w, int r) : BaseComponent(c,mem), write_speed(w), read_speed(r) {}

std::ostream& operator << (std::ostream& os, const SecondaryMemory& smd){
    double mem=smd.getMem()/1024.0; //da MB a GB
    return os << "La memoria secondaria ha " << mem << " GB "<< smd.write_speed<<" KB/s in scrittura e "<< smd.read_speed<< " KB/s in lettura";
}


