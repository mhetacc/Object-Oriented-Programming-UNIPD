#include "centralprocessingunit.h"
#include<iostream>
#include<cmath>


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

    void CentralProcessingUnit::modifyCores (int c) {
        if(c<0 && std::abs(c)>num_physical_cores) std::cerr<<" modify Error, valore comporta numero cores negativo"<<std::endl;
        else num_physical_cores+=c;
    }

    void CentralProcessingUnit::setCores (int c) {
        if(c>0)
        num_physical_cores=c;
        else std::cerr<<" set Error, inserire valore>0 "<<std::endl;
    }

    void CentralProcessingUnit::setHyperT (bool b) {
        hypertrheading=b;
    }

    CentralProcessingUnit::CentralProcessingUnit(int c, int mem, int num, bool b) : BaseComponent(c,mem), num_physical_cores(num), hypertrheading(b) {}


unsigned int CentralProcessingUnit::performance_percentage_increase=10;


std::ostream& operator<< (std::ostream& os , const CentralProcessingUnit& cpu ) {
    double mem=cpu.getMem();
        if(cpu.hypertrheading){
            return os << "La CPU con hyperthreading ha: "<< cpu.num_physical_cores <<" cores "<<cpu.getClock()<< " MHz "<< mem << " MB di cache";
        }
        else
            return os << "La CPU ha: "<< cpu.num_physical_cores<<" cores "<<cpu.getClock()<< " MHz "<< mem << " MB di cache";

}
