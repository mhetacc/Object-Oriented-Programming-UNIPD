#include "kalkwidget.h"
#include <QApplication>
#include"computer.h"
#include"inputterminal.h"
#include"list"

#include<iostream>
#include<math.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KalkWidget w;
    w.show();

    return a.exec();
}


/*modalita' con terminale beta volendo provarla, e' stato usato inputterminal per testare il programma prima della realizzazione della gui
 * In inputterminal.cpp si trova, in fondo, la lista dei comandi.
 * E' stato necessario apportare alcune modifiche, nello specifico la prima versione del codice gestiva gli errori "back end"
 * e li stampava su std::cerr
 * Ovviamente ora non e' piu' utile in quanto si usa una finestra della gui dedicata per i messaggi di errore e, per i set, si
 * occupa direttamente kalkwidget.cpp del controllo sui valori inseriti dall' input.
*/

/*
int main() {
    inputTerminal();
}
*/
