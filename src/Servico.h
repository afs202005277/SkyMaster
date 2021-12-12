//
// Created by andre on 28/11/2021.
//

#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"
#include "Funcionario.h"

enum Tipo {manutencao, limpeza};

class Servico {
    Tipo tipo;
    Data data;
    Funcionario funcionario;
};


#endif //PROJETO1_SERVICO_H
