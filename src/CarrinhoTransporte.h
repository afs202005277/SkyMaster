#ifndef PROJETO1_CARRINHOTRANSPORTE_H
#define PROJETO1_CARRINHOTRANSPORTE_H

#include <vector>
#include "Mala.h"
#include <stack>
#include "Terminal.h"
#include "Aeroporto.h"

using namespace std;
class Mala;
class Aviao;
class Terminal;

class CarrinhoTransporte : public Terminal {
private:
    int nCarruagens, nPilhas, nMalas;
    std::vector<std::vector<std::stack<Mala*>>> carga;
    Aviao * aviao;
    Aeroporto * aeroporto;

    /**
     * Ordena as malas alfabeticmente, pelo nome do dono
     * @param m1 apontador da mala m1
     * @param m2 apontador da mala m2
     * @return true se dono de m1 < dono de m2
     */
    static bool sorterMalas(Mala* m1, Mala* m2);
public:
    CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aeroporto *aeroporto, Aviao *aviao = nullptr);

    const std::vector<std::vector<std::stack<Mala *>>> &getCarga() const;

    void setCarga(const std::vector<std::vector<std::stack<Mala *>>> &carga);

    Aviao *getAviao() const;

    void setAviao(Aviao *aviao);

    int getNCarruagens() const;

    void setNCarruagens(int nCarruagens);

    int getNPilhas() const;

    void setNPilhas(int nPilhas);

    int getNMalas() const;

    void setNMalas(int nMalas);

    bool addMalas(std::vector<Mala*> m);

    /**
     * Descarrega as malas do carrinho no aviao que lhe foi atribuido
     */
    void descarregarMalasAviao();

    /**
     * Descarrega as malas do carrinho no aeroporto que lhe foi atribuido
     */
    void descarregarMalasAeroporto();

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;

    /**
     * Adiciona uma mala ao carrinho
     * @param pMala apontador da mala que vai ser adicionada
     * @return true se conseguir adicionar (se tiver espaço)
     */
    bool addMala(Mala *&pMala);

    /**
     * Um carrinho é menor que outro quando tem menos carruagens. Em caso de empate, é menor quando tem menos pilhas por carruagem.
     * Em caso de empate, é menor quando tem menos malas por pilha.
     * @param lhs
     * @param rhs
     * @return true se o carrrinho for menor que o outro
     */
    friend bool operator<(const CarrinhoTransporte &lhs, const CarrinhoTransporte &rhs);

    Aeroporto *getAeroporto() const;

    void setAeroporto(Aeroporto *aeroporto);

    list<Mala*> getMalasAlfabeticamente();
};


#endif //PROJETO1_CARRINHOTRANSPORTE_H
