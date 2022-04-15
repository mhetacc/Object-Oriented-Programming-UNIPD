#include "basecomponent.h"
#include<iostream>
#include<cmath>

    BaseComponent::BaseComponent (int c, double mem) : clockspeed(c), memory_dimension(mem) {}

    int BaseComponent::getClock () const {
        return clockspeed;
    }

    double BaseComponent::getMem () const {
        return memory_dimension;
    }

    QString BaseComponent::modifyMemory (double mem) {
        if((memory_dimension+mem)>0){
        memory_dimension+=mem;
        return "0";
        }
        else {
            std::cerr<<"Errore, valore inserito comporta memoria negativa";
            return ("          Errore, valore inserito comporta memoria negativa "+'\n');}
    }

    QString BaseComponent::modifyClock (int c) {
        if(c<0 && std::abs(c)>clockspeed) {
            std::cerr<<"Errore: valore inserito comporta clock negativo ";
            return ("          Errore: valore inserito comporta clock negativo "+'\n');}
        else {
            clockspeed+=c;
            return "0";
        }
    }

    void BaseComponent::setMemory (double mem){
        memory_dimension=mem;
    }

    void BaseComponent::setClock(int c){
        clockspeed=c;
    }

  //  unsigned int BaseComponent::getScore() const { return 0;}

    std::ostream& operator <<(std::ostream& os, const BaseComponent& bs){
        return os<<"clock "<<bs.clockspeed<<" mem "<<bs.memory_dimension<<std::endl;
    }
