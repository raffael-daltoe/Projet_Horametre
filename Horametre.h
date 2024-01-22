#ifndef HORAMETRE_H
#define HORAMETRE_H

#include <QTime>
#include "Fichier.h"
#include "CalculeTemps.h"
class Horametre{
public:
    Horametre();
    ~Horametre();

    QTime getTempsActuel();
    void setTempsInitiel(QTime tempsInitiel);
    QTime getTempsInitiel();
    QString actualiserFichier(QString value,QString valueTech) noexcept(false);

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
#endif // Horametre_H
