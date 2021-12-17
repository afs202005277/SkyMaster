#include "Mala.h"

Passageiro * Mala::getDono() const {
    return dono;
}

void Mala::setDono(Passageiro* dono) {
    Mala::dono = dono;
}

float Mala::getPeso() const {
    return peso;
}

void Mala::setPeso(float peso) {
    Mala::peso = peso;
}

Aviao *Mala::getDespachada() const {
    return despachada;
}

void Mala::setDespachada(Aviao *despachada) {
    Mala::despachada = despachada;
}

Mala::Mala(Passageiro *dono, float peso, Aviao *despachada) : dono(dono), despachada(despachada), peso(peso) {}

std::string Mala::getObjectName() {
    return "Mala (" + to_string(dono->getId()) + ", " + to_string(peso) + ", " + despachada->getMatricula() + ")";
}

std::string Mala::getObjectID() {
    return to_string(dono->getId());
}

std::stack<std::string> Mala::funcs() {
    stack<string> temp;
    temp.push("setDespachada()");
    temp.push("setDono()");
    temp.push("getPeso()");
    temp.push("setPeso()");
    return temp;
}

bool Mala::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "setDespachada") {
        lalal
    }
    else if (nomeFunc == "setDono"){
        lalal
    }
    else if (nomeFunc == "getPeso") {
        cout << peso << endl;
        return true;
    }
    else if (nomeFunc == "setPeso"){
        cout << "input Peso: ";
        string temp;
        cin >> temp;
        try {
            peso = stof(temp);
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
