#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H

#include <list>

#include "Data.h"
#include "Aeroporto.h"
#include "Bilhete.h"
#include "Passageiro.h"
#include "Aviao.h"
#include "Terminal.h"

using namespace std;

class Aviao;
class Bilhete;
class Passageiro;
class Aeroporto;
class Terminal;
class Voo : public Terminal {
private:
    unsigned int nVoo, duracao, lotacaoAtual;
    Data dataPartida;
    Tempo horaPartida;
    Aeroporto * origem;
    Aeroporto * destino;
    /**
     * Lista de passageiros presentes no voo
     */
    std::list<Passageiro *> passageiros;
    Aviao *aviao;

public:
    Voo(int nVoo, int duracao, const Data &dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
        Tempo &partida, int lotacaoAtual = 0);

    Voo(int nVoo, int duracao, string dataPartida, Aeroporto *origem, Aeroporto *destino, Aviao *aviao,
        string partida);

    const Tempo &getHoraPartida() const;

    void setHoraPartida(const Tempo &horaPartida);

    Aviao *getAviao() const;

    void setAviao(Aviao *aviao);

    unsigned int getNVoo() const;

    void setNVoo(unsigned int nVoo);

    unsigned int getDuracao() const;

    void setDuracao(unsigned int duracao);

    void setPassageiros(const list<Passageiro *> &passageiros);

    unsigned int getLotacaoAtual() const;

    void setLotacaoAtual(unsigned int lotacaoAtual);

    const Data &getDataPartida() const;

    void setDataPartida(const Data &dataPartida);

    Aeroporto *getOrigem() const;

    void setOrigem(Aeroporto *origem);

    Aeroporto *getDestino() const;

    void setDestino(Aeroporto *destino);

    /**
     * Adiciona um bilhete para o voo à fila de bilhetes do passageiro, se existirem lugares disponiveis
     * @param levaBagagem
     * @param passageiro
     * @return true se ainda existirem lugares disponiveis
     */
    bool sellBilhete(bool levaBagagem, Passageiro *passageiro);

    /**
     * Adiciona um bilhete à fila de bilhetes de cada passageiro
     * @param levaBagagem (cada posição do índice corresponde
     * @param passageiros
     * @return true se existirem lugares disponiveis para todas as pessoas do grupo
     */
    bool sellBilheteGroup(const vector<bool> &levaBagagem, const vector<Passageiro *> &passageiros);

    void addPassageiro(Passageiro *p);

    /**
     * Verifica se lhs é menor que rhs
     * @param lhs
     * @param rhs
     * @return true se a data de partida de lhs for menor que a de rhs. Em caso de empate, aplica-se a mesma lógica às horas de partida
     */
    friend bool operator<(const Voo &lhs, const Voo &rhs);

    /**
     * Verifica se lhs é maior que rhs
     * @param lhs
     * @param rhs
     * @return rhs < lhs
     */
    friend bool operator>(const Voo &lhs, const Voo &rhs);

    /**
     * Verifica se lhs é menor ou igual que rhs
     * @param lhs
     * @param rhs
     * @return !(rhs < lhs)
     */
    friend bool operator<=(const Voo &lhs, const Voo &rhs);

    /**
     * Verifica se lhs é maior ou igual que rhs
     * @param lhs
     * @param rhs
     * @return !(lhs < rhs)
     */
    friend bool operator>=(const Voo &lhs, const Voo &rhs);

    /**
     * Verifica se os 2 números de voo são iguais
     * @param lhs
     * @param rhs
     * @return true se tiverem o mesmo número de voo
     */
    friend bool operator==(const Voo &lhs, const Voo &rhs);

    const list<Passageiro *> & getPassageiros() const;

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_VOO_H
