#include "smartphone.h"

    unsigned int weight;

    double Smartphone::pscore() const {
        return Laptop::Score()*broadband_gen;
    }

    Smartphone::Smartphone(int gen) : Laptop(), broadband_gen(gen) {}
    void Smartphone::Print()const{
        Laptop::Print();
        std::cout<<std::endl<<"Lo smarphone e' un "<<broadband_gen<<"G"<<std::endl;
    }

    double Smartphone::Score() const {return pscore();}

    void Smartphone::setGen(int gen) {
        if(gen>0)
            broadband_gen=gen;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }


