#include <limits>
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

Transporte::Transporte(int distancia, const Tempo &horaChegada, const Tempo &horaPartida, TipoTransporte tipo) : distancia(distancia),
                                                                                       horaChegada(horaChegada),
                                                                                       horaPartida(horaPartida),
                                                                                       tipo(tipo) {}

bool operator<(const Transporte &lhs, const Transporte &rhs) {
    if (lhs.distancia < rhs.distancia)
        return true;
    if (lhs.distancia == rhs.distancia && lhs.horaChegada < rhs.horaChegada)
        return true;
    return false;
}

Transporte::Transporte() : horaChegada(-1, -1, -1), horaPartida (-1, -1, -1) {}

Transporte::Transporte(int distancia, const std::string &horaChegada, const std::string &horaPartida,
                       const std::string &tipo) : distancia(distancia), horaChegada(Tempo(horaChegada)),
                                             horaPartida(Tempo(horaPartida)){
    if (tipo=="metro")
        this->tipo=metro;
    else if (tipo=="comboio")
        this->tipo=comboio;
    else
        this->tipo=autocarro;
}

std::string Transporte::getObjectName() {
    return "Transporte (" + horaChegada.getTempo() + ", " + horaPartida.getTempo() + ", " + std::to_string(distancia) + ")";
}

std::string Transporte::getObjectID() {
    return horaChegada.getTempo();
}

std::stack<std::string> Transporte::funcs() {
    std::stack<std::string> temp;
    temp.push("getTipo()");
    temp.push("setTipo()");
    temp.push("getDistancia()");
    temp.push("setDitancia()");
    temp.push("getHoraChegada()");
    temp.push("setHoraChegada()");
    temp.push("getHoraPartida()");
    temp.push("setHoraPartida()");
    return temp;
}

std::vector<Terminal *> *Transporte::getV(std::string nameVector) {
    std::vector<Terminal*> *temp;
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
        string tmp;
        cin >> tmp;
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getDistancia"){
        cout << distancia << endl;
        return true;
    }
    else if (nomeFunc == "setDitancia"){
        cout << "input distancia: ";
        string temp;
        cin >> temp;
        try {
            distancia = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getHoraChegada"){
        cout << horaChegada << endl;
        return true;
    }
    else if (nomeFunc == "setHoraChegada"){
        cout << "input hora: ";
        string temp1;
        cin >> temp1;
        cout << "input minuto: ";
        string temp2;
        cin >> temp2;
        try{
            horaChegada = Tempo(stoi(temp1), stoi(temp2));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getHoraPartida"){
        cout << horaPartida << endl;
        return true;
    }
    else if (nomeFunc == "setHoraPartida"){
        cout << "input hora: ";
        string temp1;
        cin >> temp1;
        cout << "input minuto: ";
        string temp2;
        cin >> temp2;
        try{
            horaPartida = Tempo(stoi(temp1), stoi(temp2));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else{
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
