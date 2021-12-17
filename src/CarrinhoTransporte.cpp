#include "CarrinhoTransporte.h"

CarrinhoTransporte::CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aeroporto *aeroporto, Aviao *aviao) {
    this->nCarruagens = nCarruagens;
    this->nPilhas = nPilhas;
    this->nMalas = nMalas;
    this->carga = vector<vector<stack<Mala*>>>(this->nCarruagens);
    for (auto &temp : this->carga)
    {
        temp = vector<stack<Mala*>>(this->nPilhas);
    }
    this->aviao=aviao;
    this->aeroporto = aeroporto;
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

bool CarrinhoTransporte::addMala(Mala *m) {
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            if (carrinho.size() < nMalas)
            {
                carrinho.push(m);
                return true;
            }
        }
        if (carruagem.size() < this->nPilhas) {
            stack<Mala*> temp;
            temp.push(m);
            carruagem.push_back(temp);
            return true;
        }
    }
    return false;
}

void CarrinhoTransporte::descarregarMalasAviao()
{
    for (vector<stack<Mala*>> &carruagem : this->carga)
    {
        for (stack<Mala*> &carrinho : carruagem)
        {
            while (!carrinho.empty())
            {
                aviao->addMala(carrinho.top());
                carrinho.pop();
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
    aeroporto->setStorage(res);
}

std::string CarrinhoTransporte::getObjectName() {
    return "CarrinhoTransporte (" + aviao->getMatricula() +  ", " + aeroporto->getName() + ", " + to_string(nCarruagens) + ", " +
            to_string(nPilhas) + ", " + to_string(nMalas) + ")";
}

std::string CarrinhoTransporte::getObjectID() {
    return aviao->getMatricula();
}

std::stack<std::string> CarrinhoTransporte::funcs() {
    stack<string> temp;
    temp.push("getNCarruagens()");
    temp.push("setNCarruagens()");
    temp.push("getNPilhas()");
    temp.push("setNPilhas()");
    temp.push("getNMalas()");
    temp.push("setNMalas()");
    temp.push("addMala()");
    temp.push("descarregarMalasAviao()");
    temp.push("descarregarMalasAeroporto()");
    return temp;
}

bool CarrinhoTransporte::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getNCarruagens"){
        cout << getNCarruagens() << endl;
        return true;
    }
    else if (nomeFunc == "setNCarruagens"){
        cout << "input NCarruagens: ";
        string temp;
        cin >> temp;
        try {
            setNCarruagens(stoi(temp));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getNPilhas"){
        cout << getNPilhas() << endl;
        return true;
    }
    else if (nomeFunc == "setNPilhas"){
        cout << "input NPilhas: ";
        string temp;
        cin >> temp;
        try {
            setNPilhas(stoi(temp));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getNMalas"){
        cout << getNMalas() << endl;
        return true;
    }
    else if (nomeFunc == "setNMalas"){
        cout << "input NMalas: ";
        string temp;
        cin >> temp;
        try {
            setNMalas(stoi(temp));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "addMala"){
        lal
    }
    else if (nomeFunc == "descarregarMalasAviao"){
        descarregarMalasAviao();
        return true;
    }
    else if (nomeFunc == "descarregarMalasAeroporto"){
        descarregarMalasAeroporto();
        return true;
    }
    else{
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

}
