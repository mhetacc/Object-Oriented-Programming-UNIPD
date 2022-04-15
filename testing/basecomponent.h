#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H
#include"component.h"
#include<iostream>

class BaseComponent : public Component {
    friend std::ostream& operator<<(std::ostream&, const BaseComponent&);
    int clockspeed; //MHz
    double memory_dimension; //MB
public:
    BaseComponent (int =0, double =0);

    int getClock() const;
    double getMem () const;
    void modifyMemory (double);
    void modifyClock (int);
    void setMemory (double);
    void setClock (int);
   // unsigned int getScore() const;  resta virtuale = 0
};
std::ostream& operator<<(std::ostream&, const BaseComponent&);

#endif // BASECOMPONENT_H
