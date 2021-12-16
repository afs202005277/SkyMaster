#include "Funcionario.h"

#include <utility>

int Funcionario::getTelemovel() const {
    return telemovel;
}

void Funcionario::setTelemovel(int telemovel) {
    Funcionario::telemovel = telemovel;
}

const std::string &Funcionario::getNome() const {
    return nome;
}

void Funcionario::setNome(const std::string &nome) {
    Funcionario::nome = nome;
}

const std::string &Funcionario::getMorada() const {
    return morada;
}

void Funcionario::setMorada(const std::string &morada) {
    Funcionario::morada = morada;
}

Funcionario::Funcionario(int telemovel, std::string nome, std::string morada, Aeroporto *aeroporto)
        : telemovel(telemovel), nome(std::move(nome)), morada(std::move(morada)), aeroporto(aeroporto) {
    aeroporto->addFuncionario(this);
}

bool Funcionario::operator==(const Funcionario &rhs) const {
    return telemovel == rhs.telemovel &&
           nome == rhs.nome &&
           morada == rhs.morada &&
           aeroporto == rhs.aeroporto;
}

bool Funcionario::operator!=(const Funcionario &rhs) const {
    return !(rhs == *this);
}

bool operator<(const Funcionario &lhs, const Funcionario &rhs) {
    if (lhs.nome < rhs.nome)
        return true;
    if (lhs.nome == rhs.nome && rhs.telemovel < lhs.telemovel)
        return true;
    return false;
}

bool operator>(const Funcionario &lhs, const Funcionario &rhs) {
    return rhs < lhs;
}

bool operator<=(const Funcionario &lhs, const Funcionario &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Funcionario &lhs, const Funcionario &rhs) {
    return !(lhs < rhs);
}

Aeroporto *Funcionario::getAeroporto() const {
    return aeroporto;
}

void Funcionario::setAeroporto(Aeroporto *aeroporto) {
    aeroporto->removeFuncionario(*this);
    Funcionario::aeroporto = aeroporto;
}

std::string Funcionario::getObjectName() {
    return "Funcionario (" + to_string(telemovel) + ", " + nome + ", " + morada + ", " + aeroporto->getName() + ")";
}
