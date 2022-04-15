#include "secondarymemory.h"
#include<cmath>
#include<iostream>



    double SecondaryMemory::Score() const {
        return (write_speed+read_speed+getMem());
    }

    double SecondaryMemory::getScore() const {
        return Score();
    }

    QString SecondaryMemory::modifyWrite (int w){
        if(w<0 && std::abs(w)>=write_speed) {
            std::cerr<<"Errore: valore inserito rende velocita' scrittura negativa";
            return ("          Errore: valore inserito rende velocita' scrittura negativa"+'\n');} //controlla che sia una modifica "sicura"
        else {
            write_speed+=w;
            return "0";
        }
    }

    QString SecondaryMemory::modifyRead (int r){
        if(r<0 && std::abs(r)>=read_speed) {
            std::cerr<<"Errore: valore inserito rende velocita' lettura negativa";
            return ("          Errore: valore inserito rende velocita' lettura negativa"+'\n');}
        else {
            read_speed+=r;
            return "0";
        }
    }

    void SecondaryMemory::setWrite(int w){
        write_speed=w;
    }

    void SecondaryMemory::setRead(int r){
        read_speed=r;
    }

    SecondaryMemory::SecondaryMemory(int c, double mem, int w, int r) : BaseComponent(c,mem), write_speed(w), read_speed(r) {}

    QString SecondaryMemory::getPrint() const {
        QString s;
        double mm=getMem()/1024.0; //da MB a GB
        QString mem= QString::number(mm);
        QString write= QString::number(write_speed);
        QString read= QString::number(read_speed);
        s=("La memoria secondaria ha " + mem + " GB "+ write+" MB/s in scrittura e "+ read+ " MB/s in lettura");
        return s;

    }

std::ostream& operator << (std::ostream& os, const SecondaryMemory& smd){
    double mem=smd.getMem()/1024.0; //da MB a GB
    return os << "La memoria secondaria ha " << mem << " GB "<< smd.write_speed<<" MB/s in scrittura e "<< smd.read_speed<< " MB/s in lettura";
}


