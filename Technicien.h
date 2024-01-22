#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <QTime>

#include "Fichier.h"
#include "Horametre.h"

class Horametre;
class Technicien{
private:
    QTime valeurTech;
    bool v;
    Fichier *file;
    Horametre *sys;
public:
    void setPlusValeur(int valeurTech);
    void setMinusValeur(int valeurTech);

    void setTechnicienValid(bool v);
    bool getTechnicienValid();

    QString getValeuTech() noexcept(false);
    Technicien();
    ~Technicien();
};

#endif // TECHNICIEN_H
