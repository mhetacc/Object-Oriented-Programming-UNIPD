#include "graphicsprocessingunit.h"
#include<math.h>
#include<iostream>

    double GraphicProcessingUnit::Score () const {
        return (getClock() * (num_physical_cores/100) + bandwith + getMem());
    }

    double GraphicProcessingUnit::getScore() const{
        return Score();
    }

    QString GraphicProcessingUnit::modifyCores (int c) {
        if(c<0 && std::abs(c)>num_physical_cores) {
            std::cerr<<"Errore: valore inserito rende numero cores negativo";
            return ("          Errore: valore inserito rende numero cores negativo"+'\n');}
        else {
            num_physical_cores+=c;
            return "0";
        }
    }

    QString GraphicProcessingUnit::modifyBand (int b){
        if(b<0 && std::abs(b)>num_physical_cores) {
            std::cerr<<"Errore: valore inserito rende quantita' banda negativa";
            return ("          Errore: valore inserito rende quantita' banda negativa"+'\n');}
        else {
            bandwith+=b;
            return "0";
        }
    }

    void GraphicProcessingUnit::setCores (int c){
        num_physical_cores=c;
    }

    void GraphicProcessingUnit::setBand (int b){
        bandwith=b;
    }

    bool GraphicProcessingUnit::thereIsGPU () const {return gpuPresence;}

    GraphicProcessingUnit::GraphicProcessingUnit(int c, int mem, int num, int band, bool b) : BaseComponent(c,mem), num_physical_cores(num), bandwith(band), gpuPresence(b) {}


    void GraphicProcessingUnit::presenceGPU(bool b){
        gpuPresence=b;
    }

    QString GraphicProcessingUnit::getPrint() const {
        QString s;

        if(thereIsGPU()){
            double clock=getClock();
            QString band= QString::number(bandwith);
            QString cores= QString::number(num_physical_cores);
            QString mem= QString::number(getMem());
            if(clock>=1000) { //se clock>= 1GHz
                clock=clock/1000.0;
                QString clk= QString::number(clock);
                s=("La GPU ha "+ cores + " cores " + clk + " GHz "+ mem + " MB di DRAM " + band + " GB/s");
            }
            else{
                QString clk= QString::number(clock);
                s=("La GPU ha "+ cores+ " cores " + clk + " MHz "+ mem + " MB di DRAM " + band + " GB/s");
            }
        }
        else s="GPU non presente";

        return s;
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

