#ifndef CALCULETEMPS_H
#define CALCULETEMPS_H

#include <QString>
#include <QTime>

class CalculeTemps {
public :
    int differenceTemps(QTime t_initiel, QTime t_actuel);  // ici c'est pour faire la difference du temps actuel et du temps final ( Tf - Ti )

    QString calculeTemps(int tempsDiff,QString file);
};


#endif // CALCULETEMPS_H
