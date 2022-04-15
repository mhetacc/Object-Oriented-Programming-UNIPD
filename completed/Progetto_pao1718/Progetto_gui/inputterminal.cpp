#include<iostream>
#include<list>
#include"inputterminal.h"

//l' input per proteggersi da errori dovrebbe sempre essere una stringa, poi manipolata con strumenti adeguati. Tuttavia non essendo
//questo l' obbiettivo del progetto e' stato preferito un approccio meno esoso in termini di tempo e risorse, di fatto
//esponendosi alla possibilita' di avere un bad cin


void inputTerminal () {
    std::cout<<"Attenzione: inserendo un valore di tipo A dove andrebbe un tipo B, si finisce in un loop"<<std::endl;
    std::list<Computer*> l;
    auto it=l.begin();
    std::string input;
    do{
      //  std::cout<<"                         //inizio"<<std::endl;
        std::cin>>input;
        if(input!="stop"){
            if(l.empty()){
              //  std::cout<<"                   //se lista vuota"<<std::endl;
                if(input=="newpc"){
                    Computer* p=new Tower;
                    l.push_back(p);
                    it++;
                }
                else if(input=="newlp"){
                    Computer* p=new Laptop;
                    l.push_back(p);
                    it++;
                }
                else if(input=="newsm"){
                    Computer* p=new Smartphone;
                    l.push_back(p);
                    it++;
                }
                else std::cerr<<"Nessuna macchina disponibile, crearla con comando newpc o newlp"<<std::endl;
            }//se nessuna macchina, l' ho creata oppure ho stampato errore

            else if(input=="newpc"){
               // std::cout<<"                        //newpc lista non vuota"<<std::endl;
                Computer* p=new Tower;
                l.push_back(p);
                it++;
            }
            else if(input=="newlp"){
             //   std::cout<<"                        //newlp lista non vuota"<<std::endl;
                Computer* p=new Laptop;
                l.push_back(p);
                it++;
            }
            else if(input=="newsm"){
                Computer* p=new Smartphone;
                l.push_back(p);
                it++;
            }

            else if(input=="goto"){
        //        std::cout<<"                        //goto"<<std::endl;
                unsigned int num;
                std::cin>>num;
                if(num<=l.size()){
                    it=l.begin();
                    for(int i=1; i<num; i++) {++it;}
                }
                else std::cerr<<"Macchina non presente"<<std::endl;
            }

            else if(input=="delmch"){
         //       std::cout<<"                       //delpc"<<std::endl;
                if(!l.empty()){
                    if(it==l.begin()){
                        delete *it; it=l.erase(it);
                    }
                    else{
                    delete *it; it=l.erase(it); it--;}
                }
                else std::cerr<<"Nessuna macchina presente"<<std::endl;
            }

            else if(input=="outmc"){
       //         std::cout<<"                    //outpc"<<std::endl;
                if(!l.empty()){
                    (*it)->Print();
                }
                else std::cerr<<"Nessuna macchina presente"<<std::endl;
            }

            else if(input=="outlist"){
     //           std::cout<<"                   //stampa lista"<<std::endl;
                if(!l.empty()){
                    for(int i=1; i<=l.size();i++){
                        std::cout<<'['<<i<<']'<<' ';
                    }
                    std::cout<<std::endl;
                }
                else std::cerr<<"Lista vuota"<<std::endl;
            }

            else if(input=="at"){
                auto it_tem = l.begin();
                int i=1;
                for(; it_tem!=it; it_tem++, i++);
                std::cout<<i<<std::endl;
            }

            else if(input=="score"){
                double score=(*it)->Score();
                std::cout<<score;
            }

            else if(input=="setprice"){
                double price;
                std::cin>>price;
                if(price>0)
                (*it)->setPrice(price);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }

            else if(input=="setcpumem"){
                double mem;
                std::cin>>mem;
                if(mem>0)
                (*it)->setMemCPU(mem);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setgpumem"){
                double mem;
                std::cin>>mem;
                if(mem>0)
                (*it)->setMemGPU(mem);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setrammem"){
                double mem;
                std::cin>>mem;
                if(mem>0)
                (*it)->setMemRAM(mem);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setmemmem"){
                double mem;
                std::cin>>mem;
                if(mem>0)
                (*it)->setMemMEM(mem);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }

            else if(input=="setcpuclock"){
                int clock;
                std::cin>>clock;
                if(clock>0)
                (*it)->setClockCPU(clock);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setgpuclock"){
                int clock;
                std::cin>>clock;
                if(clock>0)
                (*it)->setClockGPU(clock);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setramclock"){
                int clock;
                std::cin>>clock;
                if(clock>0)
                (*it)->setClockRAM(clock);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }

            else if(input=="setcpucores"){
                int cores;
                std::cin>>cores;
                if(cores>0)
                (*it)->setCoresCPU(cores);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setgpucores"){
                int cores;
                std::cin>>cores;
                if(cores>0)
                (*it)->setCoresGPU(cores);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }

            else if(input=="setgpuband"){
                int band;
                std::cin>>band;
                if(band>0)
                (*it)->setBandGPU(band);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }

            else if(input=="setgpupres"){
                bool pres;
                std::cin>>pres;
                (*it)->setGPUpresence(pres);
            }

            else if(input=="setcpuhy"){
                int hyper;
                std::cin>>hyper;
                if(hyper==1 || hyper==0)
                    (*it)->setHyperCPU(hyper);
                else std::cerr<<"set Error, inserire valore=1 oppure valore=0"<<std::endl;
            }

            else if(input=="setread"){
                int read;
                std::cin>>read;
                if(read>0)
                (*it)->setReadSpeedMEM(read);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }
            else if(input=="setwrite"){
                int write;
                std::cin>>write;
                if(write>0)
                (*it)->setWriteSpeedMEM(write);
                else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
            }


            else if(input=="setbat"){
                if(dynamic_cast<Laptop*>(*it)){
                    int bat;
                    std::cin>>bat;
                    if(bat>0)
                    (static_cast<Laptop*>(*it))->setBattery(bat);
                    else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
                }
                else std::cerr<<"Non ha la batteria"<<std::endl;
            }

            else if(input=="setres"){
                if(dynamic_cast<Laptop*>(*it)){
                    int l, h;
                    std::cout<<"inserire valore pixel larghezza"<<std::endl;
                    std::cin>>l; //with
                    std::cout<<"inserire valore pixel altezza"<<std::endl;
                    std::cin>>h; //heiht
                    if(l>0 && h>0){
                        (static_cast<Laptop*>(*it))->setResolution(l,h);
                    }
                    else std::cout<<"inseriti uno o piu' valori non validi, devono essere >0"<<std::endl;
                }
                else std::cerr<<"Non ha lo schermo"<<std::endl;
            }

            else if(input=="setdim"){
                if(dynamic_cast<Laptop*>(*it)){
                    double dim;
                    std::cin>>dim;
                    if(dim>0)
                    (static_cast<Laptop*>(*it))->setDimension(dim);
                    else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
                }
                else std::cerr<<"Non ha lo schermo"<<std::endl;
            }

            else if(input=="setweight"){
                if(dynamic_cast<Laptop*>(*it)){
                    int wgh;
                    std::cin>>wgh;
                    if(wgh>0)
                    (static_cast<Laptop*>(*it))->setWeight(wgh);
                    else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
                }
                else std::cerr<<"Il peso non conta"<<std::endl;
            }

            else if(input=="setgen"){
                if(dynamic_cast<Smartphone*>(*it)){
                    int gen;
                    std::cin>>gen;
                    if(gen>0)
                    (static_cast<Smartphone*>(*it))->setGen(gen);
                    else std::cerr<<"Errore: inserire valore >0 "<<std::endl;
                }
            }






            else if (input=="modcpumem"){
                double mem;
                std::cin>>mem;
                (*it)->modifyMemCPU(mem);
            }
            else if (input=="modgpumem"){
                double mem;
                std::cin>>mem;
                (*it)->modifyMemGPU(mem);
            }
            else if (input=="modrammem"){
                double mem;
                std::cin>>mem;
                (*it)->modifyMemMEM(mem);
            }
            else if (input=="modrammem"){
                double mem;
                std::cin>>mem;
                (*it)->modifyMemMEM(mem);
            }
            else if (input=="modmemmem"){
                double mem;
                std::cin>>mem;
                (*it)->modifyMemMEM(mem);
            }

            else if (input=="modcpuclock"){
                int clk;
                std::cin>>clk;
                (*it)->modifyClockCPU(clk);
            }
            else if (input=="modramclock"){
                int clk;
                std::cin>>clk;
                (*it)->modifyClockRAM(clk);
            }
            else if (input=="modgpuclock"){
                int clk;
                std::cin>>clk;
                (*it)->modifyClockGPU(clk);
            }

            else if (input=="modcpucores"){
                int crs;
                std::cin>>crs;
                (*it)->modifyCoresCPU(crs);
            }
            else if (input=="modgpucores"){
                int crs;
                std::cin>>crs;
                (*it)->modifyCoresGPU(crs);
            }

            else if (input=="modgpuband"){
                int bnd;
                std::cin>>bnd;
                (*it)->modifyBandGPU(bnd);
            }

            else if (input=="modwrite"){
                int wrt;
                std::cin>>wrt;
                (*it)->modifyWriteSpeedMEM(wrt);
            }
            else if (input=="modread"){
                int rd;
                std::cin>>rd;
                (*it)->modifyReadSpeedMEM(rd);
            }

            else if (input=="modprice"){
                double prc;
                std::cin>>prc;
                (*it)->modifyPrice(prc);
            }


            else if(input=="modbat"){
                if(dynamic_cast<Laptop*>(*it)){
                    int bat;
                    std::cin>>bat;
                    (static_cast<Laptop*>(*it))->modifyBattery(bat);
                }
                else std::cerr<<"Non ha la batteria"<<std::endl;
            }

            else if(input=="modweight"){
                if(dynamic_cast<Laptop*>(*it)){
                    int wgh;
                    std::cin>>wgh;
                    (static_cast<Laptop*>(*it))->modifyWeight(wgh);
                }
                else std::cerr<<"Il peso non conta"<<std::endl;
            }

            else std::cerr<<"Comando inesistente"<<std::endl;



        }
        else{         std::cout<<"                    //se stop"<<std::endl;        //se l' utente richiede lo stop del programma rilascio la memoria se la lista e' non vuota
            if(!l.empty()){
                for(it=l.begin(); it!=l.end(); ++it)
                    delete (*it);
                l.clear();
            }
        }
std::cout<<"                 //end of while"<<std::endl;

    }while(input!="stop");


}

