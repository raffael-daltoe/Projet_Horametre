#ifndef SYSTEME_H
#define SYSTEME_H
#include <QTime>

class Systeme{
public:
    Systeme();
    ~Systeme();

    QTime getTempsActuel();
    void setTempsInitiel(QTime tempsInitiel);
    QTime getTempsInitiel();

    QString lireFichier() noexcept(false); // ici c'est le methode que vais lire le archive
    void ecrireFichier(QString tempsEcrire);
    int differenceTemps(); // ici c'est pour faire la difference du temps actuel et du temps final ( Tf - Ti )
    QString actualiserFichier() noexcept(false);

    void setFichierExiste(bool value);
    bool getFichierExiste();

    void setTempsActive(QString tempsActive);
    QString getTempsActive();
    void calculeTemps(int tempsDiff);

    void setTempsInitielValid(bool v);

    bool getTempsInitielValid();
private:
    QTime tempsInitiel;
    bool fichierExiste,tempsInitielV;
    QString tempsActive;
};
#endif // SYSTEME_H
