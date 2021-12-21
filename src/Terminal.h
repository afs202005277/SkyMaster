//
// Created by andre on 18/12/2021.
//

#ifndef AEROPORTO_CPP_TERMINAL_H
#define AEROPORTO_CPP_TERMINAL_H

#include <stack>
#include <list>
#include <vector>
#include <string>
#include <map>

class Aeroporto;
class Passageiro;
class Voo;
class Funcionario;

class Terminal{
public:
    static std::vector<Aeroporto*> aeroportos;
    static std::vector<Passageiro*> passageiros;
    static std::vector<Voo*> voos;
    static std::vector<Funcionario*> funcionarios;
    static std::stack<std::string> cur_dir;
    static std::stack<Terminal*> cur_obj;
    static std::multimap<std::string, std::tuple<std::string, std::vector<Terminal*>*>> dir;

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
     * Recebe string e retorna string até ou depois da 'occurence' de 'y'
     * @param s
     * @param y
     * @param occurence
     * @param after : se falso, retorna até 'y'. se verdadeiro, retorna depois de 'y'.
     * @return
     */
    static std::string processString(std::string &s, char y, int occurence=1, bool after=false)
    {
        std::string::size_type pos = 0;
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
    };


    /**
     * Trata de acrescentar e retirar as diretorias acessiveis dependendo de onde estamos acessando no momento
     * @param new_dir
     * @param cur_obj
     * @param dir
     * @param in : Verifica se estamos a entrar ou a sair da diretoria
     */
    static void handleListDir(std::string new_dir, Terminal* cur_obj, std::multimap<std::string, std::tuple<std::string, std::vector<Terminal*>*>> &dir, bool in)
    {
        if (new_dir == "AEROPORTO" || new_dir == "AEROPORTO_VOO")
        {
            if (in) {
                dir.insert({"FUNCIONARIO_AEROPORTO[list]", {new_dir, cur_obj->getV("funcionarios")}});
                dir.insert({"TRANSPORTE[list]", {new_dir, cur_obj->getV("transportes")}});
                dir.insert({"CARRINHO[list]", {new_dir, cur_obj->getV("carrinhos")}});
                dir.insert({"AVIAO[list]", {new_dir, cur_obj->getV("avioes")}});
                dir.insert({"STORAGE[list]", {new_dir, cur_obj->getV("storage")}});
            }
            else
            {
                dir.erase("FUNCIONARIO_AEROPORTO[list]");
                dir.erase("TRANSPORTE[list]");
                dir.erase("CARRINHO[list]");
                dir.erase("AVIAO[list]");
                dir.erase("STORAGE[list]");
            }
        }
        else if (new_dir == "AVIAO")
        {
            if (in)
            {
                dir.insert({"PLANO[list]", {new_dir, cur_obj->getV("plano")}});
                dir.insert({"SERVICO[list]", {new_dir, cur_obj->getV("servicos")}});
                dir.insert({"SERVICOPROC[list]", {new_dir, cur_obj->getV("pastServices")}});
                dir.insert({"CARGA_AVIAO[list]", {new_dir, cur_obj->getV("carga")}});
                dir.insert({"CARRINHO", {new_dir, cur_obj->getV("carrinhoAssociado")}});
            }
            else
            {
                dir.erase("PLANO[list]");
                dir.erase("SERVICO[list]");
                dir.erase("SERVICOPROC[list]");
                dir.erase("CARGA_AVIAO[list]");
                dir.erase("CARRINHO");
            }
        }
        else if (new_dir == "BILHETE")
        {
            if (in)
            {
                dir.insert({"PASSAGEIRO", {new_dir, cur_obj->getV("passageiro")}});
            }
            else
            {
                dir.erase("PASSAGEIRO");
            }
        }
        else if (new_dir == "CARRINHO")
        {
            if (in)
            {
                dir.insert({"CARGA[list]", {new_dir, cur_obj->getV("carga")}});
                dir.insert({"AVIAO", {new_dir, cur_obj->getV("aviao")}});
                dir.insert({"AEROPORTO", {new_dir, cur_obj->getV("aeroporto")}});
            }
            else
            {
                dir.erase("CARGA[list]");
                dir.erase("AVIAO");
                dir.erase("AEROPORTO");
            }
        }
        else if (new_dir == "FUNCIONARIO" || new_dir == "FUNCIONARIO_AEROPORTO")
        {
            if (in)
            {
                dir.insert({"AEROPORTO", {new_dir, cur_obj->getV("aeroporto")}});
            }
            else
            {
                dir.erase("AEROPORTO");
            }
        }
        else if (new_dir == "MALA" || new_dir == "CARGA_AVIAO")
        {
            if (in)
            {
                dir.insert({"PASSAGEIRO", {new_dir, cur_obj->getV("dono")}});
                dir.insert({"AVIAO", {new_dir, cur_obj->getV("despachada")}});
            }
            else
            {
                dir.erase("PASSAGEIRO");
                dir.erase("AVIAO");
            }
        }
        else if (new_dir == "PASSAGEIRO" || new_dir == "PASSAGEIRO_VOO")
        {
            if (in)
            {
                dir.insert({"BILHETE[list]", {new_dir, cur_obj->getV("bilhetes")}});
                dir.insert({"MALA[list]", {new_dir, cur_obj->getV("malas")}});
            }
            else
            {
                dir.erase("BILHETE[list]");
                dir.erase("MALA[list]");
            }
        }
        else if (new_dir == "SERVICO")
        {
            if (in)
            {
                dir.insert({"FUNCIONARIO", {new_dir, cur_obj->getV("funcionario")}});
            }
            else
            {
                dir.erase("FUNCIONARIO");
            }
        }
        else if (new_dir == "TRANSPORTE")
        {

        }
        else if (new_dir == "VOO")
        {
            if (in)
            {
                dir.insert({"AEROPORTO_VOO[list]", {new_dir, cur_obj->getV("viagem")}});
                dir.insert({"PASSAGEIRO_VOO[list]", {new_dir, cur_obj->getV("passageiros")}});
                dir.insert({"AVIAO", {new_dir, cur_obj->getV("aviao")}});
            }
            else
            {
                dir.erase("AEROPORTO_VOO[list]");
                dir.erase("PASSAGEIRO_VOO[list]");
                dir.erase("AVIAO");
            }
        }
    }

    /**
     * Updates directory vectors with the new changes
     */
    static void updateVec()
    {
        Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, false);
        Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, true);
    }


};
#endif //AEROPORTO_CPP_TERMINAL_H
