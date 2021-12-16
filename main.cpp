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

void f(int* i){}
int main() {
    ifstream input("povoar.txt");
    if (!input.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }
    list<Aeroporto> aeroportos;
    list<Transporte> transportes;
    list<Funcionario> funcionarios;
    list<Servico> servicos;
    string line, object, instruction;
    while(getline(cin, line))
    {
        vector<string> arguments;
        object = line.substr(0, line.find(':'));
        if (object == "Aeroporto")
        {
            while(getline(cin, instruction) && instruction.find(':') != string::npos) {
                arguments.resize(3);
                processInput(instruction, arguments);
                aeroportos.emplace_back(Aeroporto(arguments[0], arguments[1], arguments[2]));
            }
        }
        else if (object == "Transporte")
        {
            while(getline(cin, instruction) && instruction.find(':') != string::npos) {
                arguments.resize(4);
                processInput(instruction, arguments);
                transportes.emplace_back(Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]));
            }
        }
        else if (object == "Funcionario")
        {
            while(getline(cin, instruction) && instruction.find(':') != string::npos) {
                arguments.resize(4);
                processInput(instruction, arguments);
                Aeroporto required = *std::find(aeroportos.begin(), aeroportos.end(), Aeroporto(arguments[3], "", ""));
                funcionarios.emplace_back(Funcionario(stoi(arguments[0]), arguments[1], arguments[2], &required));
            }
        }
        else if(object == "Servico")
        {
            while(getline(cin, instruction) && instruction.find(':') != string::npos) {
                arguments.resize(3);
                processInput(instruction, arguments);
                Funcionario required = *std::find(funcionarios.begin(), funcionarios.end(), Funcionario(stoi(arguments[1]), "", ""));
                funcionarios.emplace_back(Funcionario(stoi(arguments[0]), arguments[1], arguments[2], &required));
            }
        }
    }
    return 0;
}
