#include "tateti.h"
#include "persona.h"
#include "computadora.h"
#include "iostream"
#include <vector>

using namespace std;

tateti::tateti() : tablero(9, '-') {}

bool tateti::tableroCompleto(){
    for (int i=0; i<9; i++){
        if (tablero[i] == '-'){
            return false;
        }
    }
    return true;
}

vector<int> tateti::movPosibles(){
    vector<int> vecOut;
    for (int i=0; i<9; i++){
        if (this->posicionValida(i)){
            vecOut.push_back(i);
        }
    }
    return vecOut;
};

bool tateti::ganoJugador(char simbolo) {
    if (tablero[0] == tablero[1] && tablero[1] == tablero[2] && tablero[0] == simbolo) return true;
    if (tablero[3] == tablero[4] && tablero[4] == tablero[5] && tablero[3] == simbolo) return true;
    if (tablero[6] == tablero[7] && tablero[7] == tablero[8] && tablero[6] == simbolo) return true;
    if (tablero[0] == tablero[3] && tablero[3] == tablero[6] && tablero[0] == simbolo) return true;
    if (tablero[1] == tablero[4] && tablero[4] == tablero[7] && tablero[1] == simbolo) return true;
    if (tablero[2] == tablero[5] && tablero[5] == tablero[8] && tablero[2] == simbolo) return true;
    if (tablero[0] == tablero[4] && tablero[4] == tablero[8] && tablero[0] == simbolo) return true;
    if (tablero[2] == tablero[4] && tablero[4] == tablero[6] && tablero[2] == simbolo) return true;
    return false;
}

char tateti::getValor(int pos){
    if (pos>=0 && pos<9)
        return this->tablero[pos];
    return 'Z';
};

string tateti::esHoja(){
    if (ganoJugador('X')){
        return "GANO JUGADOR 'X'";
    }else if (ganoJugador('O')){
        return "GANO JUGADOR 'O'";
    }else if (tableroCompleto()){
        return "EMPATE";
    }
    return "";
}


void tateti::mostrarTablero() {
    for (int i=0; i<9; i++){
        cout << tablero[i] << " ";
        if (i==2 || i==5 || i==8)
            cout << endl;
    }
}

void tateti::setValor(int pos, char valor){
    this->tablero[pos] = valor;
}

//retorna una copia;  para retornar la referencia -> vector<char>& tateti::getTablero()
vector<char> tateti::getTablero(){
    return tablero;
}

bool tateti::posicionValida(int pos){
    return pos < 9 && pos >=0 && tablero[pos] == '-';
}

bool tateti::colocarMarca(int posicion, char marca){
    if (posicionValida(posicion)){
        tablero[posicion] = marca;
        return true;
    }else{
        return false;
    }
}

void tateti::start(){
    persona p('X');
    computadora bot('O');
    string resultado;

    while(true){
        cout << "Es el turno de " << p.getSimbolo() << endl;
        this->mostrarTablero();
        int mov = p.movimiento(*this);
        this->setValor(mov, p.getSimbolo());

        resultado = esHoja();
        if (resultado != ""){
            cout << resultado << endl;
            this->mostrarTablero();
            break;
        }

        int movC = bot.movimientoMaquina(*this);
        this->setValor(movC, bot.getSimbolo());


        resultado = esHoja();
        if (resultado != ""){
            cout << resultado << endl;
            this->mostrarTablero();
            break;
        }



    }
}

