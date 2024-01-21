#ifndef IHMHORAMETRE_H
#define IHMHORAMETRE_H

#include <QDialog>
#include <QSlider>
#include <QWidget>
#include "Horametre.h"
#include "Technicien.h"
QT_BEGIN_NAMESPACE
namespace Ui { class IhmHorametre; }
QT_END_NAMESPACE

class IhmHorametre : public QDialog
{
    Q_OBJECT

public:
    IhmHorametre(QWidget *parent = nullptr);
    ~IhmHorametre();
private:
    Ui::IhmHorametre *ui;
    Technicien *tech;
    Horametre *sys;
private slots:
    void plusButton();
    void minusButton();
    void ativerTech();
    void changerAffichage();
};
#endif // HORAMETRE_H
