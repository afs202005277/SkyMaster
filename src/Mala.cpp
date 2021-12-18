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
    despachada->addMala(this);
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
        cout << "input aviao (index): ";
        string temp1;
        cin >> temp1;
        try
        {
            if (stoi(temp1) < despachada->getNextVoo().getOrigem()->getAvioes().size())
            {
                auto temp2 = despachada->getNextVoo().getOrigem()->getAvioes().begin();
                advance(temp2, stoi(temp1));
                setDespachada(*temp2);
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setDono"){
        cout << "input passageiro (index): ";
        string temp1;
        cin >> temp1;
        try
        {
            setDono(&Terminal::passageiros[stoi(temp1)]);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getPeso") {
        cout << peso << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    else if (nomeFunc == "setPeso"){
        cout << "input Peso: ";
        string temp;
        cin >> temp;
        try {
            peso = stof(temp);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

std::vector<Terminal *> *Mala::getV(std::string nameVector) {
    vector<Terminal*> *temp;
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
