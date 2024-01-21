#include "CalculeTemps.h"
#include <QTime>
#include <QString>

int CalculeTemps::differenceTemps(QTime t_initiel, QTime t_actuel){
    int msecsDifference = t_initiel.msecsTo(t_actuel);   // retour la difference en microsseconde de la difference du temps actuel et initiel
    return msecsDifference;
}

QString CalculeTemps::calculeTemps(int tempsDiff,QString file){
    QTime tempsFichier = QTime::fromString(file);        // prender le valeur du fichier et transformer pour QTime

    QTime tempsActiveFinale = tempsFichier.addMSecs(tempsDiff);         // vais faire la somme des microsecondes avec le temps du fichier

    return tempsActiveFinale.toString();              // transformation pour QString
}
