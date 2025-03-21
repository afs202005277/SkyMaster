#include "Servico.h"

Tipo Servico::getTipo() const {
    return tipo;
}

void Servico::setTipo(Tipo tipo) {
    Servico::tipo = tipo;
}

const Data &Servico::getData() const {
    return data;
}

void Servico::setData(const Data &data) {
    Servico::data = data;
}

const Funcionario * Servico::getFuncionario() const {
    return funcionario;
}

void Servico::setFuncionario(Funcionario *funcionario) {
    Servico::funcionario = funcionario;
}

Servico::Servico(const Data &data, Funcionario *funcionario, Tipo tipo) : data(data), funcionario(funcionario),
                                                                          tipo(tipo) {}

Servico::Servico(const string &data, Funcionario *funcionario, const string &tipo) : data(data), funcionario(funcionario){
    if (tipo == "manutencao")
        this->tipo=manutencao;
    else
        this->tipo=limpeza;
}

std::string Servico::getObjectName() {
    string s = to_string(funcionario->getTelemovel());
    if (tipo==limpeza)
        return "Servico (" + data.getDate() + ", " + s + ", " + "limpeza)";
    else
        return "Servico (" + data.getDate() + ", " + s + ", " + "manutencao)";
}

std::string Servico::getObjectID() {
    return data.getDate();
}

std::stack<std::string> Servico::funcs() {
    stack<string> temp;
    temp.push("getTipo()");
    temp.push("setTipo()");
    temp.push("getData()");
    temp.push("setData()");
    temp.push("setFuncionario()");
    return temp;
}

std::vector<Terminal *> *Servico::getV(std::string nameVector) {
    vector<Terminal *> *temp = new vector<Terminal*>;
    if (nameVector == "funcionario")
    {
        temp->push_back(funcionario);
    }
    return temp;
}

bool Servico::findFunc(std::string nomeFunc) {
    nomeFunc = processString(nomeFunc, '(', 1, false);
    if (nomeFunc == "getTipo"){
        if (tipo == manutencao)
            cout << "manutencao" << endl;
        else
            cout << limpeza << endl;
        return true;
    }
    else if (nomeFunc == "setTipo"){
        cout << "Input tipo: ";
        string tmp;
        getline(cin, tmp);
        if (tmp == "manutencao")
        {
            tipo = manutencao;
            return true;
        }
        else if (tmp == "limpeza"){
            tipo = limpeza;
            return true;
        }
        
        return false;
    }
    else if (nomeFunc == "getData"){
        cout << data;
        return true;
    }
    else if (nomeFunc == "setData"){
        cout << "input data (YYYY/MM/DD): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            setData(Data(temp1));
            return true;
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
            return true;
        }
    }
    else if (nomeFunc == "setFuncionario"){
        cout << "input funcionario (index): ";
        string temp1;
        getline(cin, temp1);
        try
        {
            if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::funcionarios.size())
                throw exception();
            setFuncionario(Terminal::funcionarios[stoi(temp1)]);
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

bool operator<(const Servico &lhs, const Servico &rhs) {
    if (lhs.data < rhs.data)
        return true;
    if (lhs.data == rhs.data && lhs.funcionario->getNome() < rhs.funcionario->getNome())
        return true;
    if (lhs.data == rhs.data && lhs.funcionario->getNome() < rhs.funcionario->getNome() && lhs.tipo < rhs.tipo)
        return true;
    return false;
}

bool operator==(const Servico &lhs, const Servico &rhs) {
           return lhs.data == rhs.data &&
           lhs.funcionario == rhs.funcionario &&
           lhs.tipo == rhs.tipo;
}
