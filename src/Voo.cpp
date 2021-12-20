#include "Voo.h"

Voo::Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
         Tempo &partida, int bilhetesVendidos)
        : nVoo(nVoo), duracao(duracao), bilhetesVendidos(bilhetesVendidos), dataPartida(dataPartida), origem(origem),
          destino(destino), aviao(aviao), horaPartida(partida) {aviao->addToPlanoVoo(this);}

unsigned int Voo::getNVoo() const {
    return nVoo;
}

unsigned int Voo::getDuracao() const {
    return duracao;
}

void Voo::setDuracao(unsigned int duracao) {
    Voo::duracao = duracao;
}

unsigned int Voo::getbilhetesVendidos() const {
    return bilhetesVendidos;
}

void Voo::setbilhetesVendidos(unsigned int bilhetesVendidos) {
    Voo::bilhetesVendidos = bilhetesVendidos;
}

const Data &Voo::getDataPartida() const {
    return dataPartida;
}

void Voo::setDataPartida(const Data &dataPartida) {
    Voo::dataPartida = dataPartida;
}

Aeroporto *Voo::getOrigem() const {
    return origem;
}

void Voo::setOrigem(Aeroporto *origem) {
    Voo::origem = origem;
}

Aeroporto *Voo::getDestino() const {
    return destino;
}

void Voo::setDestino(Aeroporto *destino) {
    Voo::destino = destino;
}

const list<Passageiro *> & Voo::getPassageiros() const {
    return passageiros;
}

bool Voo::sellBilhete(bool levaBagagem, Passageiro *passageiro) {
    if (this->bilhetesVendidos < this->aviao->getCapacidade())
    {
        Bilhete *temp;
        temp = new Bilhete(this->nVoo, levaBagagem, passageiro);
        this->bilhetesVendidos++;
        passageiro->addBilhete(temp);
        return true;
    }
    return false;
}

bool Voo::sellBilheteGroup(const vector<bool> &levaBagagem, const vector<Passageiro *> &passageiros) {
    unsigned int nPassageiros = levaBagagem.size();
    if (this->bilhetesVendidos + nPassageiros > aviao->getCapacidade())
        return false;
    for (int i=0;i<nPassageiros;i++)
    {
        this->sellBilhete(levaBagagem[i], passageiros[i]);
    }
    return true;
}

Aviao *Voo::getAviao() const {
    return aviao;
}

void Voo::setAviao(Aviao *aviao) {
    Voo::aviao = aviao;
}

void Voo::addPassageiro(Passageiro *p) {
    passageiros.push_back(p);
}

void Voo::setNVoo(unsigned int nVoo) {
    Voo::nVoo = nVoo;
}

void Voo::setPassageiros(const list<Passageiro *> &passageiros) {
    Voo::passageiros = passageiros;
}

const Tempo &Voo::getHoraPartida() const {
    return horaPartida;
}

void Voo::setHoraPartida(const Tempo &horaPartida) {
    Voo::horaPartida = horaPartida;
}

bool operator<(const Voo &lhs, const Voo &rhs) {
    if (lhs.dataPartida < rhs.dataPartida)
        return true;
    if (rhs.dataPartida == lhs.dataPartida && lhs.horaPartida < rhs.horaPartida)
        return true;
    return false;
}

bool operator>(const Voo &lhs, const Voo &rhs) {
    return rhs < lhs;
}

bool operator<=(const Voo &lhs, const Voo &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Voo &lhs, const Voo &rhs) {
    return !(lhs < rhs);
}

Voo::Voo(int nVoo, int duracao, string dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
         string partida) : nVoo(nVoo), duracao(duracao), dataPartida(Data(dataPartida)), origem(origem),
                           destino(destino), aviao(aviao), horaPartida(partida), bilhetesVendidos(0) {aviao->addToPlanoVoo(this);}

bool operator==(const Voo &lhs, const Voo &rhs) {
    return lhs.nVoo == rhs.nVoo;
}

std::string Voo::getObjectName() {
    return "Voo (" + std::to_string(nVoo) + ", " + std::to_string(duracao) + ", " + dataPartida.getDate() + ", " + origem->getName() + ", " + destino->getName() + ", " + aviao->getMatricula() + ", " + horaPartida.getTempo() + ")";
}

std::string Voo::getObjectID() {
    return to_string(nVoo);
}

std::stack<std::string> Voo::funcs() {
    stack<string> temp;
    temp.push("getHoraPartida()");
    temp.push("setHoraPartida()");
    temp.push("setAviao()");
    temp.push("getNVoo()");
    temp.push("setNVoo()");
    temp.push("getDuracao()");
    temp.push("setDuracao()");
    temp.push("getLotacoAtual()");
    temp.push("setbilhetesVendidos()");
    temp.push("getDataPartida()");
    temp.push("setDataPartida()");
    temp.push("setOrigem()");
    temp.push("getOrigem()");
    temp.push("setDestino()");
    temp.push("getDestino");
    temp.push("sellBilhete()");
    temp.push("sellBilheteGroup()");
    return temp;
}