//  implementazione terminale "pro" se avanza tempo
/*
COMANDI TERMINALE
---------------------FUNZIONALI-------------------

newpc          [aggiunge un nuovo oggetto tower, creato di default, alla lista l]
newlp          [aggiunge un nuovo oggetto laptop, creato di default, alla lista l]
newsm          [aggiunge un nuovo oggetto smartpgone, creato di default, alla lista l]
delmc          [rimuove la macchina attualmente selezionata]
goto           [sposta il programma e quindi i comandi sulla macchina 1,2,3....  prende prima in input la stringa di comando,
                poi richiede un secondo input di un intero che indica la posizione desiderata]
outmc          [(per testing)  stampa i dati della macchina corrente]
score          [stampa lo score della macchina attiva]
outlist        [stampa una rappresentazione grafica della lista]
at             [stampa numero (quindi posizione) macchina corrente

-------------------------IMPOSTA----------------------
una stringa per comando, una per valore da impostare  es: setcpumem 42

///BASE///
---PREZZO---
setprice       [imposta il prezzo della macchina corrente, accetta decimali]

---CPU---
setcpumem      [imposta memoria cache, input in KB]
setcpuclock    [imposta clockspeed cpu, input in MHz]
setcpucores    [imposta numero cores cpu, da 1 a max uns int]
setcpuhy       [boolean   =1 cpu ha hyperthreading, input 1 o 0]

---RAM---
setrammem      [imposta quantita' memoria RAM, input in KB]
setramclock    [imposta frequenza RAM, input in MHz]

---GPU---
setgpumem      [imposta quantita' DRAM, input in KB]
setgpuclock    [imposta clockspeed gpu, input in MHz]
setgpucores    [imposta numero cores gpu, da 1 a max uns int]
setgpuband     [imposta bandwith gpu, MB/s]
setgpupres     [boolean imposta la presenza o meno della gpu,  =1 gpu e' presente]

---MEM---
setmemmem      [imposta quantita' memoria secondaria (HDD, SSD), input in KB]
setread        [imposta velocita' lettura, input in MB/s]
setwrite       [imposta velocita' scrittura, input in MB/s]

///LAPTOP///
setbat        [imposta dimensione batteria in milli ampere ora]
setres        [imposta risoluzione schermo, input come  pixel*pixel]
setdim        [imposta grandezza diagonale in pollici]
setweight     [imposta il peso]

///SMARTPHONE///
setgen         [imposta generazione di connessione telefonica, es setgen 4     significa telefono 4G]

--------------------------MODIFICA----------------------
una stringa per comando, una per valore da impostare  es: modcpumem -42

---BASE---
---PREZZO---
modprice       [modifica il prezzo, input valore int = +- val]

---CPU---
modcpumem      [modifica cpu cache, input valore int = +- val  in KB]
modcpuclock    [modifica clockspeed cpu, input valore int = +- val   in MHz]
modcpucores    [modifica numero cores cpu, input valore int = +- val]

---RAM---
modrammem      [modifica quantita' memoria RAM, input valore int = +- val in KB]
modramclock    [modifica frequenza RAM, input valore int = +- val   in MHz]

---GPU---
modgpumem      [modifica quantita' DRAM, input valore int = +- val  in KB]
modgpuclock    [modifica clockspeed gpu, input valore int = +- val   in MHz]
modgpucores    [modifica numero cores gpu, input valore int = +- val]
modgpuband     [modifica bandwith gpu, input valore int = +- val  in MB/s]

---MEM---
modmemmem      [modifica quantita' memoria secondaria (HDD, SSD), input valore int = +- val  in KB]
modwrite       [modifica velocita' scrittura, input valore int = +- val    in MB/s]
modread        [modifica velocita' lettura, input valore int = +- val    in MB/s]

///LAPTOP///
modbat         [modifica dimensione batteria, input valore int = +- val]
modweight      [modifica peso, input valore int = +- val]



 */
