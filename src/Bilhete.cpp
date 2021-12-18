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

std::string Bilhete::getObjectName() {
    return "Bilhete (" + passageiro->getNome() + ", " + to_string(nVoo) + ", " + to_string(levaBagagem) + ")";
}

std::string Bilhete::getObjectID() {
    return passageiro->getNome();
}

std::stack<std::string> Bilhete::funcs() {
    stack<string> temp;
    temp.push("getNVoo()");
    temp.push("setNVoo()");
    temp.push("setPassageiro()");
    temp.push("getLevaBagagem()");
    temp.push("setLevaBagagem()");
    return temp;
}

bool Bilhete::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if(nomeFunc == "getNVoo"){
        cout << getNVoo() << endl;
        return true;
    }
    else if(nomeFunc == "setNVoo"){
        cout << "input nVoo: ";
        string temp;
        getline(cin, temp);
        try {
            setNVoo(stoi(temp));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "setPassageiro"){
        cout << "input Passenger's index: ";
        string temp1;
        try {
            setPassageiro((passageiros[stoi(temp1)]));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed.";
        }
    }
    else if (nomeFunc == "getLevaBagagem"){
        if (getLevaBagagem())
            cout << "True" << endl;
        else
            cout << "False" << endl;
        return true;
    }
    else if (nomeFunc == "setLevaBagagem") {
        cout << "input levaBagagem: ";
        string temp;
        getline(cin, temp);
        try {
            setLevaBagagem(stoi(temp));
            return true;
        }
        catch (exception &e) {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else{
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return false;
}

vector<Terminal*> *Bilhete::getV(std::string nameVector)
{
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "passageiro")
    {
        temp->push_back(passageiro);
    }
    return temp;
}