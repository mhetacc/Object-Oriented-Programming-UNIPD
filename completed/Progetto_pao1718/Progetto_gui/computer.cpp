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

    QString Computer::getPrint() const {
        QString pr=QString::number(price);
        QString s= ("Il prezzo e' "+pr+'\n'+cpu.getPrint() +'\n' + gpu.getPrint()+'\n' + ram.getPrint()+'\n' + mem.getPrint()+'\n');
        return s;
    }


    QString Computer::modifyMemCPU (double m){
        return cpu.modifyMemory(m);
    }

    QString Computer::modifyMemGPU (double m){
        return gpu.modifyMemory(m);
    }

    QString Computer::modifyMemRAM (double m){
        return ram.modifyMemory(m);
    }

    QString Computer::modifyMemMEM (double m){
        return mem.modifyMemory(m);
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

    QString Computer::modifyClockCPU (int cl){
        return cpu.modifyClock(cl);
    }

    QString Computer::modifyClockGPU (int cl){
        return gpu.modifyClock(cl);
    }

    QString Computer::modifyClockRAM (int cl){
        return ram.modifyClock(cl);
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

    QString Computer::modifyCoresCPU (int co){
        return cpu.modifyCores(co);
    }

    QString Computer::modifyCoresGPU (int co){
        return gpu.modifyCores(co);
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

    QString Computer::modifyBandGPU (int b){
        return gpu.modifyBand(b);
    }
    void Computer::setBandGPU (int b){
        gpu.setBand(b);
    }

    QString Computer::modifyWriteSpeedMEM (int w){
        return mem.modifyWrite(w);
    }

    QString Computer::modifyReadSpeedMEM (int r){
        return mem.modifyRead(r);
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
        price=p;
    }

    void Computer::modifyPrice(double p){
       price+=p;
    }



