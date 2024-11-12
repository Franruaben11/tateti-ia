#include "persona.h"
#include "iostream"
#include <vector>
#include <string>

using namespace std;

persona::persona(char elem){
    simbolo = elem;
}

char persona::getSimbolo(){
    return simbolo;
}

int persona::movimiento(tateti t){
    int elem;
    while (true){
        cout << "Seleccione la posicion" << endl;
        cin >> elem;
        cout << endl;

        if (t.posicionValida(elem))
            break;
    }
    return elem;
}
