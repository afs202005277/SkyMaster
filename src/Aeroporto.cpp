#include <algorithm>
#include <utility>
#include <list>
#include "Aeroporto.h"


Aeroporto::Aeroporto(std::string name, std::string city, std::string country) : transportes(Transporte(-1, Tempo{-1, -1,
                                                                                                                 -1},
                                                                                                       Tempo{-1, -1,
                                                                                                             -1}, metro,
                                                                                                       "")), name(std::move(name)), city(std::move(city)),
                                                                                country(std::move(country)) {}

const std::string &Aeroporto::getName() const {
    return name;
}

void Aeroporto::setName(const std::string &Name) {
    Aeroporto::name = Name;
}

const std::string &Aeroporto::getCity() const {
    return city;
}

void Aeroporto::setCity(const std::string &City) {
    Aeroporto::city = City;
}

const std::string &Aeroporto::getCountry() const {
    return country;
}

void Aeroporto::setCountry(const std::string &Country) {
    Aeroporto::country = Country;
}

void Aeroporto::setTransportes(BST<Transporte> &t) {
    transportes = t;
}

BST<Transporte> Aeroporto::getTransportes() {
    return transportes;
}

bool Aeroporto::addTransporte(Transporte &t) {
    return transportes.insert(t);
}

Transporte Aeroporto::getNearestTransport() {
    return transportes.findMin();
}

vector<Transporte> Aeroporto::getAvailableTransports(Tempo min, Tempo max) {
    vector<Transporte> res;
    BSTItrIn<Transporte> it(transportes);
    while(!it.isAtEnd())
    {
        Transporte current = it.retrieve();
        if (current.getHoraChegada() >= min && current.getHoraChegada() <= max)
            res.push_back(current);
        it.advance();
    }
    return res;
}

bool Aeroporto::removeTransporte(Transporte &t) {
    return transportes.remove(t);
}

Transporte Aeroporto::getNextTransport() {
    Tempo t = {INT_MAX, INT_MAX, INT_MAX};
    Transporte res;
    BSTItrIn<Transporte> it(transportes);
    while(!it.isAtEnd())
    {
        Transporte current = it.retrieve();
        if (current.getHoraChegada() < t)
        {
            t = current.getHoraChegada();
            res = current;
        }
        it.advance();
    }
    return res;
}

void Aeroporto::addFuncionario(Funcionario *f) {
    int left = 0, right = funcionarios.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (*funcionarios[middle] < *f)
            left = middle + 1;
        else if (*f < *funcionarios[middle])
            right = middle - 1;
        else
            return;
    }
    funcionarios.insert(funcionarios.begin()+left, f);
}

Funcionario *Aeroporto::removeFuncionario(const Funcionario &f) {
    int left = 0, right = (int) funcionarios.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (*funcionarios[middle] < f)
            left = middle + 1;
        else if (f < *funcionarios[middle])
            right = middle - 1;
        else
        {
            Funcionario* tmp = funcionarios[middle];
            funcionarios.erase(funcionarios.begin() + middle);
            return tmp;
        }
    }
    return nullptr;
}

const vector<Funcionario *> &Aeroporto::getFuncionarios() const {
    return funcionarios;
}

void Aeroporto::setFuncionarios(vector<Funcionario *> &funcionariosNew) {
    sort(funcionariosNew.begin(), funcionariosNew.end(), sorterFuncionarios);
    Aeroporto::funcionarios = funcionariosNew;
}

vector<CarrinhoTransporte *> & Aeroporto::getCarrinhos() {
    return carrinhos;
}

void Aeroporto::setCarrinhos(const vector<CarrinhoTransporte *> &Carrinhos) {
    Aeroporto::carrinhos = Carrinhos;
}

bool Aeroporto::sorterFuncionarios(const Funcionario *f1, const Funcionario *f2) {
    return f1->getNome() < f2->getNome();
}

