#ifndef PROJETO1_AEROPORTO_H
#define PROJETO1_AEROPORTO_H

#include <string>
#include <vector>
#include <queue>
#include <list>

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
    std::list<Aviao*> avioes;
    std::queue<Mala*> storage;

    /**
     * Função auxiliar que compara 2 apontadores de funcionários
     * @param f1
     * @param f2
     * @return true se f1 e f2 estiverem em ordem alfabética
     */
    static bool sorterFuncionarios(const Funcionario * f1, const Funcionario * f2);

    /**
     * Funcao auxiliar que compara 2 apontadores de aviões
     * @param a1
     * @param a2
     * @return true se a1 descolar primeiro que a2
     */
    static bool sorterAvioes(const Aviao* a1, const Aviao* a2);

public:
    Aeroporto(std::string name, std::string city, std::string country, const std::vector<Funcionario *> &funcionarios,
              const BST<Transporte> &transportes, const std::vector<CarrinhoTransporte *> &carrinhos,
              const std::list<Aviao *> &avioes);

    Aeroporto(std::string name, std::string city, std::string country);

    const std::string &getName() const;

    const std::queue<Mala *> &getStorage() const;

    void setStorage(const std::queue<Mala *> &storage);

    void addMalas(std::queue<Mala *> &malas);

    std::vector<CarrinhoTransporte *> & getCarrinhos();

    void setCarrinhos(const std::vector<CarrinhoTransporte *> &Carrinhos);

    void setName(const std::string &Name);

    const std::string &getCity() const;

    void setCity(const std::string &City);

    const std::list<Aviao *> &getAvioes() const;

    void setAvioes(const std::list<Aviao *> &Avioes);

    const std::string &getCountry() const;

    void setCountry(const std::string &Country);

    void setTransportes(BST<Transporte> &t);

    const std::vector<Funcionario *> &getFuncionarios() const;

    void setFuncionarios(std::vector<Funcionario *> &funcionariosNew);

    BST<Transporte> getTransportes();

    /**
     * Adiciona o transporte t à BST de transportes.
     * @param t
     * @return true se o transporte adicionado não for um duplicado
     */
    bool addTransporte(Transporte &t);

    /**
     * Remove o transporte t da BST
     * @param t
     * @return true se o transporte existir na BST
     */
    bool removeTransporte(Transporte &t);

    /**
     * Retorna o transporte mais próximo do aeroporto
     * @return transporte mais próximo
     */
    Transporte getNearestTransport();

    /**
     * Retorna o próximo transporte a chegar
     * @return próximo transporte
     */
    Transporte getNextTransport();

    /**
     * Procura todos os transportes que estão disponíveis entre as horas especificadas
     * @param min
     * @param max
     * @return vector com os transportes cuja hora de chegada está no intervalo [min, max]
     */
    std::vector<Transporte> getAvailableTransports(Tempo min, Tempo max);

    /**
     * Verifica se o transporte t existe na BST
     * @param t
     * @return true se o transporte existir
     */
    bool existsTransport(Transporte t) const;

    /**
     * Adiciona o apontador do funcionário f ao vetor de funcionários (mantendo a ordem alfabética)
     * @param f
     */
    void addFuncionario(Funcionario *f);

    /**
     * Remove o apontador do funcionário f do vetor de funcionários
     * @param f
     * @return nullptr se o funcionário não existir
     */
    Funcionario* removeFuncionario(const Funcionario &f);

    /**
     * Adiciona o apontador do avião à lista de aviões, mantendo a ordem de partida dos mesmos
     * Associa um carrinho de transporte ao avião que foi adicionado
     * @param a
     */
    void addAviao(Aviao * a);

    /**
     * Remove o aviao da lista de aviões, mantendo a posição relativa dos restantes
     * O carrinho de transporte que lhe foi associado, passa a estar disponível para outros aviões
     * @param a
     * @return true se o avião existir no aeroporto
     */
    bool removeAviao(Aviao * a);

    /**
     * Função que verifica a igualdade de 2 aeroportos
     * @param Aeroporto lhs
     * @param Aeroporto rhs
     * @return true se os 2 aeroportos tiverem o mesmo nome
     */
    friend bool operator==(const Aeroporto &lhs, const Aeroporto &rhs);

    /**
     * Função que verifica se lhs é inferior que rhs
     * @param Aeroporto lhs
     * @param Aeroporto rhs
     * @return false se os 2 aeroportos tiverem o mesmo nome
     */
    friend bool operator<(const Aeroporto &lhs, const Aeroporto &rhs);

    /**
     * Adiciona o carrinho c à lista de carrinhos do aeroporto
     * @param c
     */
    void addCarrinho(CarrinhoTransporte * c);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_AEROPORTO_H
