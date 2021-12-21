#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H

#include <string>
#include <queue>
#include <vector>

#include "Bilhete.h"
#include "Voo.h"
#include "Terminal.h"

class Voo;
class Bilhete;
class Mala;
class Terminal;

using namespace std;
class Passageiro : public Terminal {
private:
    int idade, id;
    std::string nome;
    std::queue<Bilhete *> bilhetes;
    std::queue<Mala*> malas;
public:
    Passageiro(std::string nome, int idade, int id);

    Passageiro(int idade, int id, std::string nome, const std::queue<Bilhete *> &bilhetes);

    const std::queue<Mala *> &getMalas() const;

    void setMalas(const std::queue<Mala *> &malas);

    /**
     * Adiciona uma mala à fila de malas do passageiro
     * @param m apontador da mala que vai ser adicionada
     */
    void addMala(Mala *m);

    /**
     * Remove a mala da fila de malas do passageiro
     * @param m apontador da mala que vai ser removida
     */
    void removeMala(Mala *m);

    const std::queue<Bilhete *> & getBilhetes() const;

    /**
     * Adiciona o bilhete à fila de bilhetes
     * @param bilhete apontador do bilhete que vai ser adicionado
     */
    void addBilhete(Bilhete *bilhete);

    /**
     * Retorna o próximo bilhete
     * @return próximo bilhete
     */
    Bilhete* getNextBilhete();

    /**
     * Remove o próximo bilhete da lista
     */
    void removeNextBilhete();

    void setBilhetes(const std::queue<Bilhete *> &bilhetes);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);

    /**
     * Remove o bilhete no índice index da lista
     * @param index índice do bilhete que vai ser removido
     */
    void removeBilhete(int index);

    /**
     * Verifica se o passageiro tem bilhete para o voo recebido como argumento
     * @param nVoo número do voo pretendido
     * @return true se tiver bilhete
     */
    bool hasBilhete(int nVoo) const;

    /**
     * Faz o check-in do passageiro e, caso pretenda fazer check-in automtico, envia as suas malas para o carrinho de transporte
     * @param checkInAutomatico boolean que indica se pretende checkIn automático
     * @param voo o voo em que o passageiro quer fazer checkIn
     * @param malas as malas que o passageiro quer levar
     * @return true se o passageiro tiver bilhete para o voo
     */
    bool checkIn(bool checkInAutomatico, Voo &voo, std::queue<Mala *> malas) const;

    /**
     * "Simula" a entrada do passageiro no aviao: adiciona o passageiro à lista de passageiros presentes no voo
     * @param voo o voo em que o passageiro quer entrar
     * @return true se o passageiro tiver bilhete para o voo
     */
    bool getIntoPlane(Voo &voo);

    /**
     * Verifica se 2 passageiros são a mesma pessoa
     * @param lhs
     * @param rhs
     * @return true se os 2 objetos tiverem o mesmo valor no atributo ID
     */
    friend bool operator==(const Passageiro &lhs, const Passageiro &rhs);

    /**
     * Um passageiro é menor que outro quando é mais novo, ou, em caso de empate, quando o nome é menor que outro
     * (ordem alfabética) ou, em caso de empate, quando o seu id for menor que o do outro passageiro
     * @param lhs
     * @param rhs
     * @return true se o passageiro lhs for menor que o rhs
     */
    friend bool operator<(const Passageiro &lhs, const Passageiro &rhs);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_PASSAGEIRO_H
