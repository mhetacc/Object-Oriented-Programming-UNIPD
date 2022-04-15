#include "screen.h"
#include<iostream>


Screen :: Screen (int w, int h, double dim) : resWidth(w), resHeight(h), dimension(dim) {}

void Screen::setRes(int w, int h){
    if(w>=0 && h>=0){
    resWidth=w;
    resHeight=h;
    }
    else std::cerr<<"Input error, inserire valori >=0"<<std::endl;
}

void Screen::setDim(double dim){
    if(dim>=0)
        dimension=dim;
    else std::cerr<<"Input error, inserire valore >=0"<<std::endl;
}

QString Screen::getPrint() const{
    QString resW=QString::number(resWidth);
    QString resH=QString::number(resHeight);
    QString dim=QString::number(dimension);
    return ("Risoluzione schermo= "+resW+" X "+resH+" pixels"+'\n'+"Dimensione schermo= "+dim+" pollici"+'\n');
}

int Screen::getResW() const { return resWidth;}

int Screen::getResH() const { return resHeight;}

int Screen::getRes() const { return resHeight+resWidth;}


double Screen::getDim() const { return dimension;}

double Screen::Score() const {  return getRes()/dimension;}  //piu' e' grande lo schermo a parita' di pixel, meno alto e' lo score

double Screen::getScore() const {  return Score();}
