#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

#include "Passageiro.h"
#include "Terminal.h"
class Passageiro;
class Terminal;
class Bilhete : public Terminal {
private:
    unsigned int nVoo;
    /**
     * Passageiro a que esta associado
     */
    Passageiro* passageiro;
    bool levaBagagem;
public:
    Bilhete(unsigned int nVoo, bool levaBagagem, Passageiro *p);

    void setNVoo(unsigned int nVoo);

    Passageiro *getPassageiro() const;

    void setPassageiro(Passageiro *passageiro);

    bool getLevaBagagem() const;

    void setLevaBagagem(bool leva);

    unsigned int getNVoo() const;

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_BILHETE_H
