#include "Mala.h"

Passageiro * Mala::getDono() const {
    return dono;
}

void Mala::setDono(Passageiro* dono) {
    dono->removeMala(*this);
    Terminal::updateVec();
    this->dono = dono;
    dono->addMala(this);
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
    despachada->addMala(this);
    Mala::despachada = despachada;
}

Mala::Mala(Passageiro *dono, float peso, Aviao *despachada) : dono(dono), despachada(despachada), peso(peso) {}

std::string Mala::getObjectName() {
    if (despachada != nullptr)
    {
        return "Mala (" + to_string(dono->getId()) + ", " + to_string(peso) + ", " + despachada->getMatricula() + ")";
    }
    else
    {
        return "Mala (" + to_string(dono->getId()) + ", " + to_string(peso) + ")";
    }
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
        cout << "input aviao (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < despachada->getNextVoo().getOrigem()->getAvioes().size())
            {
                auto temp2 = despachada->getNextVoo().getOrigem()->getAvioes().begin();
                advance(temp2, stoi(temp1));
                setDespachada(*temp2);
            }
            
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "setDono"){
        cout << "input passageiro (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setDono(Terminal::passageiros[stoi(temp1)]);
            Terminal::updateVec();
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "getPeso") {
        cout << peso << endl;
        return true;
    }
    else if (nomeFunc == "setPeso"){
        cout << "input Peso: ";
        string temp;
        getline(cin, temp);
        try {
            peso = stof(temp);
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

std::vector<Terminal *> *Mala::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "dono")
    {
        temp->push_back(dono);
    }
    else if (nameVector == "despachada")
    {
        temp->push_back(despachada);
    }
    return temp;
}

bool operator==(const Mala &lhs, const Mala &rhs) {
           return lhs.dono == rhs.dono && lhs.peso == rhs.peso;
}
