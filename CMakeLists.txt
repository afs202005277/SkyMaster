cmake_minimum_required(VERSION 3.20)
project(Projeto1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projeto1 main.cpp src/Aviao.cpp src/Aviao.h src/Data.cpp src/Data.h src/Servico.cpp src/Servico.h src/Funcionario.cpp src/Funcionario.h src/Aeroporto.cpp src/Aeroporto.h src/Passageiro.cpp src/Passageiro.h src/CarrinhoTransporte.cpp src/CarrinhoTransporte.h src/Transporte.cpp src/Transporte.h src/bst.h src/Bilhete.cpp src/Bilhete.h)
