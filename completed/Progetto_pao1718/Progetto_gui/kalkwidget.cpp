#include "kalkwidget.h"
#include "ui_kalkwidget.h"
#include<math.h>
#include<cmath>

KalkWidget::KalkWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KalkWidget)
{
    ui->setupUi(this);
    it=l.begin();
    smartphoneVisibility(false);
    ui->scoreLabel->setVisible(false);
}


KalkWidget::~KalkWidget()
{
    delete ui;
}

void KalkWidget::laptopVisibility (bool b){
    ui->screeHEdit->setVisible(b);
    ui->screenWEdit->setVisible(b);
    ui->screendimEdit->setVisible(b);
    ui->screendimLabel->setVisible(b);
    ui->screenresLabel->setVisible(b);
    ui->screenLabel->setVisible(b);
    ui->SETscreenres->setVisible(b);
    ui->SETscreendim->setVisible(b);
    ui->resXlabel->setVisible(b);

    ui->batteryLabel->setVisible(b);
    ui->batteryEdit->setVisible(b);
    ui->batmahLabel->setVisible(b);
    ui->SETbattery->setVisible(b);
    ui->ADDbattery->setVisible(b);

    ui->wghEdit->setVisible(b);
    ui->wghgramsLabel->setVisible(b);
    ui->wghLabel->setVisible(b);
    ui->SETwgh->setVisible(b);
    ui->ADDwgh->setVisible(b);
}
void KalkWidget::smartphoneVisibility (bool b){
    ui->screeHEdit->setVisible(b);
    ui->screenWEdit->setVisible(b);
    ui->screendimEdit->setVisible(b);
    ui->screendimLabel->setVisible(b);
    ui->screenresLabel->setVisible(b);
    ui->screenLabel->setVisible(b);
    ui->SETscreenres->setVisible(b);
    ui->SETscreendim->setVisible(b);
    ui->resXlabel->setVisible(b);

    ui->batteryLabel->setVisible(b);
    ui->batteryEdit->setVisible(b);
    ui->batmahLabel->setVisible(b);
    ui->SETbattery->setVisible(b);
    ui->ADDbattery->setVisible(b);

    ui->wghEdit->setVisible(b);
    ui->wghgramsLabel->setVisible(b);
    ui->wghLabel->setVisible(b);
    ui->SETwgh->setVisible(b);
    ui->ADDwgh->setVisible(b);

    ui->SETbbgen->setVisible(b);
    ui->bbgenEdit->setVisible(b);
    ui->bbgenLabel->setVisible(b);
    ui->brodbandLabel->setVisible(b);
}

int KalkWidget::at() const {   //ritorna la posizione della macchina corrente
    auto it_tem = l.begin();
    int i=1;
    for(; it_tem!=it; it_tem++, i++);
    return i;
}


//--------------------------------------- SLOT FUNZIONALI ------------------------------------

void KalkWidget::on_newTW_clicked()  //newpc
{
    l.push_back(new Tower);
    it++;
    int a=at();
    ui->labelMC->setText("Macchina numero " + QString::number(a));   //mostra sempre il numerod della macchina corrente
    ui->mainText->setText((*it)->getPrint());                        //aggiorna il testo principale con i dati della macchina
    smartphoneVisibility(false);                                     //si premura di rendere non visibili le modifiche per laptop e smartphone
    ui->scoreLabel->setVisible(false);
}

void KalkWidget::on_newLP_clicked()  //newlp
{
    l.push_back(new Laptop);
    it++;
    int a=at();
    ui->labelMC->setText("Macchina numero " + QString::number(a));
    ui->mainText->setText((*it)->getPrint());
    laptopVisibility(true);
    ui->scoreLabel->setVisible(false);
}

void KalkWidget::on_newSM_clicked()  //newsm
{
    l.push_back(new Smartphone);
    it++;
    int a=at();
    ui->labelMC->setText("Macchina numero " + QString::number(a));
    ui->mainText->setText((*it)->getPrint());
    smartphoneVisibility(true);
    ui->scoreLabel->setVisible(false);
}



