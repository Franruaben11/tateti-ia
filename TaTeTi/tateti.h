#ifndef TATETI_H
#define TATETI_H

#include "iostream"
#include <string>
#include <vector>

using namespace std;

class tateti {
private:
    vector<char> tablero;

public:
    tateti();
    string esHoja();
    bool ganoJugador(char simb);
    void mostrarTablero();
    void start();
    bool posicionValida(int pos);
    bool colocarMarca(int posicion, char marca);
    vector<char> getTablero();
    char getValor(int pos);
    void setValor(int posicion, char simbolo);
    bool tableroCompleto();
    vector<int> movPosibles();
};

#endif // TATETI_H
