//
// Created by andre on 12/12/2021.
//

#include "Aeroporto.h"


Aeroporto::Aeroporto(std::string name, std::string city, std::string country) : name(std::move(name)), city(std::move(city)),
                                                                                country(std::move(country)) {}

const std::string &Aeroporto::getName() const {
    return name;
}

void Aeroporto::setName(const std::string &name) {
    Aeroporto::name = name;
}

const std::string &Aeroporto::getCity() const {
    return city;
}

void Aeroporto::setCity(const std::string &city) {
    Aeroporto::city = city;
}

const std::string &Aeroporto::getCountry() const {
    return country;
}

void Aeroporto::setCountry(const std::string &country) {
    Aeroporto::country = country;
}

Aeroporto::Aeroporto() = default;
