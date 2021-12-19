#include "CarrinhoTransporte.h"

CarrinhoTransporte::CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aeroporto *aeroporto, Aviao *aviao) {
    this->nCarruagens = nCarruagens;
    this->nPilhas = nPilhas;
    this->nMalas = nMalas;
    vector<vector<stack<Mala*>>> a(this->nCarruagens);
    this->carga = a;
    for (auto &temp : this->carga)
    {
        vector<stack<Mala*>> t(this->nPilhas);
        temp = t;
    }
    this->aviao=aviao;
    this->aeroporto = aeroporto;
    aeroporto->addCarrinho(this);
}

int CarrinhoTransporte::getNCarruagens() const {
    return nCarruagens;
}

void CarrinhoTransporte::setNCarruagens(int nCarruagens) {
    CarrinhoTransporte::nCarruagens = nCarruagens;
}

int CarrinhoTransporte::getNPilhas() const {
    return nPilhas;
}

void CarrinhoTransporte::setNPilhas(int nPilhas) {
    CarrinhoTransporte::nPilhas = nPilhas;
}

int CarrinhoTransporte::getNMalas() const {
    return nMalas;
}

void CarrinhoTransporte::setNMalas(int nMalas) {
    CarrinhoTransporte::nMalas = nMalas;
}

bool CarrinhoTransporte::addMalas(vector<Mala*> m) {
    for (auto f : m) {
        for (vector<stack<Mala*>> &carruagem : this->carga)
        {
            for (stack<Mala*> &carrinho : carruagem)
            {
                if (carrinho.size() < nMalas)
                {
                    carrinho.push(f);
                    return true;
                }
            }
            if (carruagem.size() < this->nPilhas) {
                stack<Mala*> temp;
                temp.push(f);
                carruagem.push_back(temp);
                return true;
            }
        }
    }
    return false;
}

bool CarrinhoTransporte::addMala(Mala *&pMala) {
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            if (carrinho.size() < nMalas)
            {
                carrinho.push(pMala);
                return true;
            }
        }
        if (carruagem.size() < this->nPilhas) {
            stack<Mala*> temp;
            temp.push(pMala);
            carruagem.push_back(temp);
            return true;
        }
    }
    return false;
}

void CarrinhoTransporte::descarregarMalasAviao()
{
    if (aviao != nullptr) {
        for (vector<stack<Mala *>> &carruagem: this->carga) {
            for (stack<Mala *> &carrinho: carruagem) {
                while (!carrinho.empty()) {
                    auto temp1 = carrinho.top();
                    auto *temp2 = new Mala(temp1->getDono(), temp1->getPeso(), aviao);
                    aviao->addMala(temp2);
                    carrinho.pop();
                }
            }
        }
    }
}

const vector<vector<stack<Mala *>>> &CarrinhoTransporte::getCarga() const {
    return carga;
}

void CarrinhoTransporte::setCarga(const vector<vector<stack<Mala *>>> &carga) {
    CarrinhoTransporte::carga = carga;
}

Aviao *CarrinhoTransporte::getAviao() const {
    return aviao;
}

void CarrinhoTransporte::setAviao(Aviao *aviao) {
    CarrinhoTransporte::aviao = aviao;
}

void CarrinhoTransporte::descarregarMalasAeroporto() {
    std::queue<Mala*> res;
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            while (!carrinho.empty())
            {
                res.push(carrinho.top());
                carrinho.pop();
            }
        }
    }
    aeroporto->addMalas(res);
}

std::string CarrinhoTransporte::getObjectName() {
    return "CarrinhoTransporte (" + to_string(nCarruagens) + ", " + to_string(nPilhas) + ", " + to_string(nMalas) + ", " + aeroporto->getName() + ")";
}

std::string CarrinhoTransporte::getObjectID() {
    return to_string(nCarruagens);
}

bool operator<(const CarrinhoTransporte &lhs, const CarrinhoTransporte &rhs) {
    if (lhs.nCarruagens < rhs.nCarruagens)
        return true;
    if (lhs.nCarruagens == rhs.nCarruagens && lhs.nPilhas < rhs.nPilhas)
        return true;
    if (lhs.nCarruagens == rhs.nCarruagens && lhs.nPilhas == rhs.nPilhas && lhs.nMalas < rhs.nMalas)
        return true;
    if (lhs.nCarruagens == rhs.nCarruagens && lhs.nPilhas == rhs.nPilhas && lhs.nMalas == rhs.nMalas && lhs.aeroporto < rhs.aeroporto)
        return true;
    return false;
}

std::stack<std::string> CarrinhoTransporte::funcs() {
    stack<string> temp;
    temp.push("getNCarruagens()");
    temp.push("setNCarruagens()");
    temp.push("getNPilhas()");
    temp.push("setNPilhas()");
    temp.push("getNMalas()");
    temp.push("setNMalas()");
    temp.push("addMalas()");
    temp.push("descarregarMalasAviao()");
    temp.push("descarregarMalasAeroporto()");
    return temp;
}

bool CarrinhoTransporte::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getNCarruagens"){
        cout << getNCarruagens() << endl;
    }
    else if (nomeFunc == "setNCarruagens"){
        cout << "input NCarruagens: ";
        string temp;
        getline(cin, temp);
        try {
            setNCarruagens(stoi(temp));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getNPilhas"){
        cout << getNPilhas() << endl;
    }
    else if (nomeFunc == "setNPilhas"){
        cout << "input NPilhas: ";
        string temp;
        getline(cin, temp);
        try {
            setNPilhas(stoi(temp));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "getNMalas"){
        cout << getNMalas() << endl;
    }
    else if (nomeFunc == "setNMalas"){
        cout << "input NMalas: ";
        string temp;
        getline(cin, temp);
        try {
            setNMalas(stoi(temp));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "addMalas"){
        cout << "input passageiro (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            auto temp2 = Terminal::passageiros[stoi(temp1)]->getMalas();
            vector<Mala*> temp3;
            while (!temp2.empty())
            {
                temp3.push_back(temp2.front());
                temp2.pop();
            }
            addMalas(temp3);
            Terminal::updateVec();
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "descarregarMalasAviao"){
        descarregarMalasAviao();
        Terminal::updateVec();
    }
    else if (nomeFunc == "descarregarMalasAeroporto"){
        descarregarMalasAeroporto();
        Terminal::updateVec();
    }
    else {
        return false;
    }
    return true;
}

std::vector<Terminal *> *CarrinhoTransporte::getV(std::string nameVector)
{
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "carga")
    {
        for (auto c : carga)
        {
            for (auto p : c)
            {
                auto m = p;
                while (!m.empty())
                {
                    temp->push_back(m.top());
                    m.pop();
                }
            }
        }
    }
    else if (nameVector == "aviao")
    {
        temp->push_back(aviao);
    }
    else if (nameVector == "aeroporto")
    {
        temp->push_back(aeroporto);
    }
    return temp;
}
