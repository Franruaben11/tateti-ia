#ifndef PERSONA_H
#define PERSONA_H

#include "tateti.h"
#include "iostream"
#include <vector>

using namespace std;

class persona{
private:
    char simbolo;
public:
    persona(char elem);
    char getSimbolo();
    int movimiento(tateti t);
};

#endif // PERSONA_H
