#ifndef HORAMETRE_H
#define HORAMETRE_H

#include <QDialog>
#include <QSlider>
#include "Systeme.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Horametre; }
QT_END_NAMESPACE

class Horametre : public QDialog
{
    Q_OBJECT

public:
    Horametre(QWidget *parent = nullptr);
    ~Horametre();
private:
    Ui::Horametre *ui;
    Systeme *sys;
private slots:

    void changerAffichage();
};
#endif // HORAMETRE_H
