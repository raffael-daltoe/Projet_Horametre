#include "IhmHorametre.h"
#include "ui_IhmHorametre.h"

#include "IhmHorametreException.h"
#include <iostream>
#include <QTime>

IhmHorametre::IhmHorametre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IhmHorametre)
{
    ui->setupUi(this);
    this->sys = new Horametre();
    this->tech = new Technicien();
    connect(ui->curseurVertical, SIGNAL(valueChanged(int)), this, SLOT(changerAffichage()));

    connect(ui->plusButtonTech, SIGNAL(clicked()), this, SLOT(plusButton()));
    connect(ui->minusButtonTech, SIGNAL(clicked()), this, SLOT(minusButton()));
    connect(ui->ativerTech, SIGNAL(clicked()), this, SLOT(ativerTech()));

    QPixmap image("ship.jpg"); // Carregar a imagem
    QGraphicsScene *scene = new QGraphicsScene(this); // Criar uma nova cena
    scene->addPixmap(image); // Adicionar a imagem à cena
    ui->graphicsView->setScene(scene); // Configurar a cena no QGraphicsView

}

IhmHorametre::~IhmHorametre()
{
    delete ui;
    //delete sys;
    delete tech;
}

void IhmHorametre::plusButton(){
    if(this->tech->getTechnicienValid() != 0){
        this->tech->setPlusValeur(this->tech->getValeuTech()+1);
        ui->timeTech->setText(QString::number(this->tech->getValeuTech()));
    }
    //while()
    /*this->tech->setPlusValeur(this->tech->getValeur().toInt()+1);
    try{
        ui->timeTech->setText(this->tech->getValeur());
    }
    catch(IhmHorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
        ui->timeTech->setText(e.what());
    }*/
}

void IhmHorametre::minusButton(){
    if(this->tech->getTechnicienValid()!=0){
        this->tech->setMinusValeur(this->tech->getValeuTech()-1);
        ui->timeTech->setText(QString::number((this->tech->getValeuTech())));
    }
    /*this->tech->setMinusValeur(this->tech->getValeur().toInt()-1);
    try{
        ui->timeTech->setText(this->tech->minusValeur());
    }
    catch(IhmHorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
        ui->timeTech->setText(e.what());
    }*/
}

void IhmHorametre::ativerTech(){
    this->tech->setTechnicienValid(!this->tech->getTechnicienValid());
    //ui->ativerTech(this->tech->getTechnicienValid());
    }

void IhmHorametre::changerAffichage(){
    if(ui->curseurVertical->value()){ // si c'est la vitesse, if( vitesse != 0 )
        /*QString texte = QString::number(ui->curseurVertical->value()); // change le type du temps(int) pour String
        try{
            ui->affichage->setText(texte + " Km/h");                               // l'afficher
        }
        catch(HorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
            ui->affichage->setText(e.what());
        }
*/
        QString texte = QString::number(ui->curseurVertical->value()); // change le type du temps(int) pour String
        ui->affichage->setText(texte + " Km/h");
        if(this->sys->getTempsInitielValid() == 0){                   // ça c'est pour definir le valeur initiel pour chaque fois que nous allons faire la subtracion du temps initiel et actuel
            this->sys->setTempsInitiel(QTime::currentTime());
            this->sys->setTempsInitielValid(true);
        }
    }
    else{                                           // si c'est le temps
        this->sys->setTempsInitielValid(false);     // vais faire la inversion du TempsInitielValid
        ui->affichage->setText(this->sys->actualiserFichier()); // si nous avons une probleme pour afficher, normalement c'est le fichier



        /*
        try{
            ui->affichage->setText(this->sys->actualiserFichier()); // si nous avons une probleme pour afficher, normalement c'est le fichier
        }
        catch(HorametreException &e){
            ui->affichage->setText(e.what());
        }*/
    }
}
