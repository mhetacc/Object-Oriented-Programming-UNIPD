//#include"basecomponent.h"
//#include"centralprocessingunit.h"
//#include"graphicsprocessingunit.h"
//#include"randomaccessmemory.h"
//#include"secondarymemory.h"
#include"computer.h"
#include"inputterminal.h"
#include"list"

#include<iostream>
#include<math.h>
using namespace std;

// CentralProcessingUnit(unsigned int c=0, unsigned int mem=0, unsigned int num=1, bool b=false)

// LA MEMORIA VA INSERITA CON QUALCOSA DI PIU' GRANDE DI UNS INT MAX MEM = 4GB
int main () {
    /*

std::cout<<"press 0 to end"<<std::endl<<std::endl;
std::cout<<"1 set cpu cores"<<std::endl<<"2 set cpu cache"<<std::endl<<"3 set cpu clock"<<std::endl<<"4 set cpu hyperthread"<<std::endl<<std::endl;
std::cout<<"5 set gpu cores"<<std::endl<<"6 set gpu dram"<<std::endl<<"7 set gpu bandwith"<<std::endl<<"8 set gpu clock"<<std::endl<<"9 set gpu presence"<<std::endl<<std::endl;
std::cout<<"10 set ram clock"<<std::endl<<"11 set ram dimension"<<std::endl<<std::endl;
std::cout<<"12 set mem write speed"<<std::endl<<"13 set mem read speed"<<std::endl<<"14 set mem dimension"<<std::endl<<std::endl;
std::cout<<"15 set price"<<std::endl;
int command;
unsigned int valUI;
bool valB;
double valD;
do {
    std::cin>>command;
    Computer *c=new Tower;
    switch(command){
    case 0 : {delete c; break;}
    case 1 : {std::cout<<"how many cores?"<<std::endl; std::cin>>valUI; c->setCoresCPU(valUI);}
    }

}while(command !=0);
*/

/*
BaseComponent b(10,10);
cout<<b<<endl;
BaseComponent b2;
cout<<b2<<endl;
b2.setClock(45);
b2.setMemory(99);
cout<<b2;

    CentralProcessingUnit c;
    CentralProcessingUnit c2 (10, 20, 6, true);
    cout<<c<<endl<<c2<<endl;
    c2.setClock(100);
    c2.setHyperT(false);
    c2.setMemory(200);
    c2.setCores(9);
    cout<<c2;
    c2.setCores(0);
    cout<<endl<<c2<<endl;


GraphicProcessingUnit c;
GraphicProcessingUnit c2 (10, 20, 3000, 3000, true);
cout<<c<<endl<<c2<<endl;
c2.setBand(289);
c2.setClock(99);
c2.setCores(3);
c2.setMemory(20000);
cout<<c2;

RandomAccessMemory r;
RandomAccessMemory r2(99, 88);
cout<<r<<endl<<r2<<endl;
r2.setClock(800);
r2.setMemory(777);
cout<<r2<<endl;


    SecondaryMemory s;
    SecondaryMemory s2(12, 18, 24, 39);
    cout<<s<<endl<<s2<<endl;
    s2.setClock(33);
    s2.setMemory(5000000);
    s2.setRead(55);
    s2.setWrite(978);
    cout<<s2;

*/
    //testare classe Computer
   /* Computer c;
    cout<<c<<endl;
    c.setClockCPU(5000);
    c.setClockRAM(3000);
    c.setCoresGPU(55);
    cout<<c;
    std::cout<<std::endl<<std::endl;*/
    /*
std::list<Computer*>l;
auto it=l.begin();
Computer* p=new Computer;
l.push_back(p);it++;
cout<<*p;
   std::cout<<std::endl<<std::endl;
cout<<**it;*/
inputTerminal();

}

