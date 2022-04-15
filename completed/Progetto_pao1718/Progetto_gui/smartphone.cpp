#include "smartphone.h"

    unsigned int weight;

    double Smartphone::pscore() const {
        return Laptop::Score()*broadband_gen;
    }

    Smartphone::Smartphone(CentralProcessingUnit cpu,
                           GraphicProcessingUnit gpu,
                           RandomAccessMemory ram,
                           SecondaryMemory mem,
                           double prc,int resw, int resh, Screen s,int gen) : Laptop(cpu,gpu,ram,mem,prc,resw,resh,s), broadband_gen(gen) {}

    void Smartphone::Print()const{
        Laptop::Print();
        std::cout<<std::endl<<"Lo smarphone e' un "<<broadband_gen<<"G"<<std::endl;
    }

    double Smartphone::Score() const {return pscore();}

    QString Smartphone::getPrint() const {
        QString s=Laptop::getPrint(); //ha gia' alla fine '\n'
        QString bbgen= QString::number(broadband_gen);
        s+=("Lo smarphone e' un "+bbgen+"G"+'\n');
        return s;
    }

    void Smartphone::setGen(int gen) {
        broadband_gen=gen;
    }


