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

std::string Bilhete::getObjectName() {
    return "Bilhete (" + passageiro->getNome() + ", " + to_string(nVoo) + ", " + to_string(levaBagagem) + ")";
}

std::string Bilhete::getObjectID() {
    return passageiro->getNome();
}

std::stack<std::string> Bilhete::funcs() {
    stack<string> temp;
    temp.push("isLevaBagagem()");
    temp.push("getNVoo()");
    temp.push("setNVoo()");
    temp.push("setPassageiro()");
    temp.push("getLevaBagagem()");
    temp.push("setLevaBagagem()");
    return temp;
}
