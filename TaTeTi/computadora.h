#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include "tateti.h"
#include "iostream"
#include <vector>

class computadora{
private:
    char botPlayer;
    char humanPlayer;

public:
    computadora(char simbolo);

    //sabiendo que empieza con X
    char proximoJugador(tateti tablero);

    //devuelve todos los movimientos posibles
    vector<int> movPosibles(tateti tablero);

    //le pasamos el tablero y el movimiento , nos devuelve un tablero con el movimineto realizado, con proximoJugador(tablero) sabemos si el movimiento lo hace 'X' o 'O'
    tateti resultado(const tateti& tablero, int movimiento);

    char getSimbolo();


    // devuelve un map<posicion,score>, donde nos dice la posicion a agregar y el valore
    pair<int,int> minimax(tateti tablero,char simbolo, int alpha, int beta);

    int movimientoMaquina(tateti t);
};


#endif // COMPUTADORA_H
