#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Aviao.h"

#include "Tempo.h"
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

string processString(string &s, char y, int occurence=1, bool after=false)
{
    std::string::size_type pos = 0;
    for (int i = 0; i < occurence; i++) {
        pos = s.find(y, pos);
        if (pos != std::string::npos)
        {
            if (after)
                return s.substr(pos+1, s.size()-pos-1);
            else
                return s.substr(0, pos);
        }
        else
        {
            return s;
        }
    }
    return s;
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
            vector<string> arguments(4);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                transportes.emplace_back(Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]));
            }
        }
        else if (object == "Funcionario")
        {
            vector<string> arguments(4);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                auto required = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                funcionarios.emplace_back(Funcionario(stoi(arguments[0]), arguments[1], arguments[2], &required));
            }
        }
        else if(object == "Servico")
        {
            vector<string> arguments(3);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                Funcionario required = *find(funcionarios.begin(), funcionarios.end(), Funcionario(stoi(arguments[1]), "", "", nullptr));
                servicos.emplace_back(Servico(arguments[0], &required, arguments[2]));
            }
        }
        else if (object == "Passageiro")
        {
            vector<string> arguments(3);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                passageiros.emplace_back(Passageiro(arguments[0], stoi(arguments[1]), stoi(arguments[2])));
            }
        }
        else if (object == "Mala")
        {
            vector<string> arguments(2);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                Passageiro required = *find(passageiros.begin(), passageiros.end(), Passageiro("", 0, stoi(arguments[0])));
                malas.emplace_back(Mala(&required, stof(arguments[1])));
            }
        }
        else if (object == "Aviao")
        {
            vector<string> arguments(3);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                avioes.emplace_back(Aviao(stoi(arguments[0]), arguments[1], arguments[2]));
            }
        }
        else if (object == "Voo")
        {
            vector<string> arguments(7);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                Aeroporto origem = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                Aeroporto destino = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[4], "", ""));
                Aviao aviao = *std::find(avioes.begin(), avioes.end(), Aviao(0, arguments[5], std::__cxx11::string()));
                voos.emplace_back(Voo(stoi(arguments[0]), stoi(arguments[1]), arguments[2], &origem, &destino, &aviao, arguments[6]));
            }
        }
        else if (object == "CarrinhoTransporte")
        {
            vector<string> arguments(4);
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                processInput(instruction, arguments);
                Aeroporto required = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                carrinhosTransporte.emplace_back(CarrinhoTransporte(stoi(arguments[0]), stoi(arguments[1]), stoi(arguments[2]), &required));
            }
        }
    }
    return 0;
}
