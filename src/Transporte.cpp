#include <limits>
#include <iostream>
#include "Transporte.h"

using namespace  std;

TipoTransporte Transporte::getTipo() const {
    return tipo;
}

void Transporte::setTipo(TipoTransporte tipo) {
    Transporte::tipo = tipo;
}

int Transporte::getDistancia() const {
    return distancia;
}

void Transporte::setDistancia(int distancia) {
    Transporte::distancia = distancia;
}

const Tempo &Transporte::getHoraChegada() const {
    return horaChegada;
}

void Transporte::setHoraChegada(const Tempo &horaChegada) {
    Transporte::horaChegada = horaChegada;
}

const Tempo &Transporte::getHoraPartida() const {
    return horaPartida;
}

void Transporte::setHoraPartida(const Tempo &horaSaida) {
    Transporte::horaPartida = horaSaida;
}

Transporte::Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo,
                       std::string nomeAeroporto) : distancia(distancia),
                                                                                       horaChegada(horaChegada),
                                                                                       horaPartida(horaPartida),
                                                                                       tipo(tipo), nomeAeroporto(nomeAeroporto) {}

bool operator<(const Transporte &lhs, const Transporte &rhs) {
    if (lhs.distancia < rhs.distancia)
        return true;
    if (lhs.distancia == rhs.distancia && lhs.horaChegada < rhs.horaChegada)
        return true;
    if (lhs.distancia == rhs.distancia && lhs.horaChegada == rhs.horaChegada && lhs.tipo < rhs.tipo)
        return true;
    return false;
}

Transporte::Transporte() : horaChegada(-1, -1, -1), horaPartida (-1, -1, -1) {}

Transporte::Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida,
                       const std::string &tipo,
                       std::string nomeAeroporto) : distancia(distancia), horaChegada(Tempo(horaChegada)),
                                             horaPartida(Tempo(horaPartida)), nomeAeroporto(nomeAeroporto){
    if (tipo=="metro")
        this->tipo=metro;
    else if (tipo=="comboio")
        this->tipo=comboio;
    else
        this->tipo=autocarro;
}

std::string Transporte::getObjectName() {
    if (tipo == metro)
        return "Transporte (" + std::to_string(distancia) + ", " + horaChegada.getTempo() + ", " + horaPartida.getTempo() + ", metro, " + nomeAeroporto + ")";
    else if (tipo == comboio)
        return "Transporte (" + std::to_string(distancia) + ", " + horaChegada.getTempo() + ", " + horaPartida.getTempo() + ", comboio, " + nomeAeroporto + ")";
    else
        return "Transporte (" + std::to_string(distancia) + ", " + horaChegada.getTempo() + ", " + horaPartida.getTempo() + ", autocarro, " + nomeAeroporto + ")";
}

std::string Transporte::getObjectID() {
    return std::to_string(distancia);
}

std::stack<std::string> Transporte::funcs() {
    std::stack<std::string> temp;
    temp.push("getTipo()");
    temp.push("setTipo()");
    temp.push("getDistancia()");
    temp.push("setDistancia()");
    temp.push("getHoraChegada()");
    temp.push("setHoraChegada()");
    temp.push("getHoraPartida()");
    temp.push("setHoraPartida()");
    return temp;
}

std::vector<Terminal *> *Transporte::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    return temp;
}

bool Transporte::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getTipo"){
       if (tipo == metro)
           cout << "metro" << endl;
       else if (tipo == comboio)
           cout << "comboio" << endl;
       else if (tipo == autocarro)
           cout << "autocarro" << endl;
        return true;
    }
    else if (nomeFunc == "setTipo"){
        cout << "Input tipo: ";
        string tmp;
        getline(cin, tmp);
        if (tmp == "comboio")
        {
            tipo = comboio;
            return true;
        }
        else if (tmp == "metro"){
            tipo = metro;
            return true;
        }
        else if (tmp == "autocarro") {
            tipo = autocarro;
            return true;
        }
        
        return false;
    }
    else if (nomeFunc == "getDistancia"){
        cout << distancia << endl;
        return true;
    }
    else if (nomeFunc == "setDitancia"){
        cout << "input distancia: ";
        string temp;
        getline(cin, temp);
        try {
            distancia = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "getHoraChegada"){
        cout << horaChegada.getTempo() << endl;
        return true;
    }
    else if (nomeFunc == "setHoraChegada"){
        cout << "input hora: ";
        string temp1;
        getline(cin, temp1);
        cout << "input minuto: ";
        string temp2;
        getline(cin, temp2);
        try{
            horaChegada = Tempo(stoi(temp1), stoi(temp2));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "getHoraPartida"){
        cout << horaPartida.getTempo() << endl;
        return true;
    }
    else if (nomeFunc == "setHoraPartida"){
        cout << "input hora: ";
        string temp1;
        getline(cin, temp1);
        cout << "input minuto: ";
        string temp2;
        getline(cin, temp2);
        try{
            horaPartida = Tempo(stoi(temp1), stoi(temp2));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else{
        return false;
    }
}

const string &Transporte::getNomeAeroporto() const {
    return nomeAeroporto;
}

void Transporte::setNomeAeroporto(const string &nomeAeroporto) {
    Transporte::nomeAeroporto = nomeAeroporto;
}

bool operator==(const Transporte &lhs, const Transporte &rhs) {
           return lhs.distancia == rhs.distancia &&
           lhs.horaChegada == rhs.horaChegada &&
           lhs.horaPartida == rhs.horaPartida &&
           lhs.tipo == rhs.tipo &&
           lhs.nomeAeroporto == rhs.nomeAeroporto;
}
