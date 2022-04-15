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

    void BaseComponent::modifyMemory (double mem) {
        if((memory_dimension+mem)>0)
        memory_dimension+=mem;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    void BaseComponent::modifyClock (int c) {
        if(c<0 && std::abs(c)>clockspeed) std::cerr<<" modify Error, valore inserito comporta clock negativo "<<std::endl;
        else clockspeed+=c;
    }

    void BaseComponent::setMemory (double mem){
        if(mem>0)
        memory_dimension=mem;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    void BaseComponent::setClock(int c){
        if(c>0)
        clockspeed=c;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

  //  unsigned int BaseComponent::getScore() const { return 0;}

    std::ostream& operator <<(std::ostream& os, const BaseComponent& bs){
        return os<<"clock "<<bs.clockspeed<<" mem "<<bs.memory_dimension<<std::endl;
    }
