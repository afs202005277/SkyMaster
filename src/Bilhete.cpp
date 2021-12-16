#include "Bilhete.h"

Bilhete::Bilhete(unsigned int nVoo, bool levaBagagem, Passageiro *p)
        : nVoo(nVoo), levaBagagem(levaBagagem), passageiro(p) {}

bool Bilhete::getLevaBagagem() const {
    return levaBagagem;
}

void Bilhete::setLevaBagagem(bool leva) {
    Bilhete::levaBagagem = leva;
}

unsigned int Bilhete::getNVoo() const {
    return nVoo;
}

void Bilhete::setNVoo(unsigned int nVoo) {
    Bilhete::nVoo = nVoo;
}

Passageiro *Bilhete::getPassageiro() const {
    return passageiro;
}

void Bilhete::setPassageiro(Passageiro *passageiro) {
    Bilhete::passageiro = passageiro;
}

bool Bilhete::isLevaBagagem() const {
    return levaBagagem;
}
