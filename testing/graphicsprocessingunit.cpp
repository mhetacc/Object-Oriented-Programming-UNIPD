#include "graphicsprocessingunit.h"
#include<math.h>
#include<iostream>

    double GraphicProcessingUnit::Score () const {
        return (getClock() * (num_physical_cores/100) + bandwith + getMem());
    }

    double GraphicProcessingUnit::getScore() const{
        return Score();
    }

    void GraphicProcessingUnit::modifyCores (int c) {
        if(c<0 && std::abs(c)>num_physical_cores) std::cerr<<" modify Error, valore inserito rende numero cores negativo ";
        else num_physical_cores+=c;
    }

    void GraphicProcessingUnit::modifyBand (int b){
        if(b<0 && std::abs(b)>num_physical_cores) std::cerr<<" modify Error, valore inserito rende quantita' banda negativa ";
        else bandwith+=b;
    }

    void GraphicProcessingUnit::setCores (int c){
        if(c>0)
        num_physical_cores=c;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    void GraphicProcessingUnit::setBand (int b){
        if(b>0)
        bandwith=b;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    bool GraphicProcessingUnit::thereIsGPU () const {return gpuPresence;}

    GraphicProcessingUnit::GraphicProcessingUnit(int c, int mem, int num, int band, bool b) : BaseComponent(c,mem), num_physical_cores(num), bandwith(band), gpuPresence(b) {}


    void GraphicProcessingUnit::presenceGPU(bool b){
        gpuPresence=b;
    }

std::ostream& operator<< (std::ostream& os, const GraphicProcessingUnit& gpu){
    double clock=gpu.getClock();
    if(clock>=1000) { //se clock>= 1GHz
    clock=clock/1000.0;
    return os <<"La GPU ha "<< gpu.num_physical_cores << " cores " << clock << " GHz "<< gpu.getMem() << " MB di DRAM " << gpu.bandwith << " GB/s";
    }
    else
        return os <<"La GPU ha "<< gpu.num_physical_cores<< " cores " << clock << " MHz "<< gpu.getMem() << " MB di DRAM " << gpu.bandwith << " GB/s";
}


