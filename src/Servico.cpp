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

Servico::Servico(const string &data, Funcionario *funcionario, const string &tipo) {
    this->data=Data(data);
    if (tipo == "manutencao")
        this->tipo=manutencao;
    else
        this->tipo=limpeza;
}

std::string Servico::getObjectName() {
    return "Servico (" + to_string(funcionario->getTelemovel()) + ", " + data.getDate() + ", " + to_string(tipo) + ")";
}

std::string Servico::getObjectID() {
    return to_string(funcionario->getTelemovel());
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
    vector<Terminal *> *temp;
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
        string tmp;
        cin >> tmp;
        if (tmp == "manutencao")
        {
            tipo = manutencao;
            return true;
        }
        else if (tmp == "limpeza"){
            tipo = limpeza;
            return true;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else if (nomeFunc == "getData"){
        cout << data << endl;
        return true;
    }
    else if (nomeFunc == "setData"){
        cout << "input data (YYYY/MM/DD): ";
        string temp1;
        cin >> temp1;
        try
        {
            setData(Data(temp1));
        }
        catch (exception &e)
        {
            cout << "Function failed." << endl;
        }
    }
    else if (nomeFunc == "setFuncionario"){
        lalal
    }
    else{
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
