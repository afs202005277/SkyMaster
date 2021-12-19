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
    this->passageiro->removeBilhete(std::find(Terminal::passageiros.begin(), Terminal::passageiros.end(), this->passageiro) - Terminal::passageiros.begin());
    Bilhete::passageiro = passageiro;
    passageiro->addBilhete(this);
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
    }
    else if(nomeFunc == "setNVoo"){
        cout << "input nVoo: ";
        string temp;
        getline(cin, temp);
        try {
            setNVoo(stoi(temp));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setPassageiro"){
        cout << "input Passenger's index: ";
        string temp1;
        getline(cin, temp1);
        try {
            if (stoi(temp1) < Terminal::passageiros.size()) {
                setPassageiro((Terminal::passageiros[stoi(temp1)]));
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
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
    }
    else if (nomeFunc == "setLevaBagagem") {
        cout << "input levaBagagem (y/n): ";
        string temp;
        getline(cin, temp);
        try {
            if (temp == "y")
            {
                setLevaBagagem(true);
            }
            else if (temp == "n")
            {
                setLevaBagagem(false);
            }
            else
            {
                cout << "Function failed." << endl;
            }
        }
        catch (exception &e) {
            cout << "Function failed." << endl;
        }
    }
    else{
        return false;
    }
    return true;
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