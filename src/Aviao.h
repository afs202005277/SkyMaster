#ifndef PROJETO1_AVIAO_H
#define PROJETO1_AVIAO_H

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include "Data.h"
#include "Servico.h"
#include "Aeroporto.h"
#include "Voo.h"
#include "Mala.h"
#include "CarrinhoTransporte.h"

using namespace std;

class CarrinhoTransporte;
class Mala;
class Servico;
class Funcionario;
class Voo;

class Aviao {
private:
    int capacidade;
    std::list<Voo*> plano;
    std::string matricula, tipo;
    std::queue<Servico*> servicos;
    std::stack<Servico*> servicosProcessados;
    std::vector<Mala*> carga;
    CarrinhoTransporte *carrinhoAssociado;

    void sortPlano();
public:
    Aviao(int capacidade, const list<Voo *> &plano, const string &matricula, const queue<Servico *> &servicos,
          const stack<Servico *> &pastServices, const vector<Mala *> &carga, CarrinhoTransporte *carrinhoAssociado,
          std::string tipo);

    Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::queue<Servico *> servicos,
          std::string tipo);

    Aviao(int capacidade, std::list<Voo *> plano, std::string matricula, std::string tipo);

    Aviao(int capacidade, std::string matricula, std::string tipo);

    int getCapacidade() const;

    void setCapacidade(int capacidade);

    const std::list<Voo *> & getPlano() const;

    void setPlano(std::list<Voo *> plano);

    const std::string &getMatricula() const;

    void setMatricula(const std::string &matricula);

    const string &getTipo() const;

    void setTipo(const string &tipo);

    std::queue<Servico *> getServicos() const;

    void setServicos(const std::queue<Servico *> &servicos);

    const stack<Servico *> &getServicosProcessados() const;

    void setServicosProcessados(const stack<Servico *> &servicosProcessados);

    const vector<Mala *> &getCarga() const;

    void setCarga(const vector<Mala *> &carga);

    CarrinhoTransporte *getCarrinhoAssociado() const;

    void setCarrinhoAssociado(CarrinhoTransporte *carrinhoAssociado);

    void addServico(Servico *servico);

    void addToPlanoVoo(Voo *voo);

    Voo& getNextVoo() const;

    /**
     * Remove o primeiro servico da fila de servicos e adiciona-o na stack de servicos ja processados
     * @return true se existir a fila servicos nao estiver vazia
     */
    bool processService();

    /**
     * Pesquisa na stack de servicos processados todos os servicos feitos pelo funcionario f
     * @param f
     * @return um vetor com apontadores para os servicos realizados pelo funcionario f, neste aviao
     */
    vector<Servico *> getPastServicesBy(const Funcionario &f) const;

    /**
     * Pesquisa na fila de servicos todos os servicos associados ao funcionario f
     * @param f
     * @return um vetor com apontadores para os servicos que vao ser realizados pelo funcionario f, neste aviao
     */
    vector<Servico *> getFutureServicesBy(const Funcionario &f) const;

    /**
     * Pesquisa no historico de servicos realizados e na lista de servicos por realizar, todos que estao associados ao funcionario f
     * @param f
     * @return um vetor com 2 posicoes: a posicao 0 contem os resultados da busca no historico de servicos e a posicao 1 contem os resultados da busca nos servicos futuros
     */
    vector<vector<Servico *>> getAllServicesBy(const Funcionario &f) const;

    /**
     * Descarrega as malas do aviao para o carrinho de transporte. Quando o carrinho ficar cheio, vai descarregar as malas no aeroporto e continua o processo
     * @param carrinho
     */
    void descarregarMalas();

    /**
     * Adiciona uma mala ao armazenamento do avião
     * @param m
     */
    void addMala(Mala *m);

    /**
     * Remove do plano de voo do aviao, o voo passado como argumento
     * @param voo
     * @return true se o voo existir no plano de voo
     */
    bool removeFromPlanoVoo(Voo &voo);


    void viajar();

    friend bool operator==(const Aviao &lhs, const Aviao &rhs);
};


#endif //PROJETO1_AVIAO_H
