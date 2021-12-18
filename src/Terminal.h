//
// Created by andre on 18/12/2021.
//

#ifndef AEROPORTO_CPP_TERMINAL_H
#define AEROPORTO_CPP_TERMINAL_H

#include <stack>
#include <list>
#include <vector>
#include <string>
#include <unordered_map>

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
    static std::unordered_map<std::string, std::tuple<std::string, std::vector<Terminal*>*>> dir;

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
    static void handleListDir(std::string new_dir, Terminal* cur_obj, std::unordered_map<std::string, std::tuple<std::string, std::vector<Terminal*>*>> &dir, bool in)
    {
        if (new_dir == "AEROPORTO" || new_dir == "AEROPORTO_VOO")
        {
            if (in) {
                dir.insert({"FUNCIONARIO_AEROPORTO[list]", {"AEROPORTO", cur_obj->getV("funcionarios")}});
                dir.insert({"TRANSPORTE[list]", {"AEROPORTO", cur_obj->getV("transportes")}});
                dir.insert({"CARRINHO[list]", {"AEROPORTO", cur_obj->getV("carrinhos")}});
                dir.insert({"AVIAO[list]", {"AEROPORTO", cur_obj->getV("avioes")}});
                dir.insert({"STORAGE[list]", {"AEROPORTO", cur_obj->getV("storage")}});
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
                dir.insert({"PLANO[list]", {"AVIAO", cur_obj->getV("plano")}});
                dir.insert({"SERVICO[list]", {"AVIAO", cur_obj->getV("servicos")}});
                dir.insert({"SERVICOPROC[list]", {"AVIAO", cur_obj->getV("pastServices")}});
                dir.insert({"CARGA[list]", {"AVIAO", cur_obj->getV("carga")}});
                dir.insert({"CARRINHO", {"AVIAO", cur_obj->getV("carrinhoAssociado")}});
            }
            else
            {
                dir.erase("PLANO[list]");
                dir.erase("SERVICO[list]");
                dir.erase("SERVICOPROC[list]");
                dir.erase("CARGA[list]");
                dir.erase("CARRINHO");
            }
        }
        else if (new_dir == "BILHETE")
        {
            if (in)
            {
                dir.insert({"PASSAGEIRO", {"BILHETE", cur_obj->getV("passageiro")}});
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
                dir.insert({"CARGA[list]", {"CARRINHO", cur_obj->getV("carga")}});
                dir.insert({"AVIAO", {"CARRINHO", cur_obj->getV("aviao")}});
                dir.insert({"AEROPORTO", {"CARRINHO", cur_obj->getV("aeroporto")}});
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
                dir.insert({"AEROPORTO", {"FUNCIONARIO", cur_obj->getV("aeroporto")}});
            }
            else
            {
                dir.erase("AEROPORTO");
            }
        }
        else if (new_dir == "MALA")
        {
            if (in)
            {
            dir.insert({"PASSAGEIRO", {"MALA", cur_obj->getV("dono")}});
            dir.insert({"AVIAO", {"MALA", cur_obj->getV("despachada")}});
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
                dir.insert({"BILHETE[list]", {"PASSAGEIRO", cur_obj->getV("bilhetes")}});
            }
            else
            {
                dir.erase("BILHETE[list]");
            }
        }
        else if (new_dir == "SERVICO")
        {
            if (in)
            {
                dir.insert({"FUNCIONARIO", {"SERVICO", cur_obj->getV("funcionario")}});
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
                dir.insert({"AEROPORTO_VOO[list]", {"VOO", cur_obj->getV("viagem")}});
                dir.insert({"PASSAGEIRO_VOO[list]", {"VOO", cur_obj->getV("passageiros")}});
                dir.insert({"AVIAO", {"VOO", cur_obj->getV("aviao")}});
            }
            else
            {
                dir.erase("AEROPORTO_VOO[list]");
                dir.erase("PASSAGEIRO_VOO[list]");
                dir.erase("AVIAO");
            }
        }
    }

    static void updateVec()
    {
        Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, false);
        Terminal::handleListDir(Terminal::cur_dir.top(), Terminal::cur_obj.top(), Terminal::dir, true);
    }


};
#endif //AEROPORTO_CPP_TERMINAL_H
