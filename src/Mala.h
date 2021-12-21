#ifndef PROJETO1_MALA_H
#define PROJETO1_MALA_H

#include "Passageiro.h"
#include "Aviao.h"
#include "Terminal.h"

class Passageiro;
class Terminal;

class Mala : public Terminal {
private:
    Passageiro* dono;

    /**
     * Aviao em que a mala se encontra
     */
    Aviao *despachada;
    float peso;
public:
    Mala(Passageiro *dono, float peso, Aviao *despachada = nullptr);

    Aviao *getDespachada() const;

    void setDespachada(Aviao *despachada);

    Passageiro * getDono() const;

    void setDono(Passageiro* dono);

    float getPeso() const;

    void setPeso(float peso);

    /**
     * Duas malas são iguais quando todos os seus atributos são iguais
     * @param lhs
     * @param rhs
     * @return true se as malas forem iguais
     */
    friend bool operator==(const Mala &lhs, const Mala &rhs);

    /**
     * Uma mala é menor que outra quando é mais leve, ou, em caso de empate,
     * quando o nome do dono é menor que o nome do dono da outra mala
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator<(const Mala &lhs, const Mala &rhs);

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;
};


#endif //PROJETO1_MALA_H
