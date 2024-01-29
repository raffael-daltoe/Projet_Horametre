#include "Technicien.h"
#include "IhmHorametreException.h"
#include <QString>



void Technicien::setPlusValeur(int valeurTech){
    this->valeurTech = this->valeurTech.addSecs(valeurTech);
}

Technicien::Technicien(){
    this->valeurTech = QTime::fromString("00:00:00", "hh:mm:ss");         // le temps initiel
    this->v = false;
    this->file = new Fichier();
    this->sys = new Horametre();
}

Technicien::~Technicien(){
    this->sys->setTempsActive(this->getValeuTech());
    //this->file->ecrireFichier(this->getValeuTech());
    delete file;
}

void Technicien::setMinusValeur(int valeurTech){
    this->valeurTech = this->valeurTech.addSecs(valeurTech);
}

QString Technicien::getValeuTech() noexcept(false){
    if(this->valeurTech.toString() == "60:60:60"){                        // si c'est tres grand, c'est une probleme
        throw IhmHorametreException(IhmHorametreException::STRING_TROP_GD);
    }
    return this->valeurTech.toString();
}

void Technicien::setTechnicienValid(bool v){
    this->v = v;
}
bool Technicien::getTechnicienValid(){
    return this->v;
}
