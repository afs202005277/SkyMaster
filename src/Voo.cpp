#include "Voo.h"

Voo::Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
         Tempo &partida, int lotacaoAtual)
        : nVoo(nVoo), duracao(duracao), lotacaoAtual(lotacaoAtual), dataPartida(dataPartida), origem(origem),
          destino(destino), aviao(aviao), horaPartida(partida) {}

int Voo::getNVoo() const {
    return nVoo;
}

void Voo::setNVoo(int nVoo) {
    Voo::nVoo = nVoo;
}

int Voo::getDuracao() const {
    return duracao;
}

void Voo::setDuracao(int duracao) {
    Voo::duracao = duracao;
}

int Voo::getLotacaoAtual() const {
    return lotacaoAtual;
}

void Voo::setLotacaoAtual(int lotacaoAtual) {
    Voo::lotacaoAtual = lotacaoAtual;
}

const Data &Voo::getDataPartida() const {
    return dataPartida;
}

void Voo::setDataPartida(const Data &dataPartida) {
    Voo::dataPartida = dataPartida;
}

Aeroporto *Voo::getOrigem() const {
    return origem;
}

void Voo::setOrigem(Aeroporto *origem) {
    Voo::origem = origem;
}

Aeroporto *Voo::getDestino() const {
    return destino;
}

void Voo::setDestino(Aeroporto *destino) {
    Voo::destino = destino;
}

const list<Passageiro *> & Voo::getPassageiros() const {
    return passageiros;
}

bool Voo::sellBilhete(bool levaBagagem, Passageiro *p) {
    if (this->lotacaoAtual < this->aviao->getCapacidade())
    {
        Bilhete *temp;
        temp = new Bilhete(this->nVoo, levaBagagem, p);
        this->lotacaoAtual++;
        p->addBilhete(temp);
        return true;
    }
    return false;
}

bool Voo::sellBilheteGroup(const vector<bool> &checkInAuto, const vector<Passageiro *> &p) {
    unsigned int nPassageiros = checkInAuto.size();
    if (this->lotacaoAtual + nPassageiros > aviao->getCapacidade())
        return false;
    for (int i=0;i<nPassageiros;i++)
    {
        this->sellBilhete(checkInAuto[i], p[i]);
        passageiros.push_back(p[i]);
    }
    return true;
}

Aviao *Voo::getAviao() const {
    return aviao;
}

void Voo::setAviao(Aviao *aviao) {
    Voo::aviao = aviao;
}

void Voo::addPassageiro(Passageiro *p) {
    passageiros.push_back(p);
}

void Voo::setNVoo(unsigned int nVoo) {
    Voo::nVoo = nVoo;
}

void Voo::setPassageiros(const list<Passageiro *> &passageiros) {
    Voo::passageiros = passageiros;
}

const Tempo &Voo::getHoraPartida() const {
    return horaPartida;
}

void Voo::setHoraPartida(const Tempo &horaPartida) {
    Voo::horaPartida = horaPartida;
}

bool operator<(const Voo &lhs, const Voo &rhs) {
    if (lhs.dataPartida < rhs.dataPartida)
        return true;
    if (rhs.dataPartida == lhs.dataPartida && lhs.horaPartida < rhs.horaPartida)
        return true;
    return false;
}

bool operator>(const Voo &lhs, const Voo &rhs) {
    return rhs < lhs;
}

bool operator<=(const Voo &lhs, const Voo &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Voo &lhs, const Voo &rhs) {
    return !(lhs < rhs);
}

Voo::Voo(int nVoo, int duracao, string dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
         string partida) : nVoo(nVoo), duracao(duracao), dataPartida(Data(dataPartida)), origem(origem),
                           destino(destino), aviao(aviao), horaPartida(partida){}

std::string Voo::getObjectName() {
    return "Voo (" + std::to_string(nVoo) + ", " + std::to_string(duracao) + ", " + dataPartida.getDate() + ", " + horaPartida.getTempo() + ", " + origem->getName() + ", " + destino->getName() + ", " + aviao->getMatricula() + ")";
}

std::string Voo::getObjectID() {
    return to_string(nVoo);
}

std::stack<std::string> Voo::funcs() {
    stack<string> temp;
    temp.push("getHoraPartida()");
    temp.push("setHoraPartida()");
    temp.push("setAviao()");
    temp.push("getNVoo()");
    temp.push("setNVoo()");
    temp.push("getDuracao()");
    temp.push("setDuracao()");
    temp.push("getLotacoAtual()");
    temp.push("setLotacaoAtual()");
    temp.push("getDataPartida()");
    temp.push("setDataPartida()");
    temp.push("setOrigem()");
    temp.push("setDestino()");
    temp.push("sellBilhete()");
    temp.push("addPassagero()");
    return temp;
}
