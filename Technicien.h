#ifndef TECHNICIEN_H
#define TECHNICIEN_H


class Technicien{
private:
    int valeurTech;
    bool v;
public:
    void setPlusValeur(int valeurTech);
    void setMinusValeur(int valeurTech);

    void setTechnicienValid(bool v);
    bool getTechnicienValid();

    int getValeuTech();
    /*
    1) ativa botão de inicialização
    2) adiciona o tempo
    3) e após isso tu reinicia o tempo no arquivo
    4) tudo isso sem velocidade, motor desligado, se estiver ligado, o motor desliga para fazer o procedimento ( chamada do tecnico, turn on)
    5) desliga o técnico, salva na memoria
 */
};

#endif // TECHNICIEN_H
