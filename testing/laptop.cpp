#include "laptop.h"



double Laptop::pscore() const {
    return (partialScore() + (screen.getScore()*battery))/getPrice();
}



void Laptop::Print() const {
    Computer::Print();
    std::cout<<std::endl;
    std::cout<<"Risoluzione schermo= "<<screen.getResW()<<" X "<<screen.getResH()<<std::endl<<"Dimensione schermo= "<<screen.getDim()<<std::endl<<"Batteria= "<<battery<<" mAh"<<std::endl<<"Peso= "<<weight<<std::endl;
}

double Laptop::Score() const {
    return pscore();
}

Laptop::Laptop(int mah, int wgh, Screen s) : Tower(), screen(s), battery(mah), weight(wgh) {}

void Laptop::setBattery (int bat){
    if(bat>0)
    battery=bat;
    else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
}


void Laptop::setResolution (int resW, int resH){
    if(resW >=0 && resH>=0){
        screen.setRes(resW, resH);
    }
    else std::cerr<<" set Error, inserire valori >= 0"<<std::endl;
}


void Laptop::setDimension (double dim){
    if(dim>0)
    screen.setDim(dim);
    else std::cerr<<"set Error, inserire val >0"<<std::endl;
}

void Laptop::modifyBattery (int bat){
    if(bat<0 && std::abs(bat)>battery) std::cerr<<" modify Error, valore inserito rende mAh batteria negativi "<<std::endl;
    else battery+=bat;
}


void Laptop::setWeight (int wgh){
    if(wgh>0)
    weight=wgh;
    else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
}

void Laptop::modifyWeight (int wgh){
    if(wgh<0 && wgh>weight) std::cerr<<" modify Error valore inserito rende dimensione diagonale schermo negativa "<<std::endl;
    else weight+=wgh;
}
