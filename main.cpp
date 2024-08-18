#include <iostream>

using namespace std;

#include "Funciones.h"

int main()
{
    int opcion;
    cout << "=======================" <<endl;
    cout << "CALCULADORA ESTADISTICA" << endl;
    cout << "=======================" <<endl;
    cout << endl;
    cout << "1-CALCULADORA ESTADISTICA DESCRIPTIVA"<<endl;
    cout << "2-DIAGRAMA CIRCULAR"<<endl;
    cout << "1-FINALIZAR PROGRAMA"<<endl;
    cin >> opcion;

    switch (opcion){
    case 1:
        system("cls");
        calculadoraDescriptiva();
        break;
    case 2:
        system("cls");
        diagramaCircular();
    case 0:
        return 0;
    }
    return 0;
}
