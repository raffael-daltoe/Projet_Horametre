#include "Horametre.h"
#include "IhmHorametreException.h"
#include <fstream>
#include <QString>

Horametre::Horametre(){
    this->fichierExiste = false;                    // si le fichier existe
    this->tempsInitielV = false;                    // si le temps initiel c'est valide, c'est quand le moteur demarre
    this->tempsInitiel = QTime::fromString("00:00:00", "hh:mm:ss");         // le temps initiel
    this->tempsActive = "00:00:00";                     // le temps que le moteur a ete active
    this->file = new Fichier();
    this->temps = new CalculeTemps();
}

Horametre::~Horametre(){
    delete file;
    delete temps;
}

QTime Horametre::getTempsActuel(){
    return QTime::currentTime();
}

void Horametre::setTempsInitiel(QTime tempsInitiel){
    this->tempsInitiel = tempsInitiel;
}

QTime Horametre::getTempsInitiel(){
    return this->tempsInitiel;
}

void Horametre::setTempsInitielValid(bool v){
    this->tempsInitielV = v;
}

bool Horametre::getTempsInitielValid(){
    return this->tempsInitielV;
}

void Horametre::setFichierExiste(bool value){
    this->fichierExiste = value;
}

bool Horametre::getFichierExiste(){
    return this->fichierExiste;
}

void Horametre::setTempsActive(QString tempsActive){
    this->tempsActive = tempsActive;
}

QString Horametre::getTempsActive(){
    return this->tempsActive;
}

QString Horametre::actualiserFichier(QString value,QString valueTech)noexcept(false){                 // mettre à jour la valeur du temps dans le fichier
    if ( value == "Curseur" ){
        int difference = this->temps->differenceTemps(this->getTempsInitiel(),this->getTempsActuel());   // faire la difference de temps
        QString valeur_fichier = this->file->lireFichier();
        this->setTempsActive(this->temps->calculeTemps(difference,valeur_fichier));        // vais fair la somme du temps de le fichier avec la difference des temps
        this->file->ecrireFichier(this->getTempsActive());                    // vais ecrire en le fichier
        if(sizeof(this->getTempsActive()) > 10){                        // si c'est tres grand, c'est une probleme
            throw IhmHorametreException(IhmHorametreException::STRING_TROP_GD);
        }
    }else{
        this->setTempsActive(valueTech);
        this->file->ecrireFichier(valueTech);
    }
    return this->getTempsActive();
}
