#ifndef PROJETO1_TEMPO_H
#define PROJETO1_TEMPO_H


#include <string>
#include "Terminal.h"

class Tempo {
private:
    int hora;
    int minuto;
    int segundo = 0;
public:
    Tempo(int hora, int minuto, int segundo);

    Tempo(const std::string &tempo);

    int getHora() const;

    friend bool operator==(const Tempo &lhs, const Tempo &rhs);

    friend bool operator!=(const Tempo &lhs, const Tempo &rhs);

    void setHora(int hora);

    int getMinuto() const;

    void setMinuto(int minuto);

    int getSegundo() const;

    void setSegundo(int segundo);

    std::string getTempo();

    friend bool operator<(const Tempo &lhs, const Tempo &rhs);

    friend bool operator>(const Tempo &lhs, const Tempo &rhs);

    friend bool operator<=(const Tempo &lhs, const Tempo &rhs);

    friend bool operator>=(const Tempo &lhs, const Tempo &rhs);

};


#endif //PROJETO1_TEMPO_H
