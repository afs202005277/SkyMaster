#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include "Aviao.h"
#include "Terminal.h"

using namespace std;

/**
 * Breaks an instruction to create an object in the different arguments
 * @param instruction
 * @param arguments : a vector to store the resulting arguments
 */
void processInput(const string &instruction, vector<string> & arguments){
    istringstream stream(instruction);
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

/**
 * Encontra o elemento val na lista l
 * @tparam T
 * @param l
 * @param val
 * @return apontador para o elemento encontrado
 */
template<class  T>
T* find(list <T> &l, T val){
    for (auto it = l.begin();it!=l.end();it++)
    {
        if (*it == val)
            return &(*it);
    }
    cout << "Not found" << endl;
    return nullptr;
}

vector<Aeroporto> Terminal::aeroportos;
vector<Passageiro> Terminal::passageiros;
vector<Voo> Terminal::voos;
vector<Funcionario> Terminal::funcionarios;


int main() {
    ifstream input;
    input.open(R"(D:\Importante\FEUP\2 ano\1 semestre\AED\Projeto1\povoar.txt)");
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
                Aeroporto* a = new Aeroporto(arguments[0], arguments[1], arguments[2]);
                aeroportos.push_back(*a);
            }
        }
        else if (object == "Transporte")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                Transporte* t = new Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]);
                transportes.push_back(*t);
            }
        }
        else if (object == "Funcionario")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[3], "", "");
                auto required = find(aeroportos, tmp);
                Funcionario* f = new Funcionario(stoi(arguments[0]), arguments[1], arguments[2], required);
                funcionarios.push_back(*f);
            }
        }
        else if (object == "Servico")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Funcionario tmp(stoi(arguments[1]), "", "", nullptr);
                auto required = find(funcionarios, tmp);
                Servico* s = new Servico(arguments[0], required, arguments[2]);
                servicos.push_back(*s);
            }
        }
        else if (object == "Passageiro")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Passageiro* p = new Passageiro(arguments[0], stoi(arguments[1]), stoi(arguments[2]));
                passageiros.push_back(*p);
            }
        }
        else if (object == "Mala")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(2);
                processInput(instruction, arguments);
                Passageiro tmp(Passageiro("", 0, stoi(arguments[0])));
                auto required = find(passageiros,tmp);
                Mala* m = new Mala(required, stof(arguments[1]));
                malas.push_back(*m);
            }
            for (auto &elem:malas)
            {
                elem.getDono()->addMala(&elem);
            }
        }
        else if (object == "Aviao")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Aviao* a = new Aviao(stoi(arguments[0]), arguments[1], arguments[2]);
                avioes.push_back(*a);
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
                Voo* v = new Voo(stoi(arguments[0]), stoi(arguments[1]), arguments[2], origem, destino, aviao, arguments[6]);
                voos.push_back(*v);
            }
        }
        else if (object == "CarrinhoTransporte")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(4);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[3], "", "");
                auto required = find(aeroportos, tmp);
                CarrinhoTransporte* c = new CarrinhoTransporte(stoi(arguments[0]), stoi(arguments[1]), stoi(arguments[2]), required);
                carrinhosTransporte.push_back(*c);
            }
        }
    }
    // setting up:
    Aviao* airplane = &avioes.front();
    voos.back().setAviao(airplane);
    list<Voo*> plano;
    plano.push_back(&voos.front());
    plano.push_back(&voos.back());
    airplane->setPlano(plano);
    aeroportos.back().addAviao(airplane);

    cout << airplane->getNextVoo().getDestino()->getName() << endl;
    auto tmp = servicos;
    for (list<Servico>::iterator it = servicos.begin();it!=servicos.end();it++)
    {
        airplane->addServico(&(*it));
    }
    auto lala = airplane->getServicos();
    auto teste = *(lala.front());
    auto func = *(teste.getFuncionario());
    auto abc = airplane->getPastServicesBy(funcionarios.front());
    auto bcf = airplane->getFutureServicesBy(funcionarios.front());
    return 0;
}
