//
// Created by Pedro Fonseca on 13/12/2021.
//

#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H


class Bilhete
{
private:
    unsigned int numMalas;
public:
    unsigned int getNumMalas() const;

    void setNumMalas(unsigned int numMalas);

    bool isCheckInAuto() const;

    void setCheckInAuto(bool checkInAuto);

private:
    bool checkInAuto;
};


#endif //PROJETO1_BILHETE_H
