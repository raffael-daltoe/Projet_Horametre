#ifndef SYSTEME_H
#define SYSTEME_H
#include <QTime>
#include "Fichier.h"
#include "CalculeTemps.h"

class Systeme{
public:
    Systeme();
    ~Systeme();

    QTime getTempsActuel();
    void setTempsInitiel(QTime tempsInitiel);
    QTime getTempsInitiel();
    QString actualiserFichier() noexcept(false);

    void setFichierExiste(bool value);
    bool getFichierExiste();

    void setTempsActive(QString tempsActive);
    QString getTempsActive();

    void setTempsInitielValid(bool v);

    bool getTempsInitielValid();
private:
    QTime tempsInitiel;
    bool fichierExiste,tempsInitielV;
    QString tempsActive;
    Fichier *file;
    CalculeTemps *temps;
};
#endif // SYSTEME_H