void KalkWidget::on_precButton_clicked()  //next
{
    ui->scoreLabel->setVisible(false);
    if(it==l.begin()) ui->errorOutput->append("Errore: non presente una macchina precedente");
    else {
        it--;
        int a=at();
        smartphoneVisibility(false);
        if(dynamic_cast<Laptop*>(*it) || dynamic_cast<Smartphone*>(*it)  ){   //controlla se si tratta di un oggetto con schermo
            if(dynamic_cast<Smartphone*>(*it)) smartphoneVisibility(true);    //se e' un telefono rende tutto visibile
            else laptopVisibility(true);                                      //se e' un laptop non rende visibile la banda
        }
        else smartphoneVisibility(false);
        ui->labelMC->setText("Macchina numero " + QString::number(a));
        ui->mainText->setText((*it)->getPrint());
    }
}

void KalkWidget::on_nextButton_clicked()  //previous
{
    ui->scoreLabel->setVisible(false);
    auto tempit=it;
    if(++tempit==l.end()){
        ui->errorOutput->append("Errore: non presente una macchina successiva");
    }
    else {
        it++;
        int a=at();
        smartphoneVisibility(false);
        if(dynamic_cast<Laptop*>(*it) || dynamic_cast<Smartphone*>(*it)  ){
            if(dynamic_cast<Smartphone*>(*it)) smartphoneVisibility(true);
            else laptopVisibility(true);
        }
        else smartphoneVisibility(false);
        ui->labelMC->setText("Macchina numero " + QString::number(a));
        ui->mainText->setText((*it)->getPrint());
    }
}

