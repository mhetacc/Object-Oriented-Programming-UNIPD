#include "centralprocessingunit.h"
#include<iostream>
#include<cmath>
#include<QString>

    double CentralProcessingUnit::Score () const {
        unsigned int sum, var;
        double mem=getMem();
        sum= (num_physical_cores*getClock()+mem);
        if (hypertrheading){
            var= (sum*performance_percentage_increase)/100; //aumento performance percentuale sistemata in modo tale che si traduca in aumento medio del 10% nelle performance del sistema finale
            sum+=var;
        }
        if(mem>4 && mem<=8)
                    var=(sum*20)/100;
                else{
                    if(mem<=4)
                        var=(sum*10)/100;
                    if(mem>8)
                        var=(sum*30)/100;
                }
        sum+=var;
        return sum;
    }

    double CentralProcessingUnit::getScore() const {
        return Score();
    }

    QString CentralProcessingUnit::modifyCores (int c) {
        if(c<0 && std::abs(c)>num_physical_cores) {
            std::cerr<<"Errore: valore inserito comporta numero cores negativo";
            return ("          Errore: valore inserito comporta numero cores negativo"+'\n');}
        else {
            num_physical_cores+=c;
            return "0";
        }
    }

    void CentralProcessingUnit::setCores (int c) {
        num_physical_cores=c;
    }

    void CentralProcessingUnit::setHyperT (bool b) {
        hypertrheading=b;
    }

    CentralProcessingUnit::CentralProcessingUnit(int c, int mem, int num, bool b) : BaseComponent(c,mem), num_physical_cores(num), hypertrheading(b) {}


unsigned int CentralProcessingUnit::performance_percentage_increase=10;


QString CentralProcessingUnit::getPrint() const {
    QString cores=QString::number(num_physical_cores);
    QString clock=QString::number(getClock());
    QString mem=QString::number(getMem());
    QString s;
    if(hypertrheading){
        s= ("La CPU con hyperthreading ha: "+ cores+" cores "+clock+ " MHz "+ mem + " MB di cache");
    }
    else
        s= ("La CPU ha: "+ cores+" cores "+clock+ " MHz "+ mem + " MB di cache");
    return s;
}

std::ostream& operator<< (std::ostream& os , const CentralProcessingUnit& cpu ) {
        if(cpu.hypertrheading){
            return os << "La CPU con hyperthreading ha: "<< cpu.num_physical_cores <<" cores "<<cpu.getClock()<< " MHz "<< cpu.getMem() << " MB di cache";
        }
        else
            return os << "La CPU ha: "<< cpu.num_physical_cores<<" cores "<<cpu.getClock()<< " MHz "<< cpu.getMem() << " MB di cache";

}
