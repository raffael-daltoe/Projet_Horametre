#include "Technicien.h"
#include "IhmHorametreException.h"
#include <QString>


void Technicien::setPlusValeur(int valeurTech){
    this->valeurTech = valeurTech;
}

void Technicien::setMinusValeur(int valeurTech){
    this->valeurTech = valeurTech;
}

int Technicien::getValeuTech(){
    return this->valeurTech;
}

void Technicien::setTechnicienValid(bool v){
    this->v = v;
}
bool Technicien::getTechnicienValid(){
    return this->v;
}