bool Voo::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getHoraPartida")
        cout << to_string(getHoraPartida().getHora()) + ":" + to_string(getHoraPartida().getMinuto()) + ":" + to_string(getHoraPartida().getSegundo()) << endl;
    else if (nomeFunc == "setHoraPartida")
    {
        cout << "input hora (HH:MM:SS): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setHoraPartida(Tempo(temp1));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setAviao")
    {
        cout << "input aviao (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < origem->getAvioes().size() && stoi(temp1) >= 0) {
                auto t = origem->getAvioes().begin();
                advance(t, stoi(temp1));
                setAviao(*t);
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
    else if (nomeFunc == "getNVoo")
        cout << getNVoo() << endl;
    else if (nomeFunc == "setNVoo")
    {
        cout << "input nVoo: ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setNVoo(stoi(temp1));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getDuracao")
        cout << getDuracao() << endl;
    else if (nomeFunc == "setDuracao")
    {
        cout << "input duracao: ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setDuracao(stoi(temp1));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getbilhetesVendidos")
        cout << getbilhetesVendidos() << endl;
    else if (nomeFunc == "setbilhetesVendidos")
    {
        cout << "input lotacao atual: ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setbilhetesVendidos(stoi(temp1));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getDataPartida()")
        cout << getDataPartida() << endl;
    else if (nomeFunc == "setDataPartida")
    {
        cout << "input data partida (YYYY/MM/DD): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setDataPartida(Data(temp1));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setOrigem")
    {
        cout << "input aeroporto origem (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::aeroportos.size())
                throw exception();
            setOrigem(Terminal::aeroportos[stoi(temp1)]);
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setDestino")
    {
        cout << "input aeroporto destino (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::aeroportos.size())
                throw exception();
            setDestino(Terminal::aeroportos[stoi(temp1)]);
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "sellBilhete")
    {
        cout << "input levaBagagem? (y/n): ";
        string temp1;
        getline(cin, temp1);
        cout << "input passageiro (index): ";
        string temp2;
        getline(cin, temp2);
        try
        {
            if (stoi(temp2) < 0 || stoi(temp2) >=Terminal::passageiros.size())
                throw exception();
            if (temp1 == "y")
            {
                cout << (sellBilhete(true, Terminal::passageiros[stoi(temp2)]) ? "Sold." : "Not sold.") << endl;
            }
            else if (temp1 == "n")
            {
                cout << (sellBilhete(false, Terminal::passageiros[stoi(temp2)]) ? "Sold." : "Not sold.") << endl;
            }
            else
            {
                cout << "Function failed." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getOrigem")
    {
        cout << "Aeroporto (" + origem->getName() << ", " << origem->getCity() << ", " << origem->getCountry() + ")" << endl;
        return true;
    }
    else if (nomeFunc == "getDestino")
    {
        cout << "Aeroporto (" + destino->getName() << ", " << destino->getCity() << ", " << destino->getCountry() + ")" << endl;
        return true;
    }
    else if (nomeFunc == "sellBilheteGroup")
    {
        cout << "input passageiro (index): ";
        string temp1;
        getline(cin, temp1);
        cout << "input levaBagagem? (y/n): ";
        string temp2;
        getline(cin, temp2);
        vector<bool> lb;
        set<Passageiro*> p;
        try
        {
            if ((temp2 == "y" || temp2 == "n") && stoi(temp1) < Terminal::passageiros.size() && stoi(temp1) >= 0)
            {
                lb.push_back(temp2=="y");
                p.insert(Terminal::passageiros[stoi(temp1)]);
                bool c = true;
                while (c) {
                    cout << "input passageiro (index) or any letter to exit: ";
                    getline(cin, temp1);
                    try {
                        stoi(temp1);
                        cout << "input levaBagagem? (y/n): ";
                        getline(cin, temp2);
                        if ((temp2 == "y" || temp2 == "n") && stoi(temp1) < Terminal::passageiros.size() && stoi(temp1) >= 0)
                        {
                            int temp4 = p.size();
                            p.insert(Terminal::passageiros[stoi(temp1)]);
                            if (p.size() != temp4)
                                lb.push_back(temp2 == "y");
                        }
                        else
                        {
                            throw exception();
                        }
                    }
                    catch (exception &e) {
                        cout << "Finishing." << endl;
                        vector<Passageiro *> temp3;
                        for (auto s: p) {
                            temp3.push_back(s);
                        }
                        sellBilheteGroup(lb, temp3);
                        c = false;
                    }
                }
                Terminal::updateVec();
            }
            else
            {
                cout << "Function failed." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else
        return false;
    return true;
}

std::vector<Terminal *> *Voo::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "viagem")
    {
        temp->push_back(origem);
        temp->push_back(destino);
    }
    else if (nameVector == "passageiros")
    {
        for (auto &p : passageiros)
        {
            temp->push_back(p);
        }
    }
    else if (nameVector == "aviao")
    {
        temp->push_back(aviao);
    }
    return temp;
}

