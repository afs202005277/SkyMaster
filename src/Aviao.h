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
#include "Terminal.h"

using namespace std;

class CarrinhoTransporte;
class Mala;
class Servico;
class Funcionario;
class Voo;
class Terminal;

class Aviao : public Terminal {
private:
    int capacidade;
    std::list<Voo*> plano;
    std::string matricula, tipo;
    std::queue<Servico*> servicos;
    std::stack<Servico*> servicosProcessados;
    std::vector<Mala*> carga;
    CarrinhoTransporte *carrinhoAssociado;
    /**
     * Função auxiliar que ordena os voos pelas suas datas de partida
     */
    static bool sortPlano(const Voo *v1, const Voo *v2);

    /**
     * Função auxiliar que ordena os serviços da resposta por odem cronológica, e em caso de empate, alfabeticamente
     * @param s1 apontador do serviço s1
     * @param s2 apontador do serviço s2
     * @return true se s1 < s2
     */
    static bool sorterServicos(const Servico* s1, const Servico* s2);
public:
    Aviao(int capacidade, const std::list<Voo *> &plano, const std::string &matricula, const std::queue<Servico *> &servicos,
          const std::stack<Servico *> &pastServices, const std::vector<Mala *> &carga, CarrinhoTransporte *carrinhoAssociado,
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

    const std::string &getTipo() const;

    void setTipo(const std::string &tipo);

    std::queue<Servico *> getServicos() const;

    void setServicos(const std::queue<Servico *> &servicos);

    const std::stack<Servico *> &getServicosProcessados() const;

    void setServicosProcessados(const std::stack<Servico *> &servicosProcessados);

    const std::vector<Mala *> &getCarga() const;

    void setCarga(const std::vector<Mala *> &carga);

    CarrinhoTransporte *getCarrinhoAssociado() const;

    void setCarrinhoAssociado(CarrinhoTransporte *carrinhoAssociado);

    /**
     * Adiciona um Servico no fim da fila servicos
     * @param servico apontador do serviço que vai ser adicionado
     */
    void addServico(Servico *servico);

    /**
     * Adiciona um voo ao plano de voo e mantém o plano de voo ordenado por ordem de partida
     * @param voo apontador do voo que vai ser adicionado
     */
    void addToPlanoVoo(Voo *voo);

    /**
     * Retorna o voo a seguir ao atual, se existir
     * @return o voo seguinte
     */
    Voo& getNextVoo() const;

    /**
     * Remove o primeiro servico da fila de servicos e adiciona-o na std::stack de servicos ja processados
     * @return true se existir a fila servicos nao estiver vazia
     */
    bool processService();

    /**
     * Pesquisa na std::stack de servicos processados todos os servicos feitos pelo funcionario f
     * @param f funcionário que vai ser procurado
     * @return um vetor com apontadores para os servicos realizados pelo funcionario f, neste aviao
     */
    std::vector<Servico *> getPastServicesBy(const Funcionario &f) const;

    /**
     * Pesquisa na fila de servicos todos os servicos associados ao funcionario f
     * @param f funcionário que vai ser procurado
     * @return um vetor com apontadores para os servicos que vao ser realizados pelo funcionario f, neste aviao
     */
    std::vector<Servico *> getFutureServicesBy(const Funcionario &f) const;

    /**
     * Pesquisa no historico de servicos realizados e na std::lista de servicos por realizar, todos que estao associados ao funcionario f
     * @param f funcionário que vai ser procurado
     * @return um vetor com 2 posicoes: a posicao 0 contem os resultados da busca no historico de servicos e a posicao 1 contem os resultados da busca nos servicos futuros
     */
    std::vector<std::vector<Servico *>> getAllServicesBy(const Funcionario &f) const;

    /**
     * Descarrega as malas do aviao para o carrinho de transporte. Quando o carrinho ficar cheio, vai descarregar as malas no aeroporto e continua o processo
     */
    void descarregarMalas();

    /**
     * Adiciona uma mala ao armazenamento do avião
     * @param m apontador da mala que vai ser adicionada
     */
    void addMala(Mala *m);

    /**
     * Remove do plano de voo do aviao, o voo passado como argumento
     * @param voo apontador do voo que vai ser removido
     * @return true se o voo existir no plano de voo
     */
    bool removeFromPlanoVoo(Voo &voo);

    /**
     * - Carrega para o aviao as malas que ainda estejam no carrinho
     * - O carrinho deixa de estar associado ao aviao
     * - O aviao é adicionado ao aeroporto do destino
     * - O aviao é removido do aeroporto de origem
     * - O voo é retirado do plano de voo
     */
    void viajar();

    /**
     * Verifica se 2 avioes são iguais
     * @param lhs
     * @param rhs
     * @return true se as matrículas forem iguais
     */
    friend bool operator==(const Aviao &lhs, const Aviao &rhs);

    list<Servico*> getAllServicesAfter(Data d);
    std::string getObjectName() override;
    std::string getObjectID() override;
    bool findFunc(std::string nomeFunc) override;
    std::stack<std::string> funcs() override;
    std::vector<Terminal*> *getV(std::string nameVector) override;

    friend bool operator<(const Aviao &lhs, const Aviao &rhs);
};


#endif //PROJETO1_AVIAO_H
