#ifndef SECONDARYMEMORY_H
#define SECONDARYMEMORY_H
#include"basecomponent.h"
#include<iostream>

class SecondaryMemory : public BaseComponent {
    friend std::ostream& operator<< (std::ostream&, const SecondaryMemory&);
    int write_speed; //MB/s
    int read_speed;  //MB/s
    double Score() const;
public:
    double getScore() const;
    void modifyWrite (int);
    void modifyRead (int);
    void setWrite (int);
    void setRead (int);
    SecondaryMemory(int =0, double =0, int =0, int =0);
};

std::ostream& operator << (std::ostream&, const SecondaryMemory&);



#endif // SECONDARYMEMORY_H
