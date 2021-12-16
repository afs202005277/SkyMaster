#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aviao.h"

#include "Tempo.h"
using namespace std;

void processInput(const string &line, vector<string> & arguments){
    istringstream stream(line);
    string argument;
    int index=0;
    while(stream >> argument)
    {
        arguments[index] = argument;
        index++;
    }
}

int main() {
    ifstream input;
    input.open(R"(D:\Importante\FEUP\2 ano\1 semestre\AED\Projeto1\povoar)");
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
        vector<string> arguments;
        object = line.substr(0, line.find(':'));
        if (object == "Aeroporto")
        {
            arguments.resize(3);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                aeroportos.emplace_back(Aeroporto(arguments[0], arguments[1], arguments[2]));
            }
        }
        else if (object == "Transporte")
        {
            arguments.resize(4);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                transportes.emplace_back(Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]));
            }
        }
        else if (object == "Funcionario")
        {
            arguments.resize(4);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                Aeroporto required = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                funcionarios.emplace_back(Funcionario(stoi(arguments[0]), arguments[1], arguments[2], &required));
            }
        }
        else if(object == "Servico")
        {
            arguments.resize(3);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                Funcionario required = *std::find(funcionarios.begin(), funcionarios.end(), Funcionario(stoi(arguments[1]), "", "", nullptr));
                servicos.emplace_back(Servico(arguments[0], &required, arguments[2]));
            }
        }
        else if (object == "Passageiro")
        {
            arguments.resize(3);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                passageiros.emplace_back(Passageiro(arguments[0], stoi(arguments[1]), stoi(arguments[2])));
            }
        }
        else if (object == "Mala")
        {
            arguments.resize(2);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                Passageiro required = *std::find(passageiros.begin(), passageiros.end(), Passageiro("", 0, stoi(arguments[0])));
                malas.emplace_back(Mala(&required, stof(arguments[1])));
            }
        }
        else if (object == "Aviao")
        {
            arguments.resize(3);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                avioes.emplace_back(Aviao(stoi(arguments[0]), arguments[1], arguments[2]));
            }
        }
        else if (object == "Voo")
        {
            arguments.resize(7);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                Aeroporto origem = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                Aeroporto destino = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[4], "", ""));
                Aviao aviao = *std::find(avioes.begin(), avioes.end(), Aviao(0, arguments[5], std::__cxx11::string()));
                voos.emplace_back(Voo(stoi(arguments[0]), stoi(arguments[1]), arguments[2], &origem, &destino, &aviao, arguments[6]));
            }
        }
        else if (object == "CarrinhoTransporte")
        {
            arguments.resize(4);
            while(getline(input, instruction) && instruction.find(':') != string::npos) {
                processInput(instruction, arguments);
                Aeroporto required = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                carrinhosTransporte.emplace_back(CarrinhoTransporte(stoi(arguments[0]), stoi(arguments[1]), stoi(arguments[2]), &required));
            }
        }
    }
    return 0;
}
