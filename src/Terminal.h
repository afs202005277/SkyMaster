//
// Created by Pedro Fonseca on 16/12/2021.
//

#include <iostream>
#include <vector>
#include <stack>


#ifndef AED1_TERMINAL_H
#define AED1_TERMINAL_H


class Terminal
{
public:
    virtual std::string getObjectName() = 0;
    virtual std::string getObjectID() = 0;
    virtual bool findFunc(std::string nomeFunc) = 0;
    virtual std::stack<std::string> funcs() = 0;
    virtual std::vector<Terminal*> *getV(std::string nameVector) = 0;
};


#endif //AED1_TERMINAL_H
