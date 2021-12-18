//
// Created by andre on 18/12/2021.
//

#ifndef AEROPORTO_CPP_TERMINAL_H
#define AEROPORTO_CPP_TERMINAL_H

#include <stack>
#include <list>
#include <vector>
#include <string>

class Aeroporto;
class Passageiro;
class Voo;
class Funcionario;
class Terminal{
protected:
    static std::vector<Aeroporto> aeroportos;
    static std::vector<Passageiro> passageiros;
    static std::vector<Voo> voos;
    static std::vector<Funcionario> funcionarios;
public:
    virtual std::string getObjectName() {};
    virtual std::string getObjectID() {};
    virtual bool findFunc(std::string nomeFunc) {};
    virtual std::stack<std::string> funcs() {};
    virtual std::vector<Terminal*> *getV(std::string nameVector) {};

    std::string processString(std::string &s, char y, int occurence=1, bool after=false)
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
    };
};
#endif //AEROPORTO_CPP_TERMINAL_H
