//
// Created by Pedro Fonseca on 16/12/2021.
//

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "Aeroporto.h"
#include "Transporte.h"
#include "Funcionario.h"
#include "Passageiro.h"
#include "Mala.h"
#include "Aviao.h"
#include "Voo.h"
#include "CarrinhoTransporte.h"

#ifndef AED1_TERMINAL_H
#define AED1_TERMINAL_H


class Terminal
{
public:
    virtual std::string getObjectName() = 0;
    virtual std::string getObjectID() = 0;
    virtual bool findFunc(std::string nomeFunc) = 0;
    virtual std::stack<std::string> funcs() = 0;
    virtual std::vector<Terminal*> *getV(std::string nameVector) = 0;
    static std::list<Aeroporto> *aeroportos;
    static std::list<Transporte> *transportes;
    static std::list<Funcionario> *funcionarios;
    static std::list<Servico> *servicos;
    static std::list<Passageiro> *passageiros;
    static std::list<Mala> *malas;
    static std::list<Aviao> *avioes;
    static std::list<Voo> *voos;
    static std::list<CarrinhoTransporte> *carrinhosTransporte;



    static std::string processString(std::string &s, char y, int occurence=1, bool after=false)
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


#endif //AED1_TERMINAL_H
