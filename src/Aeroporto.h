#ifndef PROJETO1_AEROPORTO_H
#define PROJETO1_AEROPORTO_H

#include <string>
#include <vector>
#include <queue>
#include "Transporte.h"
#include "Funcionario.h"
#include "CarrinhoTransporte.h"
#include "bst.h"
#include "Aviao.h"

class Terminal;
class Funcionario;
class CarrinhoTransporte;
class Aeroporto : public Terminal {
private:
    std::string name, city, country;
    std::vector<Funcionario*> funcionarios;
    BST<Transporte> transportes;
    std::vector<CarrinhoTransporte*> carrinhos;
    list<Aviao*> avioes;
    std::queue<Mala*> storage;

    /**
     * Funcao auxiliar que compara 2 apontadores de funcionarios
     * @param f1
     * @param f2
     * @return true se f1 e f2 estiverem em ordem alfabetica
     */
    static bool sorterFuncionarios(const Funcionario * f1, const Funcionario * f2);

    /**
     * Funcao auxiliar que compara 2 apontadores de avioes
     * @param a1
     * @param a2
     * @return true se a1 descolar primeiro que a2
     */
    static bool sorterAvioes(const Aviao* a1, const Aviao* a2);

public:
    Aeroporto(string name, string city, string country, const vector<Funcionario *> &funcionarios,
              const BST<Transporte> &transportes, const vector<CarrinhoTransporte *> &carrinhos,
              const list<Aviao *> &avioes);

    Aeroporto(std::string name, std::string city, std::string country);

    const std::string &getName() const;

    const queue<Mala *> &getStorage() const;

    void setStorage(const queue<Mala *> &storage);

    void addMalas(queue<Mala *> &malas);

    vector<CarrinhoTransporte *> & getCarrinhos();

    void setCarrinhos(const vector<CarrinhoTransporte *> &Carrinhos);

    void setName(const std::string &Name);

    const std::string &getCity() const;

    void setCity(const std::string &City);

    const list<Aviao *> &getAvioes() const;

    void setAvioes(const list<Aviao *> &Avioes);

    const std::string &getCountry() const;

    void setCountry(const std::string &Country);

    void setTransportes(BST<Transporte> &t);

    const vector<Funcionario *> &getFuncionarios() const;

    void setFuncionarios(vector<Funcionario *> &funcionariosNew);

    BST<Transporte> getTransportes();

    void addTransporte(Transporte &t);

    bool removeTransporte(Transporte &t);

    Transporte getNearestTransport();

    Transporte getNextTransport();

    /**
     * Procura todos os transportes que estão disponíveis entre as horas especificadas
     * @param min
     * @param max
     * @return vector com os transportes cuja hora de chegada está no intervalo [min, max]
     */
    vector<Transporte> getAvailableTransports(Tempo min, Tempo max);

    bool existsTransport(Transporte t) const;

    void addFuncionario(Funcionario *f);

    Funcionario* removeFuncionario(const Funcionario &f);

    /**
     * Adiciona o apontador do aviao à lista de avioes, mantendo a ordem de partida dos avioes
     * Associa um carrinho de transporte ao aviao que foi adicionado
     * @param a
     */
    void addAviao(Aviao * a);

    /**
     * Remove o aviao da lista de avioes, mantendo a posicao relativa dos restantes
     * O carrinho de transporte que lhe foi associado, passa a estar disponível para outros avioes
     * @param a
     * @return true se o aviao existir no aeroporto
     */
    bool removeAviao(Aviao * a);

    /**
     * Funcao que verifica a igualdade de 2 aeroportos
     * @param Aeroporto lhs
     * @param Aeroporto rhs
     * @return true se os 2 aeroportos tiverem o mesmo nome
     */
    friend bool operator==(const Aeroporto &lhs, const Aeroporto &rhs);

    /**
     * Funcao que verifica se lhs é inferior que rhs
     * @param Aeroporto lhs
     * @param Aeroporto rhs
     * @return false se os 2 aeroportos tiverem o mesmo nome
     */
    friend bool operator<(const Aeroporto &lhs, const Aeroporto &rhs);

    void addCarrinho(CarrinhoTransporte * c);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_AEROPORTO_H