void Aeroporto::addAviao(Aviao *a) {
    avioes.push_back(a);
    avioes.sort(sorterAvioes);
    bool assigned=false;
    for (auto &c:carrinhos)
    {
        if (c->getAviao() == nullptr)
        {
            c->setAviao(a);
            a->setCarrinhoAssociado(c);
            assigned = true;
            break;
        }
    }
    if (!assigned)
    {
        auto *c = new CarrinhoTransporte(5, 5, 5, this, a);
        if (!carrinhos.empty())
        {
            auto *ref = carrinhos.front();
            c = new CarrinhoTransporte(ref->getNCarruagens(), ref->getNPilhas(), ref->getNMalas(), this, a);
        }
        a->setCarrinhoAssociado(c);
    }
}

bool Aeroporto::removeAviao(Aviao *a)
{
    auto t = find(avioes.begin(), avioes.end(), a);
    if (t != avioes.end())
    {
        (*t)->getCarrinhoAssociado()->setAviao(nullptr);
        (*t)->setCarrinhoAssociado(nullptr);
        avioes.erase(t);
        return true;
    }
    return false;
}

const list<Aviao *> &Aeroporto::getAvioes() const {
    return avioes;
}

void Aeroporto::setAvioes(const list<Aviao *> &Avioes) {
    Aeroporto::avioes = Avioes;
}

Aeroporto::Aeroporto(string name, string city, string country,
                     const vector<Funcionario *> &funcionarios, const BST<Transporte> &transportes,
                     const vector<CarrinhoTransporte *> &carrinhos, const list<Aviao *> &avioes) : name(std::move(name)),
                                                                                                   city(std::move(city)),
                                                                                                   country(std::move(country)),
                                                                                                   funcionarios(
                                                                                                           funcionarios),
                                                                                                   transportes(
                                                                                                           transportes),
                                                                                                   carrinhos(carrinhos),
                                                                                                   avioes(avioes) {
    this->avioes.sort(sorterAvioes);
}

bool Aeroporto::sorterAvioes(const Aviao* a1, const Aviao* a2) {
    if (a1->getPlano().size() > 1 && a2->getPlano().size() > 1)
    {
        return a1->getNextVoo() < a2->getNextVoo();
    }
    else if (a2->getPlano().size() > 1)
    {
        return true;
    }
    return false;
}

const queue<Mala *> &Aeroporto::getStorage() const {
    return storage;
}

void Aeroporto::setStorage(const queue<Mala *> &storage) {
    Aeroporto::storage = storage;
}

bool operator==(const Aeroporto &lhs, const Aeroporto &rhs) {
    return lhs.name == rhs.name;
}

void Aeroporto::addMalas(queue<Mala *> &malas) {
    while(!malas.empty())
    {
        storage.push(malas.front());
        malas.pop();
    }
}

void Aeroporto::addCarrinho(CarrinhoTransporte *c)
{
    carrinhos.push_back(c);
}

std::string Aeroporto::getObjectName() {
    return "Aeroporto (" + name + ", " + city + ", " + country + ")";
}

std::string Aeroporto::getObjectID() {
    return name;
}

bool Aeroporto::existsTransport(Transporte t) const {
    Transporte f = transportes.find(t);
    if (f.getDistancia() == -1)
        return false;
    return true;
}

list<Mala *> Aeroporto::searchStorageByName(const string &nomeDono) {
    auto tmp = storage;
    list<Mala*> res;
    while(!storage.empty())
    {
        if (storage.front()->getDono()->getNome() == nomeDono)
        {
            res.push_back(storage.front());
        }
        storage.pop();
    }
    storage = tmp;
    return res;
}

std::list<Aviao *> Aeroporto::getPlanesDepartingTo(const string& destination) {
    list<Aviao*> res;
    for (auto &a:avioes)
        if (!a->getPlano().empty() && a->getPlano().front()->getOrigem()->name == destination)
            res.push_back(a);
    return res;
}

std::list<Funcionario *> Aeroporto::getFuncionariosByNames(const string & Nome){
    list<Funcionario*> res;
    for (auto &f:funcionarios)
    {
        if (f->getNome() == Nome)
            res.push_back(f);
    }
    return res;
}

