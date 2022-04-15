#include "computer.h"
#include<cmath>
#include<iostream>

Computer::Computer(CentralProcessingUnit cp,
                   GraphicProcessingUnit gp,
                   RandomAccessMemory ra,
                   SecondaryMemory me,
                   double pr) : cpu(cp), gpu(gp), ram(ra), mem(me), price(pr) {}



    double Computer::pscore () const {
        if (gpu.thereIsGPU()){
        return (cpu.getScore() + gpu.getScore() + ram.getScore() + mem.getScore());}
        else
            return (cpu.getScore() + ram.getScore() + mem.getScore());
    }

    double Computer::partialScore () const {
        return pscore();
    }

    double Computer::getPrice () const { return price; }

  //  Computer::~Computer () {}

    void Computer::Print() const {
        std::cout<<cpu<<std::endl<<gpu<<std::endl<<ram<<std::endl<<mem<<std::endl;
    }


    void Computer::modifyMemCPU (double m){
        cpu.modifyMemory(m);
    }

    void Computer::modifyMemGPU (double m){
        gpu.modifyMemory(m);
    }

    void Computer::modifyMemRAM (double m){
        ram.modifyMemory(m);
    }

    void Computer::modifyMemMEM (double m){
        mem.modifyMemory(m);
    }

    void Computer::setMemCPU (double m){
        cpu.setMemory(m);
    }

    void Computer::setMemGPU (double m){
        gpu.setMemory(m);
    }
    void Computer::setMemRAM (double m){
        ram.setMemory(m);
    }

    void Computer::setMemMEM (double m){
        mem.setMemory(m);
    }

    void Computer::modifyClockCPU (int cl){
        cpu.modifyClock(cl);
    }

    void Computer::modifyClockGPU (int cl){
        gpu.modifyClock(cl);
    }

    void Computer::modifyClockRAM (int cl){
        ram.modifyClock(cl);
    }

    void Computer::setClockCPU (int cl){
        cpu.setClock(cl);
    }

    void Computer::setClockGPU (int cl){
        gpu.setClock(cl);
    }

    void Computer::setClockRAM (int cl){
        ram.setClock(cl);
    }

    void Computer::modifyCoresCPU (int co){
        cpu.modifyCores(co);
    }

    void Computer::modifyCoresGPU (int co){
        gpu.modifyCores(co);
    }

    void Computer::setCoresCPU (int co){
        cpu.setCores(co);
    }
    void Computer::setCoresGPU(int co){
        gpu.setCores(co);
    }

    void Computer::setHyperCPU (bool hy){
        cpu.setHyperT(hy);
    }

    void Computer::modifyBandGPU (int b){
        gpu.modifyBand(b);
    }
    void Computer::setBandGPU (int b){
        gpu.setBand(b);
    }

    void Computer::modifyWriteSpeedMEM (int w){
        mem.modifyWrite(w);
    }

    void Computer::modifyReadSpeedMEM (int r){
        mem.modifyRead(r);
    }

    void Computer::setWriteSpeedMEM (int w){
        mem.setWrite(w);
    }

    void Computer::setReadSpeedMEM (int r){
        mem.setRead(r);
    }

    void Computer::setGPUpresence(bool gp) {
        gpu.presenceGPU(gp);
    }

    void Computer::setPrice(double p){
        if(p>=0)
        price=p;
    }

    void Computer::modifyPrice(double p){
        if(p<0 && p>price) std::cerr<<" modify Error ";
        else price=p;
    }



