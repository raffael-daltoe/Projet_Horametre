#include "Systeme.h"
#include "HorametreException.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QString>

using namespace std;


Systeme::Systeme(){
    this->fichierExiste = false;                    // si le fichier existe
    this->tempsInitielV = false;                    // si le temps initiel c'est valide, c'est quand le moteur demarre
    this->tempsInitiel = QTime::fromString("00:00:00", "hh:mm:ss");         // le temps initiel
    this->tempsActive = "00:00:00";                     // le temps que le moteur a ete active
    file = new Fichier();
    temps = new CalculeTemps();
}


Systeme::~Systeme(){
    delete file;
    delete temps;
}

QTime Systeme::getTempsActuel(){
    return QTime::currentTime();
}

void Systeme::setTempsInitiel(QTime tempsInitiel){
    this->tempsInitiel = tempsInitiel;
}

QTime Systeme::getTempsInitiel(){
    return this->tempsInitiel;
}

void Systeme::setTempsInitielValid(bool v){
    this->tempsInitielV = v;
}

bool Systeme::getTempsInitielValid(){
    return this->tempsInitielV;
}

void Systeme::setFichierExiste(bool value){
    this->fichierExiste = value;
}

bool Systeme::getFichierExiste(){
    return this->fichierExiste;
}

void Systeme::setTempsActive(QString tempsActive){
    this->tempsActive = tempsActive;
}

QString Systeme::getTempsActive(){
    return this->tempsActive;
}

QString Systeme::actualiserFichier()noexcept(false){                 // mettre à jour la valeur du temps dans le fichier
    int difference = this->temps->differenceTemps(this->getTempsInitiel(),this->getTempsActuel());   // faire la difference de temps
    QString valeur_fichier = this->file->lireFichier();
    this->setTempsActive(this->temps->calculeTemps(difference,valeur_fichier));        // vais fair la somme du temps de le fichier avec la difference des temps
    this->file->ecrireFichier(this->getTempsActive());                    // vais ecrire en le fichier
    if(sizeof(this->getTempsActive()) > 10){                        // si c'est tres grand, c'est une probleme
        throw HorametreException(HorametreException::STRING_TROP_GD);
    }
    return this->getTempsActive();
}