list<Transporte> Aeroporto::searchTransportesTipo(const string &tipo) {
    list <Transporte> res;
    TipoTransporte t;
    BSTItrIn<Transporte> it(transportes);
    if (tipo == "autocarro")
        t = autocarro;
    else if (tipo == "metro")
        t = metro;
    else
        t = comboio;
    while(!it.isAtEnd())
    {
        if (it.retrieve().getTipo() == t)
            res.push_back(it.retrieve());
        it.advance();
    }
    res.sort(sorterTransportes);
    return res;
}

bool Aeroporto::sorterTransportes(const Transporte &t1, const Transporte &t2) {
    return t1.getHoraPartida() < t2.getHoraPartida();
}

std::stack<std::string> Aeroporto::funcs() {
    stack<string> temp;
    temp.push("getName()");
    temp.push("setName()");
    temp.push("getCity()");
    temp.push("setCity()");
    temp.push("getCountry()");
    temp.push("setCountry()");
    temp.push("addTransporte()");
    temp.push("removeTransporte()");
    temp.push("getNearestTransport()");
    temp.push("getNextTransport()");
    temp.push("addFuncionario()");
    temp.push("removeFuncionario()");
    temp.push("addAviao()");
    temp.push("removeAviao()");
    temp.push("getPlanesDepartingTo()");
    temp.push("getFuncionariosByNames()");
    temp.push("searchStorageByName()");
    temp.push("searchTransportesTipo()");
    return temp;
}

