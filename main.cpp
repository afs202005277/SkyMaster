#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include "Aviao.h"
#include "Terminal.h"
#include <set>

using namespace std;

vector<Aeroporto*> Terminal::aeroportos;
vector<Passageiro*> Terminal::passageiros;
vector<Voo*> Terminal::voos;
vector<Funcionario*> Terminal::funcionarios;
stack<string> Terminal::Terminal::cur_dir;
stack<Terminal*> Terminal::Terminal::cur_obj;
std::multimap<string, tuple<string, vector<Terminal*>*>> Terminal::Terminal::dir;

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
     * Removes duplicates from list objects
     * @tparam T : changes the given list directly
     */
template <class T>
void removeDuplicates(list<T> &temp)
{
    set<T> temp2;
    for (auto t : temp)
    {
        temp2.insert(t);
    }
    temp.clear();
    for (auto t : temp2)
    {
        temp.push_back(t);
    }
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

    /**
     * Funcao que lê de um ficheiro fileName os diferentes atributos das diferentes classes e
     * cria objetos que são guardados nos seus respetivos vetores dados
     * @param string fileName
     * @param list aeroportos
     * @param list transportes
     * @param list funcionarios
     * @param list servicos
     * @param list passageiros
     * @param list malas
     * @param list avioes
     * @param list voos
     * @param list carrinhosTransporte
     */
void readFromFile(string fileName, list<Aeroporto> &aeroportos, list<Transporte> &transportes, list<Funcionario> &funcionarios
                  ,list<Servico> &servicos, list<Passageiro> &passageiros, list<Mala> &malas, list<Aviao> &avioes,
                  list<Voo> &voos,list<CarrinhoTransporte> &carrinhosTransporte){
    ifstream input;
    input.open((fileName));
    if (!input.is_open())
    {
        cout << "File not found" << endl;
        exit(1);
    }
    string line, object, instruction;
    while(getline(input, line)) // line -> o "cabecalho" que antecede cada conjunto de instrucoes de criacao de atributos
    {
        object = line.substr(0, line.find(':')); // remove o simbolo ":"
        if (object == "Aeroporto")
        {
            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                // instruction -> instrucao de criacao do objeto referido no cabecalho
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Aeroporto* a = new Aeroporto(arguments[0], arguments[1], arguments[2]);
                aeroportos.push_back(*a);
            }
            removeDuplicates(aeroportos);
        }
        else if (object == "Transporte")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(5);
                processInput(instruction, arguments);
                Aeroporto tmp(arguments[4], "", "");
                auto required = find(aeroportos, tmp);
                Transporte* t = new Transporte(stoi(arguments[0]), arguments[1], arguments[2], arguments[3]);
                required->addTransporte(*t);
                transportes.push_back(*t);
            }
            removeDuplicates(transportes);
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
            removeDuplicates(funcionarios);
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
            removeDuplicates(servicos);
        }
        else if (object == "Passageiro")
        {

            while(getline(input, instruction) && !instruction.empty() && instruction.find(',') != string::npos) {
                vector<string> arguments(3);
                processInput(instruction, arguments);
                Passageiro* p = new Passageiro(arguments[0], stoi(arguments[1]), stoi(arguments[2]));
                passageiros.push_back(*p);
            }
            removeDuplicates(passageiros);
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
            removeDuplicates(malas);
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
            removeDuplicates(avioes);
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
            removeDuplicates(voos);
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
}

/**
 * Reads 'povoar.txt' which contains saved objects and creates vectors with said objects. Afterwards, the program runs the Terminal.
 */
