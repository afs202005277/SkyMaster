#ifndef PROJETO1_TEMPO_H
#define PROJETO1_TEMPO_H


#include <string>
#include <sstream>
#include <iomanip>
#include "Terminal.h"
class Terminal;
class Tempo {
private:
    int hora;
    int minuto;
    int segundo;
public:
    Tempo(int hora, int minuto, int segundo=0);

    Tempo(const std::string &tempo);

    int getHora() const;

    void setHora(int hora);

    int getMinuto() const;

    void setMinuto(int minuto);

    int getSegundo() const;

    void setSegundo(int segundo);

    /**
     * Retorna uma string no formato hh:mm
     * @return string no formato hh:mm
     */
    std::string getTempo();

    /**
     * Verifica se um tempo é menor que outro
     * @param lhs
     * @param rhs
     * @return true se a hora de lhs for menor que a de rhs. Em caso de empate, recorre-se a comparacao dos minutos.
     * Se empatar de novo, compara-se os segundos
     */
    friend bool operator<(const Tempo &lhs, const Tempo &rhs);

    friend bool operator>(const Tempo &lhs, const Tempo &rhs);

    friend bool operator<=(const Tempo &lhs, const Tempo &rhs);

    friend bool operator>=(const Tempo &lhs, const Tempo &rhs);

    /**
     * Dois tempos são iguais quando têm o mesmo valor em todos os atributos
     * @param lhs
     * @param rhs
     * @return true se forem iguais
     */
    friend bool operator==(const Tempo &lhs, const Tempo &rhs);

    friend bool operator!=(const Tempo &lhs, const Tempo &rhs);
};


#endif //PROJETO1_TEMPO_H