bool Aeroporto::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getName")
        cout << name << endl;
    else if (nomeFunc == "setName")
    {
        cout << "input name: ";
        string temp;
        getline(cin, temp);
        setName(temp);
    }
    else if (nomeFunc == "getCity")
        cout << city << endl;
    else if (nomeFunc == "setCity")
    {
        cout << "input city: ";
        string temp;
        getline(cin, temp);
        setCity(temp);
    }
    else if (nomeFunc == "getCountry")
        cout << country << endl;
    else if (nomeFunc == "setCountry")
    {
        cout << "input country: ";
        string temp;
        getline(cin, temp);
        setCountry(temp);
    }
    else if (nomeFunc == "addTransporte")
    {
        cout << "input distancia: ";
        string temp1;
        getline(cin, temp1);
        cout << "input hora chegada (hh:mm): ";
        string temp2;
        getline(cin, temp2);
        cout << "input hora partida (hh:mm): ";
        string temp3;
        getline(cin, temp3);
        cout << "input tipo (autocarro/metro/comboio): ";
        string temp4;
        getline(cin, temp4);
        try {
            auto temp5 = Transporte(stoi(temp1), temp2, temp3, temp4, name);
            addTransporte(temp5);
            Terminal::updateVec();
        } catch (exception &e)
        {
            cout << "Function failed.";
        }
    }
    else if (nomeFunc == "removeTransporte")
    {
        cout << "input transporte (index): ";
        string temp;
        getline(cin, temp);
        try {
            if (stoi(temp) < getV("transportes")->size() && stoi(temp) >= 0)
            {
                BSTItrIn<Transporte> it(transportes);
                for (int i = 0; i < stoi(temp); i++)
                {
                    it.advance();
                }
                transportes.remove(it.retrieve());
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        } catch (exception &e)
        {
            cout << "Function failed.";
        }
    }
    else if (nomeFunc == "getNearestTransport")
    {
        auto temp1 = getNearestTransport();
        if (temp1.getHoraChegada().getHora() == -1)
        {
            cout << "Not found." << endl;
        }
        else
        {
            cout << temp1.getObjectName() << endl;
        }
    }
    else if (nomeFunc == "getNextTransport")
    {
        auto temp1 = getNextTransport();
        if (temp1.getHoraChegada().getHora() == -1)
        {
            cout << "Not found." << endl;
        }
        else
        {
            cout << temp1.getObjectName() << endl;
        }
    }
    else if (nomeFunc == "addFuncionario")
    {
        cout << "input telemovel: ";
        string temp1;
        getline(cin, temp1);
        cout << "input nome: ";
        string temp2;
        getline(cin, temp2);
        cout << "input morada: ";
        string temp3;
        getline(cin, temp3);
        try {
            auto t = new Funcionario(stoi(temp1), temp2, temp3, this);
            addFuncionario(t);
            Terminal::updateVec();
        } catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "removeFuncionario")
    {
        cout << "input funcionario (index): ";
        string temp;
        getline(cin, temp);
        try
        {
            if (stoi(temp) < funcionarios.size() && stoi(temp) >= 0)
            {
                removeFuncionario(*funcionarios[stoi(temp)]);
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "addAviao")
    {
        cout << "input capacidade: ";
        string temp1;
        getline(cin, temp1);
        cout << "input matricula (6 letras): ";
        string temp2;
        getline(cin, temp2);
        cout << "input tipo: ";
        string temp3;
        getline(cin, temp3);
        try
        {
            addAviao(new Aviao(stoi(temp1), temp2, temp3));
            Terminal::updateVec();
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "removeAviao")
    {
        cout << "input aviao (index): ";
        string temp;
        getline(cin, temp);
        try
        {
            if (stoi(temp) < avioes.size() && stoi(temp) >=0)
            {
                auto temp2 = avioes.begin();
                advance(temp2, stoi(temp));
                removeAviao(*temp2);
                Terminal::updateVec();
            }
            else
            {
                cout << "Object not found." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getPlanesDepartingTo")
    {
        string temp1;
        cout << "input country: ";
        getline(cin, temp1);
        auto lista = getPlanesDepartingTo(temp1);
        if (lista.empty())
            cout << "empty." << endl;
        else
            for (auto &t:lista)
                {cout << t->getObjectName() << endl;}
        return true;
    }
    else if (nomeFunc == "getFuncionariosByNames")
    {
        cout << "input name: ";
        string temp1;
        getline(cin, temp1);
        auto lista = getFuncionariosByNames(temp1);
        if (lista.empty())
            cout << "empty." << endl;
        else
            for (auto &t:lista)
            {cout << t->getObjectName() << endl;}
        return true;
    }
    else if (nomeFunc == "searchStorageByName")
    {
        cout << "input name: ";
        string temp1;
        getline(cin, temp1);
        auto lista = searchStorageByName(temp1);
        if (lista.empty())
            cout << "empty." << endl;
        else
            for (auto &t:lista)
            {cout << t->getObjectName() << endl;}
        return true;
    }
    else if (nomeFunc == "searchTransportesTipo")
    {
        cout << "input tipo (autocarro/metro/comboio): ";
        string temp1;
        getline(cin, temp1);
        try{
            if (!(temp1=="autocarro" || temp1 == "metro" || temp1=="comboio"))
                throw exception();
            auto lista = searchTransportesTipo(temp1);
            for (auto t:lista)
            {
                cout << t.getObjectName() << endl;
            }
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else
    {
        return false;
    }
    return true;
}

std::vector<Terminal *> *Aeroporto::getV(std::string nameVector)
{
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "funcionarios")
    {
        for (auto f : funcionarios)
        {
            temp->push_back(f);
        }
    }
    else if (nameVector == "transportes")
    {
        BSTItrIn<Transporte> it(transportes);
        while (!it.isAtEnd())
        {
            auto t = it.retrieve();
            Transporte *tmp = new Transporte(t.getDistancia(), t.getHoraChegada(), t.getHoraPartida(), t.getTipo(),t.getNomeAeroporto());
            temp->push_back(tmp);
            it.advance();
        }
    }
    else if (nameVector == "carrinhos")
    {
        for (auto c : carrinhos)
        {
            temp->push_back(c);
        }
    }
    else if (nameVector == "avioes")
    {
        for (auto a : avioes)
        {
            temp->push_back(a);
        }
    }
    else if (nameVector == "storage")
    {
        std::queue<Mala*> s = getStorage();
        while (!s.empty())
        {
            temp->push_back(s.front());
            s.pop();
        }
    }
    return temp;
}

bool operator<(const Aeroporto &lhs, const Aeroporto &rhs) {
    if (lhs.name < rhs.name)
        return true;
    if (lhs.name == rhs.name && lhs.city < rhs.city)
        return true;
    if (lhs.name == rhs.name && lhs.city == rhs.city && lhs.country < rhs.country)
        return true;
    return false;
}