void KalkWidget::on_removeButton_clicked()   //delmch
{
    ui->scoreLabel->setVisible(false);
    if(!l.empty()){
        if(it==l.begin()) {delete *it; it=l.erase(it); it=l.begin();}   //se sono all' inzio elimino e poi torno al "nuovo" inizio
        else              {delete *it; it=l.erase(it); it--;}           //se sono non al primo nodo elimino e arretro di uno

        int a=at();
        smartphoneVisibility(false);
        if(dynamic_cast<Laptop*>(*it) || dynamic_cast<Smartphone*>(*it)  ){
            if(dynamic_cast<Smartphone*>(*it)) smartphoneVisibility(true);
            else laptopVisibility(true);
        }
        ui->labelMC->setText("Macchina numero " + QString::number(a));
        if(l.empty()){
            ui->labelMC->setText("Nessuna macchina disponibile");
            ui->mainText->setText("");
        }
        else ui->mainText->setText((*it)->getPrint()); //NON VA DEREFERENZIATO SE IT E' PRE THE BEGIN
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

// ----------------------------------------- SLOT DI MODIFICA DEGLI OGGETTI -------------------------------------------

void KalkWidget::on_scoreButton_clicked()
{
    ui->scoreLabel->setVisible(true);
    if(!l.empty()){
        double score=(*it)->Score();
        if(!std::isnan(score) && !std::isinf(score)){
        QString s= QString::number(score);
        ui->scoreLabel->setText("Score= "+s);
        }
        else ui->errorOutput->append("Errore: richiedere lo score solo dopo aver impostato tutti i dati della macchina");
    }
    else{
        ui->errorOutput->append("Errore: nessuna macchina presente");
    }
}

void KalkWidget::on_SETprice_clicked()
{
    if(!l.empty()){
        QString s= ui->priceEdit->text();
        double price= s.toDouble();
        if(price>0.0){
            (*it)->setPrice(price);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire prezzo >0");
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");

}

void KalkWidget::on_SETcpumem_clicked()
{
    if(!l.empty()){
        QString s= ui->cpumemEdit->text();
        double mem= s.toDouble();
        if(mem>0){
            (*it)->setMemCPU(mem);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire quantita' cache >0");
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETcpucores_clicked()
{
    if(!l.empty()){
        QString s= ui->cpucoresEdit->text();
        int cores= s.toInt();
        if(cores>0){
            (*it)->setCoresCPU(cores);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire numero cores >0");
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

/*
   if(!l.empty()){
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
    */

void KalkWidget::on_SETcpuclock_clicked()
{
    if(!l.empty()){
        QString s=ui->cpuclockEdit->text();
        int clock= s.toInt();
        if(clock>0){
            (*it)->setClockCPU(clock);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire clockspeed >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETgpumem_clicked()
{
    if(!l.empty()){
        QString s=ui->gpumemEdit->text();
        double mem= s.toDouble();
        if(mem>0){
            (*it)->setMemGPU(mem);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire quantita' di memoria >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETgpucores_clicked()
{
    if(!l.empty()){
        QString s=ui->gpucoresEdit->text();
        int cores= s.toInt();
        if(cores>0){
            (*it)->setCoresGPU(cores);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire numero cores >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETgpuclock_clicked()
{
    if(!l.empty()){
        QString s=ui->gpuclockEdit->text();
        int clock= s.toInt();
        if(clock>0){
            (*it)->setClockGPU(clock);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire clockspeed >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETgpuband_clicked()
{
    if(!l.empty()){
        QString s=ui->gpubandEdit->text();
        int band= s.toInt();
        if(band>0){
            (*it)->setBandGPU(band);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire bandwith >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETrammem_clicked()
{
    if(!l.empty()){
        QString s=ui->rammemEdit->text();
        double mem= s.toDouble();
        if(mem>0){
            (*it)->setMemRAM(mem);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire quantita' di memoria >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETramclock_clicked()
{
    if(!l.empty()){
        QString s=ui->ramclockEdit->text();
        int clock= s.toInt();
        if(clock>0){
            (*it)->setClockRAM(clock);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire clockspeed >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETmemmem_clicked()
{
    if(!l.empty()){
        QString s=ui->memmemEdit->text();
        double mem= s.toDouble();
        if(mem>0){
            (*it)->setMemMEM(mem);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire quantita' di memoria >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETmemwrite_clicked()
{
    if(!l.empty()){
        QString s=ui->memwriteEdit->text();
        int write= s.toInt();
        if(write>0){
            (*it)->setWriteSpeedMEM(write);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire velocita' di scrittura >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETmemread_clicked()
{
    if(!l.empty()){
        QString s=ui->memreadEdit->text();
        int read= s.toInt();
        if(read>0){
            (*it)->setReadSpeedMEM(read);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire velocita' di lettura >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETscreenres_clicked()
{
    if(!l.empty()){
        QString W=ui->screenWEdit->text();  //risoluzione orizzontale
        QString H=ui->screeHEdit->text();   //risoluzione verticale
        int resW=W.toInt();
        int resH=H.toInt();
        if(resW>0 && resH>0){
            (dynamic_cast<Laptop*>(*it))->setResolution(resW,resH);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire risoluzione orizzontale e verticale >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETscreendim_clicked()
{
    if(!l.empty()){
        QString s=ui->screendimEdit->text();
        double dim= s.toDouble();
        if(dim>0){
            (dynamic_cast<Laptop*>(*it))->setDimension(dim);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire dimensione schermo >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETwgh_clicked()
{
    if(!l.empty()){
        QString s=ui->wghEdit->text();
        int weight= s.toInt();
        if(weight>0){
            (dynamic_cast<Laptop*>(*it))->setWeight(weight);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire peso >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETbattery_clicked()
{
    if(!l.empty()){
        QString s=ui->batteryEdit->text();
        int bat= s.toInt();
        if(bat>0){
            (dynamic_cast<Laptop*>(*it))->setBattery(bat);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire capacita' batteria >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_SETbbgen_clicked()
{
    if(!l.empty()){
        QString s=ui->bbgenEdit->text();
        int bb= s.toInt();
        if(bb>0){
            (dynamic_cast<Smartphone*>(*it))->setGen(bb);
            ui->mainText->setText((*it)->getPrint());
        }
        else ui->errorOutput->append("Errore: inserire generazione telefonica >0");
     }
     else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDpriceButton_clicked()
{
    if(!l.empty()){
        QString s= ui->priceEdit->text();
        double price= s.toDouble();
        if((*it)->getPrice()+price <=0) {
            ui->errorOutput->append("Errore: valore inserito rende il prezzo <=0");
        }
        else {
            (*it)->modifyPrice(price);
            ui->mainText->setText((*it)->getPrint());
        }
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDcpumem_clicked()
{
    if(!l.empty()){
        QString s= ui->cpumemEdit->text();
        double mem= s.toDouble();
        QString result= (*it)->modifyMemCPU(mem);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDcpucores_clicked()
{
    if(!l.empty()){
        QString s= ui->cpucoresEdit->text();
        int cores= s.toInt();
        QString result= (*it)->modifyCoresCPU(cores);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDcpuclock_clicked()
{
    if(!l.empty()){
        QString s= ui->cpuclockEdit->text();
        int clock= s.toInt();
        QString result= (*it)->modifyClockCPU(clock);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDgpumem_clicked()
{
    if(!l.empty()){
        QString s= ui->gpumemEdit->text();
        double mem= s.toDouble();
        QString result= (*it)->modifyMemGPU(mem);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDgpucores_clicked()
{
    if(!l.empty()){
        QString s= ui->gpucoresEdit->text();
        int cores= s.toInt();
        QString result= (*it)->modifyCoresGPU(cores);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDgpuclock_clicked()
{
    if(!l.empty()){
        QString s= ui->gpuclockEdit->text();
        double clock= s.toInt();
        QString result= (*it)->modifyClockGPU(clock);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDgpuband_clicked()
{
    if(!l.empty()){
        QString s= ui->gpubandEdit->text();
        int band= s.toInt();
        QString result= (*it)->modifyBandGPU(band);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDrammem_clicked()
{
    if(!l.empty()){
        QString s= ui->rammemEdit->text();
        double mem= s.toDouble();
        QString result= (*it)->modifyMemRAM(mem);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDramclock_clicked()
{
    if(!l.empty()){
        QString s= ui->ramclockEdit->text();
        int clock= s.toInt();
        QString result= (*it)->modifyClockRAM(clock);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDmemmem_clicked()
{
    if(!l.empty()){
        QString s= ui->memmemEdit->text();
        double mem= s.toDouble();
        QString result= (*it)->modifyMemMEM(mem);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDwrite_clicked()
{
    if(!l.empty()){
        QString s= ui->memwriteEdit->text();
        int write= s.toInt();
        QString result= (*it)->modifyWriteSpeedMEM(write);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDread_clicked()
{
    if(!l.empty()){
        QString s= ui->memreadEdit->text();
        int read= s.toInt();
        QString result= (*it)->modifyReadSpeedMEM(read);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDwgh_clicked()
{
    if(!l.empty()){
        QString s= ui->wghEdit->text();
        int wgh= s.toInt();
        QString result= (dynamic_cast<Laptop*>(*it))->modifyWeight(wgh);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_ADDbattery_clicked()
{
    if(!l.empty()){
        QString s= ui->batteryEdit->text();
        int bat= s.toInt();
        QString result= (dynamic_cast<Laptop*>(*it))->modifyBattery(bat);
        ui->mainText->setText((*it)->getPrint());
        if(result!="0") ui->errorOutput->append(result);
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_hyperYesButton_clicked()
{
    if(!l.empty()){
        (*it)->setHyperCPU(true);
        ui->mainText->setText((*it)->getPrint());
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_hyperNoButton_clicked()
{
    if(!l.empty()){
        (*it)->setHyperCPU(false);
        ui->mainText->setText((*it)->getPrint());
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_gpupresYesButton_clicked()
{
    if(!l.empty()){
        (*it)->setGPUpresence(true);
        ui->mainText->setText((*it)->getPrint());
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}

void KalkWidget::on_gpupresNoButton_clicked()
{
    if(!l.empty()){
        (*it)->setGPUpresence(false);
        ui->mainText->setText((*it)->getPrint());
    }
    else ui->errorOutput->append("Errore: nessuna macchina presente");
}
