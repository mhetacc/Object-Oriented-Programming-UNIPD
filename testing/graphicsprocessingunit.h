#ifndef GRAPHICSPROCESSINGUNIT_H
#define GRAPHICSPROCESSINGUNIT_H
#include"basecomponent.h"
#include<iostream>

class GraphicProcessingUnit : public BaseComponent {
    friend std::ostream& operator<<(std::ostream&, const GraphicProcessingUnit&);
    int num_physical_cores;
    int bandwith; //GB/s
    bool gpuPresence;
    double Score () const;
public:
    double getScore() const;
    void modifyCores (int);
    void modifyBand (int);
    void setCores (int);
    void setBand (int);
    bool thereIsGPU () const;
    void presenceGPU (bool);
    GraphicProcessingUnit(int =0, int =0, int =0, int =0, bool =false);
};
std::ostream& operator<<(std::ostream&, const GraphicProcessingUnit&);


#endif // GRAPHICSPROCESSINGUNIT_H
