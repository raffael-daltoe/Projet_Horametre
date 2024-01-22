#include "IhmHorametre.h"
#include "ui_IhmHorametre.h"
#include "IhmHorametreException.h"
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
    delete sys;
    delete tech;
}

void IhmHorametre::plusButton(){
    if(this->tech->getTechnicienValid() == 1){
        this->tech->setPlusValeur(5);
        try{
            ui->timeTech->setText(this->tech->getValeuTech());
        }
        catch(IhmHorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
            ui->timeTech->setText(e.what());
        }
    }
}

void IhmHorametre::minusButton(){
    if(this->tech->getTechnicienValid() == 1 && this->tech->getValeuTech()>="00:00:05"){
        this->tech->setPlusValeur(-5);
        try{
            ui->timeTech->setText(this->tech->getValeuTech());
        }
        catch(IhmHorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
            ui->timeTech->setText(e.what());
        }
    }
}

void IhmHorametre::ativerTech(){
    this->tech->setTechnicienValid(!this->tech->getTechnicienValid());

    if(this->tech->getTechnicienValid()==1){
        ui->timeTech->setText("Inserer un valeur s'il vous plaît");
    }
    else{
        ui->timeTech->setText("");
        try{
            ui->affichage->setText(this->sys->actualiserFichier("Technicien",this->tech->getValeuTech())); // si nous avons une probleme pour afficher, normalement c'est le fichier
        }
        catch(IhmHorametreException &e){
            ui->affichage->setText(e.what());
        }
    }
    ui->curseurVertical->setSliderPosition(0);
    ui->curseurVertical->setValue(0);
    ui->curseurVertical->setDisabled(this->tech->getTechnicienValid());
}

void IhmHorametre::changerAffichage(){
    if(ui->curseurVertical->value()){ // si c'est la vitesse, if( vitesse != 0 )
        QString texte = QString::number(ui->curseurVertical->value()); // change le type du temps(int) pour String
        try{
            ui->affichage->setText(texte + " Km/h");                               // l'afficher
        }
        catch(IhmHorametreException &e){                           // il y a une probleme de affichage, le taille de la string c'est grand
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
            ui->affichage->setText(this->sys->actualiserFichier("Curseur","0")); // si nous avons une probleme pour afficher, normalement c'est le fichier
        }
        catch(IhmHorametreException &e){
            ui->affichage->setText(e.what());
        }
    }
}
