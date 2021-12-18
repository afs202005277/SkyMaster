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
    /**
     * @return string com toda a informacao relativa ao objeto
     */
    virtual std::string getObjectName() = 0;

    /**
     * @return string com o identificador do objeto
     */
    virtual std::string getObjectID() = 0;

    /**
     * Executa o metodo cujo nome recebeu como argumento
     * @param nomeFunc
     * @return true se encontrar um metodo com o nome referido e se o input pedido estiver correto
     */
    virtual bool findFunc(std::string nomeFunc) = 0;

    /**
     * @return stack de strings contendo os nomes de todos os metodos do respetivo objeto
     */
    virtual std::stack<std::string> funcs() = 0;

    /**
     * Retorna a estrutura de dados com nome nameVector da classe respetiva
     * @param nameVector
     * @return apontador para um vetor de apontadores de terminais com a informacao requerida
     */
    virtual std::vector<Terminal*> *getV(std::string nameVector) = 0;

    /**
     *
     * @param s
     * @param y
     * @param occurence
     * @param after
     * @return
     */
    static std::string processString(std::string &s, char y, int occurence=1, bool after=false)
    {
        std::string::size_type pos = 0;
        for (int i=0;i<occurence;i++) {
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
