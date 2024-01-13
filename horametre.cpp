#include "horametre.h"
#include "ui_horametre.h"
#include "HorametreException.h"
#include <iostream>
#include <QTime>

Horametre::Horametre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Horametre)
{
    ui->setupUi(this);
    this->sys = new Systeme();
    connect(ui->curseurVertical, SIGNAL(valueChanged(int)), this, SLOT(changerAffichage()));
}

Horametre::~Horametre()
{
    delete ui;
}

void Horametre::changerAffichage(){
    if(ui->curseurVertical->value()){ // si c'est la vitesse, if( vitesse != 0 )
        QString texte = QString::number(ui->curseurVertical->value()); // change le type du temps(int) pour String
        try{
            ui->affichage->setText(texte + " Km/h");                               // l'afficher
        }
        catch(HorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
            ui->affichage->setText(e.what());
        }

        if(this->sys->getTempsInitielValid() == 0){                   // ça c'est pour definir le valeur initiel pour chaque fois que nous allons faire la subtracion du temps initiel et actuel
            this->sys->setTempsInitiel(QTime::currentTime());
            this->sys->setTempsInitielValid(true);
        }
    }
    else{                                           // si c'est le temps
        this->sys->setTempsInitielValid(false);     // vais faire la inversion du TempsInitielValid
        try{
            ui->affichage->setText(this->sys->actualiserFichier()); // si nous avons une probleme pour afficher, normalement c'est le fichier
        }
        catch(HorametreException &e){
            ui->affichage->setText(e.what());
        }
    }
}
