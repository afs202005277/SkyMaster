#ifndef PROJETO1_PASSAGEIRO_H
#define PROJETO1_PASSAGEIRO_H

#include <string>
#include <queue>
#include <vector>

#include "Bilhete.h"
#include "Voo.h"

class Voo;
class Bilhete;
class Mala;

class Passageiro {
private:
    int idade, id;
    std::string nome;
    std::queue<Bilhete *> bilhetes;
public:
    Passageiro(std::string nome, int idade, int id);

    Passageiro(int idade, int id, std::string nome, const std::queue<Bilhete *> &bilhetes);

    const std::queue<Bilhete *> & getBilhetes() const;

    void addBilhete(Bilhete *bilhete);

    Bilhete* getNextBilhete();

    void removeNextBilhete();

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    int getId() const;

    void setId(int id);

    bool hasBilhete(int nVoo) const;

    /**
     * Faz o check-in do passageiro e, caso pretenda fazer check-in automtico, envia as suas malas para o carrinho de transporte
     * @param checkInAutomatico
     * @param voo
     * @param malas
     * @return true se o passageiro tiver bilhete para o voo
     */
    bool checkIn(bool checkInAutomatico, Voo &voo, std::queue<Mala *> &malas) const;

    /**
     * "Simula" a entrada do passageiro no aviao: adiciona o passageiro à lista de passageiros presentes no voo
     * @param voo
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
};


#endif //PROJETO1_PASSAGEIRO_H
