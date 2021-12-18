#include "Passageiro.h"


const std::string &Passageiro::getNome() const {
    return nome;
}

void Passageiro::setNome(const std::string &nome) {
    Passageiro::nome = nome;
}

int Passageiro::getIdade() const {
    return idade;
}

void Passageiro::setIdade(int idade) {
    Passageiro::idade = idade;
}

int Passageiro::getId() const {
    return id;
}

void Passageiro::setId(int id) {
    Passageiro::id = id;
}

Passageiro::Passageiro(std::string nome, int idade, int id) : nome(std::move(nome)), idade(idade), id(id) {}

const queue<Bilhete *> & Passageiro::getBilhetes() const {
    return this->bilhetes;
}

void Passageiro::addBilhete(Bilhete *bilhete) {
    this->bilhetes.push(bilhete);
}

Bilhete* Passageiro::getNextBilhete()
{
    return this->bilhetes.front();
}

void Passageiro::removeNextBilhete() {
    if (!bilhetes.empty())
        this->bilhetes.pop();
}

bool Passageiro::hasBilhete(int nVoo) const {
    std::queue<Bilhete *> temp = bilhetes;
    while (!temp.empty())
    {
        if (temp.front()->getNVoo() == nVoo)
        {
            return true;
        }
        temp.pop();
    }
    return false;
}


bool Passageiro::checkIn(bool checkInAutomatico, Voo &voo, std::queue<Mala *> &malas) const {
    if (!this->hasBilhete(voo.getNVoo()))
       return false;
   if (!checkInAutomatico)
       return true;
    std::vector<CarrinhoTransporte *> carrinhos = voo.getOrigem()->getCarrinhos();
    for (auto &c:carrinhos)
    {
        if (c->getAviao() == voo.getAviao())
        {
            for (int i=0;i<malas.size();i++)
            {
                bool flag = c->addMala(malas.front());
                if (!flag){
                    c->descarregarMalasAviao();
                    c->addMala(malas.front());
                }
                malas.pop();
            }
        }
    }
    return true;
}

bool Passageiro::getIntoPlane(Voo &voo) {
    std::queue<Mala*> reference;
    if (!hasBilhete(voo.getNVoo()))
        return false;
    voo.addPassageiro(this);
    return true;
}

Passageiro::Passageiro(int idade, int id, string nome, const queue<Bilhete *> &bilhetes) : idade(idade), id(id),
                                                                                                  nome(std::move(nome)),
                                                                                                  bilhetes(bilhetes) {}

bool operator==(const Passageiro &lhs, const Passageiro &rhs) {
    return lhs.id == rhs.id;
}

std::string Passageiro::getObjectName() {
    return "Passageiro (" + to_string(id) + ", " + nome + ", " + to_string(idade) + ")";
}

std::string Passageiro::getObjectID() {
    return to_string(id);
}

std::stack<std::string> Passageiro::funcs() {
    stack<string> temp;
    temp.push("removeNextBilhete()");
    temp.push("getNome()");
    temp.push("getIdade()");
    temp.push("setIdade()");
    temp.push("getId()");
    temp.push("setId()");
    temp.push("hasBilhete()");
    temp.push("getIntoPlane()");
    return temp;
}

std::vector<Terminal *> *Passageiro::getV(std::string nameVector) {
    vector<Terminal*> *temp;
    if (nameVector == "bilhetes")
    {
        auto temp1 = getBilhetes();
        while (!temp1.empty())
        {
            temp->push_back(temp1.front());
            temp1.pop();
        }
    }
    return temp;
}

bool Passageiro::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "removeNextBilhete"){
        removeNextBilhete();
        return true;
    }
    else if (nomeFunc == "getNome"){
        cout << nome <<  endl;
        return true;
    }
    else if (nomeFunc == "getIdade"){
        cout << idade << endl;
        return true;
    }
    else if (nomeFunc == "setIdade"){
        cout << "input Idade: ";
        string temp;
        cin >> temp;
        try {
            idade = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getId"){
        cout << id << endl;
        return true;
    }
    else if (nomeFunc == "setId"){
        cout << "input ID: ";
        string temp;
        cin >> temp;
        try {
            id = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "hasBilhete"){
        cout << "input voo (index): ";
        string temp1;
        cin >> temp1;
        try
        {
            cout << hasBilhete(Terminal::voos[stoi(temp1)].getNVoo()) << endl;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getIntoPlane"){
        cout << "input voo (index): ";
        string temp1;
        cin >> temp1;
        try
        {
            cout << (getIntoPlane(Terminal::voos[stoi(temp1)]) ? "Done." : "Not done.") << endl;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else{
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}

const vector<Mala *> &Passageiro::getMalas() const {
    return malas;
}

void Passageiro::setMalas(const vector<Mala *> &malas) {
    Passageiro::malas = malas;
}

void Passageiro::addMala(Mala *m)
{
    malas.push_back(m);
}


