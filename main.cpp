#include <iostream>
#include <Aeroporto.h>
#include <Passageiro.h>
#include <vector>
#include <Aviao.h>
#include "Voo.h"

int main() {
    auto *OPO = new Aeroporto("Aeroporto Francisco Sá Carneiro", "Porto", "Portugal");
    auto *LIS = new Aeroporto("Aeroporto de Lisboa", "Lisboa", "Portugal");
    auto *FAO = new Aeroporto("Aeroporto de Faro", "Faro", "Portugal");
    auto *LAX = new Aeroporto("Los Angeles International Airport", "Los Angeles", "USA");
    auto *JFK = new Aeroporto("John F. Kennedy International Airport", "New York", "USA");
    auto *LGW = new Aeroporto("Gatwick Airport", "London", "United Kingdom");


    Passageiro p1("Julieta Branco", 30, 882128799);
    Passageiro p2("Arthur Borges", 50, 947739138);
    Passageiro p3("Nicolau Melo", 20, 700001005);
    Passageiro p4("Solange Leite", 70, 393213807);
    Passageiro p5("Sandra Valente", 20, 555057094);
    Passageiro p6("Tiago Gouveia", 18, 710052462);
    Passageiro p7("Armando Santos", 30, 383973487);
    Passageiro p8("Bernardino Soares", 40, 903373072);
    Passageiro p9("Joaquina Mota", 80, 626482872);
    Passageiro p10("Hugo Monteiro", 35, 575041321);


    Voo v1(1, 523, Data(2021, 12, 17), OPO, LAX, 55),
        v2(2, 50, Data(2022, 1, 1), FAO, OPO),
        v3(3, 300, Data(2021, 12, 25), JFK, LGW);





    return 0;
}
