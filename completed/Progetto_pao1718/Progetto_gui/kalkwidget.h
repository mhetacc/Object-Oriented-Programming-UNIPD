#ifndef KALKWIDGET_H
#define KALKWIDGET_H
#include"smartphone.h"
#include <QMainWindow>

namespace Ui {
class KalkWidget;
}

class KalkWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit KalkWidget(QWidget *parent = 0);
    ~KalkWidget();

private slots:
    void on_newTW_clicked();  //bottone nuova Tower

    void on_newLP_clicked();

    void on_newSM_clicked();

    void on_precButton_clicked();

    void on_nextButton_clicked();

    void on_removeButton_clicked();

    void on_scoreButton_clicked();

    void on_SETprice_clicked();

    void on_SETcpumem_clicked();

    void on_SETcpucores_clicked();

    void on_SETcpuclock_clicked();

    void on_SETgpumem_clicked();

    void on_SETgpucores_clicked();

    void on_SETgpuclock_clicked();

    void on_SETgpuband_clicked();

    void on_SETrammem_clicked();

    void on_SETramclock_clicked();

    void on_SETmemmem_clicked();

    void on_SETmemwrite_clicked();

    void on_SETmemread_clicked();

    void on_SETscreenres_clicked();

    void on_SETscreendim_clicked();

    void on_SETwgh_clicked();

    void on_SETbattery_clicked();

    void on_SETbbgen_clicked();

    void on_ADDpriceButton_clicked();

    void on_ADDcpumem_clicked();

    void on_ADDcpucores_clicked();

    void on_ADDcpuclock_clicked();

    void on_ADDgpumem_clicked();

    void on_ADDgpucores_clicked();

    void on_ADDgpuclock_clicked();

    void on_ADDgpuband_clicked();

    void on_ADDrammem_clicked();

    void on_ADDramclock_clicked();

    void on_ADDmemmem_clicked();

    void on_ADDwrite_clicked();

    void on_ADDread_clicked();

    void on_ADDwgh_clicked();

    void on_ADDbattery_clicked();

    void on_hyperYesButton_clicked();

    void on_hyperNoButton_clicked();

    void on_gpupresYesButton_clicked();

    void on_gpupresNoButton_clicked();

private:
    Ui::KalkWidget *ui;
    std::list<Computer*> l;
    std::list<Computer*>::iterator it;
    int at() const;
    void laptopVisibility (bool);
    void smartphoneVisibility (bool);

};

#endif // KALKWIDGET_H
