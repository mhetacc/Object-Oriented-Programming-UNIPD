#include "laptop.h"



double Laptop::pscore() const {
    return (partialScore() + (screen.getScore()+battery-weight))/getPrice();
}

QString Laptop::getPrint() const {
    QString s= Computer::getPrint(); //ha gia' +'\n' alla fine
    s+= screen.getPrint(); //ha gia' +'\n' alla fine
    QString bat = QString::number(battery);
    QString wgh = QString::number(weight);
    s+= ("Batteria= "+bat+" mAh"+'\n'+"Peso= "+wgh+" grammi"+'\n');
    return s;
}

void Laptop::Print() const {
    Computer::Print();
    std::cout<<std::endl;
    std::cout<<"Risoluzione schermo= "<<screen.getResW()<<" X "<<screen.getResH()<<std::endl<<"Dimensione schermo= "<<screen.getDim()<<std::endl<<"Batteria= "<<battery<<" mAh"<<std::endl<<"Peso= "<<weight<<std::endl;
}


double Laptop::Score() const {
    return pscore();
}

Laptop::Laptop(CentralProcessingUnit cpu,
               GraphicProcessingUnit gpu,
               RandomAccessMemory ram,
               SecondaryMemory mem, double prc, int mah, int wgh, Screen s) : Tower(cpu,gpu,ram,mem,prc), screen(s), battery(mah), weight(wgh) {}

void Laptop::setBattery (int bat){
    battery=bat;
}


void Laptop::setResolution (int resW, int resH){
    screen.setRes(resW, resH);
}


void Laptop::setDimension (double dim){
    screen.setDim(dim);
}

QString Laptop::modifyBattery (int bat){
    if(bat<0 && std::abs(bat)>battery) {
        std::cerr<<"Errore: valore inserito rende mAh batteria <=0";
        return ("           Errore: valore inserito rende mAh batteria <=0"+'\n');}
    else {
        battery+=bat;
        return "0";
    }
}


void Laptop::setWeight (int wgh){
    weight=wgh;
}

QString Laptop::modifyWeight (int wgh){
    if(wgh+weight<=0) {
        std::cerr<<"Errore: valore inserito rende peso <=0";
        return ("          Errore: valore inserito rende peso <=0"+'\n');}
    else {
        weight+=wgh;
        return "0";
    }
}
