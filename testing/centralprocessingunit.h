#ifndef CENTRALPROCESSINGUNIT_H
#define CENTRALPROCESSINGUNIT_H
#include"basecomponent.h"
#include<iostream>



class CentralProcessingUnit : public BaseComponent {
    friend std::ostream& operator<< (std::ostream& , const CentralProcessingUnit& );
    static unsigned int performance_percentage_increase;
    int num_physical_cores;
    bool hypertrheading;
    double Score () const;
public:
    double getScore() const;
    void modifyCores (int);
    void setCores (int);
    void setHyperT (bool);
    CentralProcessingUnit(int =0, int =0, int =0, bool =false);
    //ricorda che ha set write/read
};
std::ostream& operator<< (std::ostream&  , const CentralProcessingUnit&  );

#endif // CENTRALPROCESSINGUNIT_H
