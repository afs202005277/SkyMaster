#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aviao.h"
#include "Tempo.h"
#include "Terminal.h"

using namespace std;

void processInput(const string &line, vector<string> & arguments){
    istringstream stream(line);
    string argument;
    int index=0;
    while(stream >> argument)
    {
        if (argument.find(',') != string::npos)
        {
            arguments[index] += argument.substr(0, argument.find(','));
            index++;
        }
        else
            arguments[index] += argument + " ";
    }
    string tmp = arguments[arguments.size()-1];
    tmp = tmp.substr(0, tmp.find_last_of(' '));
    arguments[arguments.size()-1] = tmp;
}

template<class  T>
T* find(list<T> &l, T val){
    for (auto it = l.begin();it!=l.end();it++)
    {
        if (*it == val)
            return &(*it);
    }
    cout << "Not found" << endl;
}

vector<Aeroporto> Terminal::aeroportos;
vector<Passageiro> Terminal::passageiros;
vector<Voo> Terminal::voos;
vector<Funcionario> Terminal::funcionarios;


int main() {
    Data d1(2002, 6, 23), d2(2010, 8, 10);
    bool f = d1<d2;
    cout << f << endl;

    ifstream input;
    input.open(R"(/Users/pedrofonseca/Documents/FEUP/AED/AED1/povoar.txt)");
    if (!input.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }
    list<Aeroporto> aeroportos;
    list<Transporte> transportes;
    list<Funcionario> funcionarios;
    list<Servico> servicos;
    list<Passageiro> passageiros;
    list<Mala> malas;
    list<Aviao> avioes;
    list<Voo> voos;
    list<CarrinhoTransporte> carrinhosTransporte;
    string line, object, instruction;
    while(getline(input, line))
    {
        object = line.substr(0, line.find(':'));
        if (object == "Aeroporto")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                aeroportos.emplace_back(Aeroporto(arguments[0], arguments[1], arguments[2]));
            }
        }
        else if (object == "Transporte")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                transportes.emplace_back(Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]));
            }
        }
        else if (object == "Funcionario")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[3], "", "");
                auto required = find(aeroportos, tmp);
                funcionarios.emplace_back(Funcionario(stoi(arguments[0]), arguments[1], arguments[2], required));
            }
        }
        else if (object == "Servico")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Funcionario tmp(stoi(arguments[1]), "", "", nullptr);
                auto required = find(funcionarios, tmp);
                servicos.emplace_back(Servico(arguments[0], required, arguments[2]));
            }
        }
        else if (object == "Passageiro")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                passageiros.emplace_back(Passageiro(arguments[0], stoi(arguments[1]), stoi(arguments[2])));
            }
        }
        else if (object == "Mala")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(2);
                processInput(instruction, arguments);
                Passageiro tmp(Passageiro("", 0, stoi(arguments[0])));
                auto required = find(passageiros,tmp);
                malas.emplace_back(Mala(required, stof(arguments[1])));
            }
        }
        else if (object == "Aviao")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                avioes.emplace_back(Aviao(stoi(arguments[0]), arguments[1], arguments[2]));
            }
        }
        else if (object == "Voo")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(7);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[3], "", "");
                auto origem = find(aeroportos, tmp);
                tmp = Aeroporto(arguments[4], "", "");
                auto destino = find(aeroportos, tmp);
                Aviao tmp_aviao(0, arguments[5], "");
                auto aviao = find(avioes, tmp_aviao);
                voos.emplace_back(Voo(stoi(arguments[0]), stoi(arguments[1]), arguments[2], origem, destino, aviao, arguments[6]));
            }
        }
        else if (object == "CarrinhoTransporte")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[3], "", "");
                auto required = find(aeroportos, tmp);
                carrinhosTransporte.emplace_back(CarrinhoTransporte(stoi(arguments[0]), stoi(arguments[1]), stoi(arguments[2]), required));
            }
        }
    }
    return 0;
}
