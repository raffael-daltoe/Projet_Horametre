#include "IhmHorametreException.h"
#include <QString>

IhmHorametreException::IhmHorametreException(Raison cs) noexcept{
    this->cause = cs;
}

const char* IhmHorametreException::what() const noexcept{
    char *raison = nullptr;

    switch(this->cause){
    case FILE_PROBLEM:
        raison = QString("Fichier avec probleme\n").toLocal8Bit().data();
        break;
    case STRING_TROP_GD:
        raison=QString("Dépassement de la capacité d'affichage\n").toLocal8Bit().data();
        break;
    case NB_NEGATIF:
        raison=QString("Numero negatif\n").toLocal8Bit().data();
        break;
    }
    return raison;
}
