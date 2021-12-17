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
    return telemovel == rhs.telemovel;
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

std::string Funcionario::getObjectID() {
    return to_string(telemovel);
}

std::stack<std::string> Funcionario::funcs() {
    stack<string> temp;
    temp.push("setAeroporto()");
    temp.push("getTelemovel()");
    temp.push("setTelemovel()");
    temp.push("getNome()");
    temp.push("setNome()");
    temp.push("getMorada()");
    temp.push("setMorada()");
    return temp;
}

bool Funcionario::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "setAeroporto"){
        lalal
    }
    else if (nomeFunc == "getTelemovel"){
        cout << telemovel << endl;
        return true;
    }
    else if (nomeFunc == "setTelemovel") {
        cout << "input Telemovel: ";
        string temp;
        cin >> temp;
        try {
            setTelemovel(stoi(temp));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    else if (nomeFunc == "getNome"){
        cout << nome << endl;
    }
    else if (nomeFunc == "setNome"){
        cout << "input Nome: ";
        string temp;
        getline(cin, nome);
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }

}
