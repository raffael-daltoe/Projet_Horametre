#ifndef FICHIER_H
#define FICHIER_H

#include <QDialog>
#include <QSlider>
class Fichier{
public:

    void ecrireFichier(QString tempsEcrire);
    QString lireFichier() noexcept(false); // ici c'est le methode que vais lire le archive

};

#endif // FICHIER_H
