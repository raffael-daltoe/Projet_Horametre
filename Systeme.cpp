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
}


Systeme::~Systeme(){

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

void Systeme::ecrireFichier(QString tempsEcrire){
    ofstream file("temps.txt", ios::out);                 // ici va créer la variable pour le fichier
    string line = tempsEcrire.toStdString();              // ensuite, vais prendrer le temps et transformer pour string
    file << line << endl;                                 // escrire en le fichier
    file.close();
}

QString Systeme::lireFichier() noexcept(false){
    ifstream file("temps.txt", ios::in);        // ici va créer la variable pour le fichier
    if(!file.is_open()){                        // le fichier n'ai pas cree encore
        return "00:00:00";
        //throw HorametreException(HorametreException::FILE_PROBLEM);     // c'est pas possible de ouvrir le fichier
    }
    string line = "";
    getline(file, line);                // lira jusqu'a chercher un '\n'

    if( line[2] != ':' && line[5] != ':'){                              // ce n'est pas le format d'heure ou peut-être que nous n'avons pas pu ouvrir le fichier.
        throw HorametreException(HorametreException::FILE_PROBLEM);     // c'est pas possible de ouvrir le fichier
    }

    file.close();
    return QString::fromStdString(line);      // vais retourner le temps du fichier

}


int Systeme::differenceTemps(){
    QTime temps_Initiel = this->getTempsInitiel();         // c'est le temps du fichier, le premier temps
    QTime temps_Actuel  = this->getTempsActuel();          // c'est le temps actuel

    int msecsDifference = temps_Initiel.msecsTo(temps_Actuel);   // retour la difference en microsseconde de la difference du temps actuel et initiel
    return msecsDifference;
}

void Systeme::calculeTemps(int tempsDiff){
    QTime tempsFichier = QTime::fromString(this->lireFichier());        // prender le valeur tu fichier et transformer pour QTime

    QTime tempsActiveFinale = tempsFichier.addMSecs(tempsDiff);         // vais faire la somme des microsecondes avec le temps du fichier

    QString tempsActiveFin = tempsActiveFinale.toString();              // transformation pour QString

    this->setTempsActive(tempsActiveFin);                               // Ecrire en le attribute
}

QString Systeme::actualiserFichier()noexcept(false){                 // mettre à jour la valeur du temps dans le fichier
    int difference = this->differenceTemps();                       // faire la difference de temps
    this->calculeTemps(difference);                                 // vais fair la somme du temps de le fichier avec la difference des temps
    this->ecrireFichier(this->getTempsActive());                    // vais ecrire en le fichier
    if(sizeof(this->getTempsActive()) > 10){                        // si c'est tres grand, c'est une probleme
        throw HorametreException(HorametreException::STRING_TROP_GD);
    }
    return this->getTempsActive();

}