int main() {
    list<Aeroporto> aeroportos;
    list<Transporte> transportes;
    list<Funcionario> funcionarios;
    list<Servico> servicos;
    list<Passageiro> passageiros;
    list<Mala> malas;
    list<Aviao> avioes;
    list<Voo> voos;
    list<CarrinhoTransporte> carrinhosTransporte;

    string fileName = "../povoar.txt";

    readFromFile(fileName, aeroportos, transportes, funcionarios, servicos, passageiros, malas, avioes, voos, carrinhosTransporte);

    //ASSOCIA 1 AEROPORTO A CADA AVIAO
    for (auto &a:avioes){
        if (a.getPlano().empty())
            continue;
        else
        {
            a.getPlano().front()->getOrigem()->addAviao(&a);
        }

    }

    // TERMINAL STUFF
    for (auto &a: aeroportos)
    {
        Terminal::aeroportos.push_back(&a);
    }
    for (auto &p : passageiros)
    {
        Terminal::passageiros.push_back(&p);
    }
    for (auto &v : voos)
    {
        Terminal::voos.push_back(&v);
    }
    for (auto &f : funcionarios)
    {
        Terminal::funcionarios.push_back(&f);
    }

    vector<Terminal*> term_aero(Terminal::aeroportos.begin(), Terminal::aeroportos.end());
    vector<Terminal*> term_pass(Terminal::passageiros.begin(), Terminal::passageiros.end());
    vector<Terminal*> term_voos(Terminal::voos.begin(), Terminal::voos.end());
    vector<Terminal*> term_func(Terminal::funcionarios.begin(), Terminal::funcionarios.end());

    /**
    * Creates 'main' directory
    */
    bool run = true;
    string command;
    Terminal::cur_dir.push("main");
    Terminal::cur_obj.push(nullptr);
    Terminal::dir.insert({"AEROPORTO[list]", {"main", &term_aero}});
    Terminal::dir.insert({"PASSAGEIRO[list]", {"main", &term_pass}});
    Terminal::dir.insert({"VOO[list]", {"main", &term_voos}});
    Terminal::dir.insert({"FUNCIONARIO[list]", {"main", &term_func}});

    /**
     * Starts running the Terminal.
     */
    cout << "Welcome to Airport Management Terminal\n";
    cout << "Type 'help' to get started.\n";
    cout << "[" + Terminal::cur_dir.top() + "] ";
    while (getline(cin, command) && run)
    {
        auto command_temp = command.find(" ");
        if (command_temp == std::string::npos)
            std::transform(command.begin(), command.end(), command.begin(), ::toupper);
        else
            std::transform(command.begin(), command.end()-command.size()+command_temp, command.begin(), ::toupper);
        /**
         * Ends program.
         */
        if (command == "QUIT")
        {
            return 0;
        }
        /**
         * Prints the available commands on the Terminal.
         */
        else if (command == "HELP")
        {
            int field_size = 40;
            cout << "These are the available commands for various situations\n\n";
            cout << left << setw(field_size) << setfill(' ') << "list <object> " << right << setw(field_size) << setfill(' ') << "Prints elements of object list";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "ls" << right << setw(field_size) << setfill(' ') << "Lists available objects/methods";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "access <object> <first attribute>" << right << setw(field_size) << setfill(' ') << "Accesses object";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "save <object> " << right << setw(field_size) << setfill(' ') << "Saves elements for later use";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "back" << right << setw(field_size) << setfill(' ') << "Go back to previous directory";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "func <method>" << right << setw(field_size) << setfill(' ') << "Runs method";
            cout<<endl;
            cout << left << setw(field_size) << setfill(' ') << "quit" << right << setw(field_size) << setfill(' ') << "Quits Airport Management Terminal";
            cout<<endl;
        }
        /**
         * Prints existing objects and functions inside the directory on the Terminal.
         */
        else if (command == "LS")
        {
            vector<string> t;
            for (auto d : Terminal::dir)
            {
                if (get<0>(d.second) == Terminal::cur_dir.top())
                {
                    cout << d.first << endl;
                }
            }
            if (Terminal::cur_obj.top() != nullptr)
            {
                stack<string> temp = Terminal::cur_obj.top()->funcs();
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
        /**
         * Prints the vectors getObjectName on the Terminal of given list. If list is empty prints 'empty.'.
         */
        else if (Terminal::processString(command, ' ') == "LIST")
        {
            auto t= Terminal::dir.find(Terminal::processString(command, ' ', 1, true)+"[list]");
            if (t == Terminal::dir.end() || get<0>(t->second) != Terminal::cur_dir.top())
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
        /**
         * Accesses inside given object if found.
         */
        else if (Terminal::processString(command, ' ') == "ACCESS")
        {
            string arguments = Terminal::processString(command, ' ', 1, true);
            auto t= Terminal::dir.find(Terminal::processString(arguments, ' ', 1, false));
            if (t == Terminal::dir.end())
                t = Terminal::dir.find(Terminal::processString(arguments, ' ', 1, false)+"[list]");
            if (t == Terminal::dir.end() || get<0>(t->second) != Terminal::cur_dir.top())
            {
                cout << "Object \"" << Terminal::processString(arguments, ' ', 1, false) << "\" not found. Please try again.\n";
            }
            else
            {
                if (get<1>(t->second)->size() == 1 && Terminal::processString(const_cast<string &>(t->first), '[', 1, true) != "list]")
                {
                    if (Terminal::processString(arguments, ' ', 1, true) == arguments)
                    {
                        if (get<1>(t->second)->back() == nullptr)
                        {
                            cout << "Object not found." << endl;
                        }
                        else
                        {
                            auto ttt = t->first;
                            ttt = Terminal::processString(ttt, '[', 1, false);
                            Terminal::cur_dir.push(ttt);
                            Terminal::cur_obj.push(get<1>(t->second)->back());
                            Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir,true);
                        }
                    }
                }
                else
                {
                    auto tt = find_if(get<1>(t->second)->begin(), get<1>(t->second)->end(), [&arguments] (Terminal* item) { if (item == nullptr) {return false;} return item->getObjectID() == Terminal::processString(arguments, ' ', 1, true);});
                    if (tt == get<1>(t->second)->end())
                    {
                        try {
                            if (stoi(Terminal::processString(arguments, ' ', 1, true)) < get<1>(t->second)->size() || get<0>(t->second) == Terminal::cur_dir.top())
                            {
                                auto tt = get<1>(t->second)->at(stoi(Terminal::processString(arguments, ' ', 1, true)));
                                auto ttt = t->first;
                                ttt = Terminal::processString(ttt, '[', 1, false);
                                Terminal::cur_dir.push(ttt);
                                Terminal::cur_obj.push(tt);
                                Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, true);
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
                        Terminal::cur_dir.push(ttt);
                        Terminal::cur_obj.push(*tt);
                        Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, true);
                    }
                }
            }
        }
        /**
         * Runs given function if found.
         */
        else if (Terminal::processString(command, ' ') == "FUNC")
        {
            auto nameFunc = Terminal::processString(command, ' ', 1, true);
            if (Terminal::cur_obj.top() != nullptr)
            {
                if (!Terminal::cur_obj.top()->findFunc(nameFunc))
                {
                    cout << "Function not found. Please try again.\n";
                }
            }
            else
            {
                nameFunc = Terminal::processString(nameFunc, '(', 1, false);
                if (nameFunc == "addAeroporto")
                {
                    cout << "input name: ";
                    string temp1;
                    getline(cin, temp1);
                    cout << "input cidade: ";
                    string temp2;
                    getline(cin, temp2);
                    cout << "input pais: ";
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
                        if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::aeroportos.size())
                            throw exception();
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
                        if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::passageiros.size())
                            throw exception();
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
                        if (stoi(temp4) < 0 || stoi(temp4) > Terminal::aeroportos.size() || stoi(temp5) < 0 || stoi(temp5) >= Terminal::aeroportos.size())
                            throw exception();
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
                        if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::voos.size())
                            throw exception();
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
                        if (stoi(temp4) < 0 || stoi(temp4) >= Terminal::aeroportos.size())
                            throw exception();
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
                        if (stoi(temp1) < 0 || stoi(temp1) >= Terminal::funcionarios.size())
                            throw exception();
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
        /**
         * Saves given object/list to 'povoar.txt' for later use.
         */
        else if (Terminal::processString(command, ' ') == "SAVE")
        {
            auto arguments = Terminal::processString(command, ' ', 1, true);
            auto t= Terminal::dir.find(Terminal::processString(arguments, ' ', 1, false));
            if (t == Terminal::dir.end())
                t = Terminal::dir.find(Terminal::processString(arguments, ' ', 1, false)+"[list]");
            if (t == Terminal::dir.end() || get<0>(t->second) != Terminal::cur_dir.top())
            {
                cout << "Object \"" << Terminal::processString(command, ' ', 1, true) << "\" not found. Please try again.\n";
            }
            else
            {
                if (!get<1>(t->second)->empty())
                {
                    ofstream output;
                    output.open(fileName, ios_base::app);
                    if (!output.is_open()) {
                        cout << "File not found" << endl;
                        return 1;
                    }
                    if (Terminal::processString(arguments, ' ', 1, true) == arguments) {

                        auto temp1 = (*get<1>(t->second)->begin())->getObjectName();
                        output << endl;
                        output << endl;
                        output << Terminal::processString(temp1, ' ', 1, false) << ":" << endl;
                        for (auto p: *get<1>(t->second)) {
                            auto temp3 = p->getObjectName();
                            string temp2 = Terminal::processString(temp3, '(', 1, true);
                            string arguments = Terminal::processString(temp2, ')', 1, false);
                            output << arguments << endl;
                        }
                        cout << "Saved." << endl;
                    }
                    else
                    {
                        auto tt = find_if(get<1>(t->second)->begin(), get<1>(t->second)->end(), [&arguments] (Terminal* item) { if (item == nullptr) {return false;} return item->getObjectID() == Terminal::processString(arguments, ' ', 1, true);});
                        if (tt == get<1>(t->second)->end())
                        {
                            try {
                                if (stoi(Terminal::processString(arguments, ' ', 1, true)) < get<1>(t->second)->size() || get<0>(t->second) == Terminal::cur_dir.top())
                                {
                                    auto temp3 = get<1>(t->second)->at(stoi(Terminal::processString(arguments, ' ', 1, true)));
                                    output << endl;
                                    output << endl;
                                    auto temp1 = temp3->getObjectName();
                                    output << Terminal::processString(temp1, ' ', 1, false) << ":" << endl;
                                    string temp2 = Terminal::processString(temp1, '(', 1, true);
                                    string args = Terminal::processString(temp2, ')', 1, false);
                                    output << args << endl;
                                    cout << "Saved." << endl;
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
                            auto temp1 = (*tt)->getObjectName();
                            output << Terminal::processString(temp1, ' ', 1, false) << ":" << endl;
                            string temp2 = Terminal::processString(temp1, '(', 1, true);
                            string args = Terminal::processString(temp2, ')', 1, false);
                            output << args << endl;
                            cout << "Saved." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Nothing to save." << endl;
                }
            }
        }
        /**
         * Goes back to previous directory. If in 'main' prints 'Nothing to go back to'.
         */
        else if (command == "BACK")
        {
            if (Terminal::cur_dir.top() != "main")
            {
                Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, false);
                Terminal::cur_dir.pop();
                Terminal::cur_obj.pop();
                Terminal::updateVec();
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
        cout << "[" + Terminal::cur_dir.top() + "] ";
    }
    return 0;
}
