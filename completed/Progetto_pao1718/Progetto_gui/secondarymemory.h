#ifndef SECONDARYMEMORY_H
#define SECONDARYMEMORY_H
#include"basecomponent.h"
#include<iostream>

class SecondaryMemory : public BaseComponent {
private:
    friend std::ostream& operator<< (std::ostream&, const SecondaryMemory&);
    int write_speed; //MB/s
    int read_speed;  //MB/s
    double Score() const;
public:
    QString getPrint() const;
    double getScore() const;
    QString modifyWrite (int);
    QString modifyRead (int);
    void setWrite (int);
    void setRead (int);
    SecondaryMemory(int =0, double =0, int =0, int =0);
};

std::ostream& operator << (std::ostream&, const SecondaryMemory&);



#endif // SECONDARYMEMORY_H
