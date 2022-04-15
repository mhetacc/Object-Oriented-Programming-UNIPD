#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H
#include"component.h"
#include<iostream>
#include<QString>


class BaseComponent : public Component {
private:
    friend std::ostream& operator<<(std::ostream&, const BaseComponent&);
    int clockspeed; //MHz
    double memory_dimension; //MB
public:
    BaseComponent (int =0, double =0);


    QString modifyMemory (double);
    QString modifyClock (int);
    void setMemory (double);
    void setClock (int);
protected:
    int getClock() const;
    double getMem () const;
};
std::ostream& operator<<(std::ostream&, const BaseComponent&);

#endif // BASECOMPONENT_H
