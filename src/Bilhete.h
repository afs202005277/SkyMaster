//
// Created by Pedro Fonseca on 13/12/2021.
//

#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

class Bilhete
{
private:
    bool checkInAuto;
    unsigned int numMalas, nVoo;
public:
    Bilhete(unsigned int nVoo, bool checkInAuto, unsigned int numMalas);

    unsigned int getNumMalas() const;

    void setNumMalas(unsigned int numMalas);

    bool isCheckInAuto() const;

    void setCheckInAuto(bool checkInAuto);

    unsigned int getNVoo() const;
};


#endif //PROJETO1_BILHETE_H
