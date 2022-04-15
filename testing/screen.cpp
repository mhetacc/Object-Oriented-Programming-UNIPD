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

int Screen::getResW() const { return resWidth;}

int Screen::getResH() const { return resHeight;}

int Screen::getRes() const { return resHeight*resWidth;}


double Screen::getDim() const { return dimension;}

double Screen::Score() const {  return getRes()/dimension;}

double Screen::getScore() const {  return Score();}     //lo score dello schermo e' fondamentalmente il suo DPI, ovvero la densita' di pixel per pollice
