#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Aviao.h"
#include "Tempo.h"
#include "Terminal.h"
#include <unordered_map>

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

vector<Aeroporto*> Terminal::aeroportos;
vector<Passageiro*> Terminal::passageiros;
vector<Voo*> Terminal::voos;
vector<Funcionario*> Terminal::funcionarios;

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

    // TERMINAL STUFF
    for (auto a: aeroportos)
    {
        Terminal::aeroportos.push_back(&a);
    }
    for (auto p : passageiros)
    {
        Terminal::passageiros.push_back(&p);
    }
    for (auto v : voos)
    {
        Terminal::voos.push_back(&v);
    }
    for (auto f : funcionarios)
    {
        Terminal::funcionarios.push_back(&f);
    }

    vector<Terminal*> term_aero(Terminal::aeroportos.begin(), Terminal::aeroportos.end());
    vector<Terminal*> term_pass(Terminal::passageiros.begin(), Terminal::passageiros.end());
    vector<Terminal*> term_voos(Terminal::voos.begin(), Terminal::voos.end());
    vector<Terminal*> term_func(Terminal::funcionarios.begin(), Terminal::funcionarios.end());

    bool run = true;
    string command;
    stack<string> cur_dir;
    cur_dir.push("main");
    stack<Terminal*> cur_obj;
    cur_obj.push(nullptr);
    std::unordered_map<string, tuple<string, vector<Terminal*>*>> dir;
    dir.insert({"AEROPORTO[list]", {"main", &term_aero}});
    dir.insert({"PASSAGEIRO[list]", {"main", &term_pass}});
    dir.insert({"VOO[list]", {"main", &term_voos}});
    dir.insert({"FUNCIONARIO[list]", {"main", &term_func}});

    cout << "Welcome to Airport Management Terminal\n";
    cout << "Type 'help' to get started.\n";
    cout << "[" + cur_dir.top() + "] ";
    while (getline(cin, command) && run)
    {
        auto command_temp = command.find(" ");
        if (command_temp == std::string::npos)
            std::transform(command.begin(), command.end(), command.begin(), ::toupper);
        else
            std::transform(command.begin(), command.end()-command.size()+command_temp, command.begin(), ::toupper);
        if (command == "QUIT")
        {
            return 0;
        }
        else if (command == "HELP")
        {
            cout << "These are the available commands in various situations\n\n";
            cout << "list <object>\t\t\t\t\t\t\t\t\t\t Prints elements of object list\n";
            cout << "ls\t\t\t\t\t\t\t\t\t\t\t\t\t Lists available objects/methods\n";
            cout << "access <object> <first attribute>\t\t\t\t\t Accesses object\n";
            cout << "back\t\t\t\t\t\t\t\t\t\t\t\t Go back to previous directory\n";
            cout << "func <method>\t\t\t\t\t\t\t\t\t\t Runs method\n";
            cout << "quit\t\t\t\t\t\t\t\t\t\t\t\t Quits Airport Management Terminal\n";
        }
        else if (command == "LS")
        {
            vector<string> t;
            for (auto d : dir)
            {
                if (get<0>(d.second) == cur_dir.top())
                {
                    cout << d.first << endl;
                }
            }
            if (cur_obj.top() != nullptr)
            {
                stack<string> temp = cur_obj.top()->funcs();
                while (!temp.empty())
                {
                    cout << temp.top() << endl;
                    temp.pop();
                }
            }
            else
            {
                cout << "addAeroporto()" << endl;
                cout << "removeAeroporto()" << endl;
                cout << "addPassageiro()" << endl;
                cout << "removePassageiro()" << endl;
                cout << "addVoo()" << endl;
                cout << "removeVoo()" << endl;
                cout << "addFuncionario()" << endl;
                cout << "removeFuncionario()" << endl;
            }
        }
        else if (Terminal::processString(command, ' ') == "LIST")
        {
            auto t= dir.find(Terminal::processString(command, ' ', 1, true)+"[list]");
            if (t == dir.end() || get<0>(t->second) != cur_dir.top())
            {
                cout << "List \"" << Terminal::processString(command, ' ', 1, true) << "\" not found. Please try again.\n";
            }
            else
            {
                if (get<1>(t->second)->size() == 0)
                {
                    cout << "empty." << endl;
                }
                else {
                    for (auto p : *get<1>(t->second))
                    {
                        cout << p->getObjectName() << endl;
                    }
                }
            }
        }
        else if (Terminal::processString(command, ' ') == "ACCESS")
        {
            string arguments = Terminal::processString(command, ' ', 1, true);
            auto t= dir.find(Terminal::processString(arguments, ' ', 1, false));
            if (t == dir.end())
                t = dir.find(Terminal::processString(arguments, ' ', 1, false)+"[list]");
            if (t == dir.end() || get<0>(t->second) != cur_dir.top())
            {
                cout << "Object \"" << Terminal::processString(arguments, ' ', 1, false) << "\" not found. Please try again.\n";
            }
            else
            {
                if (get<1>(t->second)->size() == 1)
                {
                    if (Terminal::processString(arguments, ' ', 1, true) == arguments)
                    {
                        auto ttt = t->first;
                        ttt = Terminal::processString(ttt, '[', 1, false);
                        cur_dir.push(ttt);
                        cur_obj.push(get<1>(t->second)->back());
                        Terminal::handleListDir(cur_dir.top(), cur_obj.top(), dir, true);
                    }
                }
                else
                {
                    auto tt = find_if(get<1>(t->second)->begin(), get<1>(t->second)->end(), [&arguments] (Terminal* item) { if (item == nullptr) {return false;} return item->getObjectID() == Terminal::processString(arguments, ' ', 1, true);});
                    if (tt == get<1>(t->second)->end())
                    {
                        try {
                            if (stoi(Terminal::processString(arguments, ' ', 1, true)) < get<1>(t->second)->size() || get<0>(t->second) == cur_dir.top())
                            {
                                auto tt = get<1>(t->second)->at(stoi(Terminal::processString(arguments, ' ', 1, true)));
                                auto ttt = t->first;
                                ttt = Terminal::processString(ttt, '[', 1, false);
                                cur_dir.push(ttt);
                                cur_obj.push(tt);
                                Terminal::handleListDir(cur_dir.top(), cur_obj.top(), dir, true);
                            }
                            else
                            {
                                cout << "Object found. Attribute \"" << Terminal::processString(arguments, ' ', 1, true) << "\" not found. Please try again.\n";
                            }
                        }
                        catch (exception &e)
                        {
                            cout << "Object found. Attribute \"" << Terminal::processString(arguments, ' ', 1, true) << "\" not found. Please try again.\n";
                        }
                    }
                    else
                    {
                        auto ttt = t->first;
                        ttt = Terminal::processString(ttt, '[', 1, false);
                        cur_dir.push(ttt);
                        cur_obj.push(*tt);
                        Terminal::handleListDir(cur_dir.top(), cur_obj.top(), dir, true);
                    }
                }
            }
        }
        else if (Terminal::processString(command, ' ') == "FUNC")
        {
            auto nameFunc = Terminal::processString(command, ' ', 1, true);
            if (cur_obj.top() != nullptr)
            {
                if (!cur_obj.top()->findFunc(nameFunc))
                {
                    cout << "Function not found. Please try again.\n";
                }
            }
            else
            {
                nameFunc = Terminal::processString(nameFunc, '(', 1, false);
                if (nameFunc == "addAeroporto")
                {
                    cout << "input aeroporto name: ";
                    string temp1;
                    getline(cin, temp1);
                    cout << "input cidade name: ";
                    string temp2;
                    getline(cin, temp2);
                    cout << "input país name: ";
                    string temp3;
                    getline(cin, temp3);
                    try
                    {
                        Terminal::aeroportos.push_back(new Aeroporto(temp1, temp2, temp3));
                        term_aero.push_back(Terminal::aeroportos.back());
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "removeAeroporto")
                {
                    cout << "input aeroporto (index): ";
                    string temp1;
                    getline(cin, temp1);
                    try
                    {
                        auto temp2 = Terminal::aeroportos.begin();
                        auto temp3 = term_aero.begin();
                        advance(temp2, stoi(temp1));
                        advance(temp3, stoi(temp1));
                        Terminal::aeroportos.erase(temp2);
                        term_aero.erase(temp3);
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "addPassageiro")
                {
                    cout << "input nome: ";
                    string temp1;
                    getline(cin, temp1);
                    cout << "input idade: ";
                    string temp2;
                    getline(cin, temp2);
                    cout << "input id: ";
                    string temp3;
                    getline(cin, temp3);
                    try
                    {
                        Terminal::passageiros.push_back(new Passageiro(temp1, stoi(temp2), stoi(temp3)));
                        term_pass.push_back(Terminal::passageiros.back());
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "removePassageiro")
                {
                    cout << "input passageiro (index): ";
                    string temp1;
                    getline(cin, temp1);
                    try
                    {
                        auto temp2 = Terminal::passageiros.begin();
                        auto temp3 = term_pass.begin();
                        advance(temp2, stoi(temp1));
                        advance(temp3, stoi(temp1));
                        Terminal::passageiros.erase(temp2);
                        term_pass.erase(temp3);
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "addVoo")
                {
                    cout << "input nVoo: ";
                    string temp1;
                    getline(cin, temp1);
                    cout << "input duracao: ";
                    string temp2;
                    getline(cin, temp2);
                    cout << "input dataPartida (YYYY/MM/DD): ";
                    string temp3;
                    getline(cin, temp3);
                    cout << "input aeroporto origem (index): ";
                    string temp4;
                    getline(cin, temp4);
                    cout << "input aeroporto destino (index): ";
                    string temp5;
                    getline(cin, temp5);
                    cout << "input aviao (index dos avioes do aerporto origem): ";
                    string temp6;
                    getline(cin, temp6);
                    cout << "input horaPartida (HH:MM:SS): ";
                    string temp7;
                    getline(cin, temp7);
                    try
                    {
                        auto temp8 = Terminal::aeroportos[stoi(temp4)]->getAvioes().begin();
                        advance(temp8, stoi(temp6));
                        Terminal::voos.push_back(new Voo(stoi(temp1), stoi(temp2), temp3, Terminal::aeroportos[stoi(temp4)], Terminal::aeroportos[stoi(temp5)], *temp8, temp7));
                        term_voos.push_back(Terminal::voos.back());
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "removeVoo")
                {
                    cout << "input voo (index): ";
                    string temp1;
                    getline(cin, temp1);
                    try
                    {
                        auto temp2 = Terminal::voos.begin();
                        auto temp3 = term_voos.begin();
                        advance(temp2, stoi(temp1));
                        advance(temp3, stoi(temp1));
                        Terminal::voos.erase(temp2);
                        term_voos.erase(temp3);
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "addFuncionario")
                {
                    cout << "input telemovel: ";
                    string temp1;
                    getline(cin, temp1);
                    cout << "input nome: ";
                    string temp2;
                    getline(cin, temp2);
                    cout << "input morada: ";
                    string temp3;
                    getline(cin, temp3);
                    cout << "input aeroporto (index): ";
                    string temp4;
                    getline(cin, temp4);
                    try
                    {
                        Terminal::funcionarios.push_back(new Funcionario(stoi(temp1), temp2, temp3, Terminal::aeroportos[stoi(temp4)]));
                        term_func.push_back(Terminal::funcionarios.back());
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else if (nameFunc == "removeFuncionario")
                {
                    cout << "input funcionario (index): ";
                    string temp1;
                    getline(cin, temp1);
                    try
                    {
                        auto temp2 = Terminal::funcionarios.begin();
                        auto temp3 = term_func.begin();
                        advance(temp2, stoi(temp1));
                        advance(temp3, stoi(temp1));
                        Terminal::funcionarios.erase(temp2);
                        term_func.erase(temp3);
                    }
                    catch (exception &e)
                    {
                        cout << "Function failed." << endl;
                    }
                }
                else { cout << "Function not found. Please try again." << endl; }
            }
        }
        else if (command == "BACK")
        {
            if (cur_dir.top() != "main")
            {
                Terminal::handleListDir(cur_dir.top(), cur_obj.top(), dir, false);
                cur_dir.pop();
                cur_obj.pop();
            }
            else
            {
                cout << "Nothing to go back to.\n";
            }
        }
        else
        {
            cout << "Unavailable command. Please try again.\n";
        }
        cout << "[" + cur_dir.top() + "] ";
    }

    return 0;
}
