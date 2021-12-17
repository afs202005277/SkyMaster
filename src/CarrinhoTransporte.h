#ifndef PROJETO1_CARRINHOTRANSPORTE_H
#define PROJETO1_CARRINHOTRANSPORTE_H

#include <vector>
#include "Mala.h"
#include <stack>
#include "Terminal.h"
using namespace std;
class Mala;
class Aviao;

class CarrinhoTransporte : public Terminal {
private:
    int nCarruagens, nPilhas, nMalas;
    std::vector<std::vector<std::stack<Mala*>>> carga;
    Aviao * aviao;
    Aeroporto * aeroporto;

public:
    const vector<vector<stack<Mala *>>> &getCarga() const;

    void setCarga(const vector<vector<stack<Mala *>>> &carga);

    Aviao *getAviao() const;

    void setAviao(Aviao *aviao);

    CarrinhoTransporte(int nCarruagens, int nPilhas, int nMalas, Aeroporto *aeroporto, Aviao *aviao = nullptr);

    int getNCarruagens() const;

    void setNCarruagens(int nCarruagens);

    int getNPilhas() const;

    void setNPilhas(int nPilhas);

    int getNMalas() const;

    void setNMalas(int nMalas);

    bool addMalas(vector<Mala*> m);

    void descarregarMalasAviao();

    void descarregarMalasAeroporto();

    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;

    bool addMala(Mala *&pMala);
};


#endif //PROJETO1_CARRINHOTRANSPORTE_H
