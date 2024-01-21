#include "Fichier.h"
#include "IhmHorametreException.h"

#include <iostream>
#include <fstream>
#include <string>
#include <QString>

using namespace std;

void Fichier::ecrireFichier(QString tempsEcrire){
    ofstream file("temps.txt", ios::out);                 // ici va créer la variable pour le fichier
    string line = tempsEcrire.toStdString();              // ensuite, vais prendrer le temps et transformer pour string
    file << line << endl;                                 // escrire en le fichier
    file.close();
}

QString Fichier::lireFichier() noexcept(false){
    ifstream file("temps.txt", ios::in);        // ici va créer la variable pour le fichier
    if(!file.is_open()){                        // le fichier n'ai pas cree encore
        return "00:00:00";
        //throw HorametreException(HorametreException::FILE_PROBLEM);     // c'est pas possible de ouvrir le fichier
    }
    string line = "";
    getline(file, line);                // lira jusqu'a chercher un '\n'

    if( line[2] != ':' && line[5] != ':'){                              // ce n'est pas le format d'heure ou peut-être que nous n'avons pas pu ouvrir le fichier.
        throw IhmHorametreException(IhmHorametreException::FILE_PROBLEM);     // c'est pas possible de ouvrir le fichier
    }

    file.close();
    return QString::fromStdString(line);      // vais retourner le temps du fichier

}
