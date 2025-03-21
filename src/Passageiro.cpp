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


bool Passageiro::checkIn(bool checkInAutomatico, Voo &voo, std::queue<Mala *> malas) const {
    if (!this->hasBilhete(voo.getNVoo()))
       return false;
   if (!checkInAutomatico)
       return true;
    std::vector<CarrinhoTransporte *> carrinhos = voo.getOrigem()->getCarrinhos();
    for (auto &c:carrinhos)
    {
        if (c->getAviao() == voo.getAviao())
        {
            while(!malas.empty())
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
    return "Passageiro (" + nome + ", " + to_string(idade) + ", " + to_string(id) + ")";
}

std::string Passageiro::getObjectID() {
    return to_string(id);
}

std::stack<std::string> Passageiro::funcs() {
    stack<string> temp;
    temp.push("removeBilhete()");
    temp.push("removeNextBilhete()");
    temp.push("getNome()");
    temp.push("setNome()");
    temp.push("getIdade()");
    temp.push("setIdade()");
    temp.push("addMala()");
    temp.push("removeMala()");
    temp.push("getId()");
    temp.push("setId()");
    temp.push("hasBilhete()");
    temp.push("getIntoPlane()");
    temp.push("checkIn()");
    return temp;
}

std::vector<Terminal *> *Passageiro::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "bilhetes")
    {
        auto temp1 = getBilhetes();
        while (!temp1.empty())
        {
            temp->push_back(temp1.front());
            temp1.pop();
        }
    }
    else if (nameVector == "malas")
    {
        auto temp1 = getMalas();
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
    if (nomeFunc == "removeBilhete")
    {
        cout << "input bilhete (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < bilhetes.size() && stoi(temp1) >= 0)
            {
                removeBilhete(stoi(temp1));
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
    else if (nomeFunc == "removeNextBilhete"){
        removeNextBilhete();
        Terminal::updateVec();
        return true;
    }
    else if (nomeFunc == "getNome"){
        cout << nome <<  endl;
        return true;
    }
    else if (nomeFunc == "setNome"){
        cout << "Input nome: ";
        getline(cin, nome);
        return true;
    }
    else if (nomeFunc == "getIdade"){
        cout << idade << endl;
        return true;
    }
    else if (nomeFunc == "setIdade"){
        cout << "input Idade: ";
        string temp;
        getline(cin, temp);
        try {
            idade = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "addMala")
    {
        cout << "input peso: ";
        string temp1;
        getline(cin, temp1);
        try
        {
            addMala(new Mala(this, stoi(temp1), nullptr));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "removeMala")
    {
        cout << "input mala (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < malas.size()  && stoi(temp1) >= 0)
            {
                auto temp2 = getMalas();

            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "getId"){
        cout << id << endl;
        return true;
    }
    else if (nomeFunc == "setId"){
        cout << "input ID: ";
        string temp;
        getline(cin, temp);
        try {
            id = stoi(temp);
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "hasBilhete"){
        cout << "input voo (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::voos.size())
                throw exception();
            bool f = hasBilhete(Terminal::voos[stoi(temp1)]->getNVoo());
            if (f)
                cout << true << endl;
            else
                cout << false << endl;
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "getIntoPlane"){
        cout << "input voo (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::voos.size())
                throw exception();
            cout << (getIntoPlane(*Terminal::voos[stoi(temp1)]) ? "Done." : "You don't have a ticket for that flight.") << endl;
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "checkIn")
    {
        cout << "input checkInAutomatico? (y/n): ";
        string temp1;
        getline(cin, temp1);
        cout << "input voo (index): ";
        string temp2;
        getline(cin, temp2);
        try
        {
            if ((temp1 == "y" || temp1 == "n") && stoi(temp2) < Terminal::voos.size() && stoi(temp2) >= 0)
            {
                checkIn(temp1=="y", *Terminal::voos[stoi(temp2)], malas);
            }
            else
                throw exception();
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else
    {
        return false;
    }
    return true;
}

const queue<Mala *> &Passageiro::getMalas() const {
    return malas;
}

void Passageiro::setMalas(const queue<Mala *> &malas) {
    Passageiro::malas = malas;
}

void Passageiro::addMala(Mala *m)
{
    malas.push(m);
}

void Passageiro::removeBilhete(int index)
{
    queue<Bilhete*> temp;
    while (!bilhetes.empty())
    {
        if (index != 0)
        {
            temp.push(bilhetes.front());
        }
        bilhetes.pop();
        index--;
    }
    bilhetes = temp;
}

void Passageiro::removeMala(Mala *m) {
    queue<Mala*> temp;
    while (!malas.empty())
    {
        if (malas.front() != m)
        {
            temp.push(malas.front());
        }
        malas.pop();
    }
    malas = temp;
}

void Passageiro::setBilhetes(const queue<Bilhete *> &bilhetes) {
    Passageiro::bilhetes = bilhetes;
}

bool operator<(const Passageiro &lhs, const Passageiro &rhs) {
    if (lhs.idade < rhs.idade)
        return true;
    if (lhs.idade == rhs.idade && lhs.nome < rhs.nome)
        return true;
    if (lhs.idade == rhs.idade && lhs.nome == rhs.nome && lhs.id < rhs.id)
        return true;
    return false;
}
