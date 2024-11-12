#include "computadora.h"
#include "iostream"
#include <vector>
#include <string>

using namespace std;

computadora::computadora(char simbolo){
    this->botPlayer = simbolo;
}

char computadora::proximoJugador(tateti t){
    int contadorX = 0;
    int contadorY = 0;

    for (int i=0; i<9; i++){
        if (t.getValor(i) == 'X'){
            contadorX += 1;
        }else if (t.getValor(i) == 'O'){
            contadorY += 1;
        }
    }
    if (contadorX <= contadorY){
        return 'X';
    }else{
        return 'O';
    }
}

tateti computadora::resultado(const tateti& t, int mov){
    tateti tOut = t;

    if (tOut.posicionValida(mov)){
        char marca = proximoJugador(tOut);
        tOut.setValor(mov,marca);
    }

    return tOut;
}


//pair<posicion, score>
pair<int, int> computadora::minimax(tateti tablero, char player, int alpha, int beta){
    char max_player = this->humanPlayer;
    char min_player = this->botPlayer;

    string salida = tablero.esHoja();

    if (salida != "") {
        if (salida == "GANO JUGADOR 'X'") {
            return make_pair(-1, 1);
        } else if (salida == "GANO JUGADOR 'O'") {
            return make_pair(-1, -1);
        } else {
            return make_pair(-1, 0);
        }
    }


    pair<int, int> best;

    if (player == max_player){
        best = {-1, -999};
    }else{
        best = {-1, 999};
    }

    for (int& posible_move : tablero.movPosibles()) {
        tateti newTablero = resultado(tablero,posible_move);

        char proximo = (player == max_player) ? min_player : max_player;

        pair<int,int> valoracion_del_movimiento = this->minimax(newTablero, proximo,alpha,beta);

        valoracion_del_movimiento.first = posible_move;

        if (player == max_player){
            if (valoracion_del_movimiento.second > best.second){
                best = valoracion_del_movimiento;
            }
            alpha = std::max(alpha, best.second);
        }else{
            if (valoracion_del_movimiento.second < best.second){
                best = valoracion_del_movimiento;
            }
            beta = std::min(beta, best.second);
        }

        if (beta <= alpha) {
            break;
        }
    }
    return best;
}

char computadora::getSimbolo(){
    return this->botPlayer;
}

int computadora::movimientoMaquina(tateti tablero){
    int casilla = this->minimax(tablero, this->botPlayer,-9999,9999).first;
    return casilla;
}
