//
// Created by andre on 18/12/2021.
//

#ifndef AEROPORTO_CPP_TERMINAL_H
#define AEROPORTO_CPP_TERMINAL_H

#include <stack>
#include <list>
#include <vector>
#include <string>
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
public:
    virtual std::string getObjectName() = 0;
    virtual std::string getObjectID() = 0;
    virtual bool findFunc(std::string nomeFunc) = 0;
    virtual std::stack<std::string> funcs() = 0;
    virtual std::vector<Terminal*> *getV(std::string nameVector) = 0;

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
    static void handleListDir(std::string new_dir, Terminal* cur_obj, std::unordered_map<std::string, std::tuple<std::string, std::vector<Terminal*>*>> &dir, bool in)
    {
        if (new_dir == "AEROPORTO")
        {
            if (in) {
                dir.insert({"FUNCIONARIO[list]", {"AEROPORTO", cur_obj->getV("funcionarios")}});
                dir.insert({"TRANSPORTE[list]", {"AEROPORTO", cur_obj->getV("transportes")}});
                dir.insert({"CARRINHO[list]", {"AEROPORTO", cur_obj->getV("carrinhos")}});
                dir.insert({"AVIAO[list]", {"AEROPORTO", cur_obj->getV("avioes")}});
                dir.insert({"STORAGE[list]", {"AEROPORTO", cur_obj->getV("storage")}});
            }
            else
            {
                dir.erase("FUNCIONARIOS[list]");
                dir.erase("TRANSPORTES[list]");
                dir.erase("CARRINHOS[list]");
                dir.erase("AVIOES[list]");
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
        else if (new_dir == "FUNCIONARIO")
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
        else if (new_dir == "PASSAGEIRO")
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
                dir.insert({"AEROPORTO[list]", {"VOO", cur_obj->getV("viagem")}});
                dir.insert({"PASSAGEIRO[list]", {"VOO", cur_obj->getV("passageiros")}});
                dir.insert({"AVIAO", {"VOO", cur_obj->getV("aviao")}});
            }
            else
            {
                dir.erase("AEROPORTO[list]");
                dir.erase("PASSAGEIRO[list]");
                dir.erase("AVIAO");
            }
        }
    }


};
#endif //AEROPORTO_CPP_TERMINAL_H
