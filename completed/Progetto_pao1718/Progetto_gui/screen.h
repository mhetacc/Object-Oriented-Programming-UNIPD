#ifndef SCREEN_H
#define SCREEN_H
#include"component.h"

//The area, height and width of displays with identical diagonal measurements vary

class Screen : public Component
{
private:
    int resWidth;  //pixels
    int resHeight;  //pixels
    double dimension;  //diagonal inches
    double Score() const;
public:
    Screen(int =0, int =0, double =0);
    void setRes (int, int);
    void setDim (double);
    int getRes() const;
    double getDim () const;
    int getResW() const;
    int getResH() const;
    QString getPrint() const;

    double getScore() const;
};



#endif // SCREEN_H
