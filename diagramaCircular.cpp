#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#include "Funciones.h"

void diagramaCircular(){

    int tamCuadro, opcion;

    cout << "Ingrese la cantidad de palabras a comparar: ";
    cin >> tamCuadro;

    vector<string> labels(tamCuadro); // Usamos vector en lugar de array para mejor manejo
    cout << "Ingrese las palabras a comparar: " << endl;

    for (int i = 0; i < tamCuadro; ++i) {
        cin >> labels[i];
    }

    vector<int> sizes(tamCuadro); // Usamos vector en lugar de array para mejor manejo
    cout << "Ingrese los valores de cada palabra: " << endl;

    for (int i = 0; i < tamCuadro; ++i) {
        cin >> sizes[i];
    }

    // Suma total de las cantidades
    int total = 0;
    for (int size : sizes) {
        total += size;
    }

    // Crear un gr fico de texto (ASCII) simple basado en porcentajes
    vector<int> percentages; // Cambiamos la declaraci¢n de 'percentages' a vector
    for (int size : sizes) {
        percentages.push_back(static_cast<int>(round((size / static_cast<float>(total)) * 100)));
    }

    // Mostrar el diagrama circular (aproximado con caracteres)
    cout << "Diagrama circular aproximado (basado en porcentajes):\n\n";

    for (size_t i = 0; i < labels.size(); ++i) {
        cout << labels[i] << ": ";
        for (int j = 0; j < percentages[i]; ++j) {
            cout << "*";  // Cada asterisco representa un porcentaje
        }
        cout << " " << percentages[i] << "%" << endl;
    }

    cout << endl;
    cout << "=======================" <<endl;
    cout << endl;
    cout << "1-REGRESAR AL MENU"<<endl;
    cout << "0-FINALIZAR PROGRAMA"<<endl;
    cin >> opcion;

    switch (opcion){
    case 1:
        system("cls");
        main();
        break;
    case 0:
        return;
    }

    return;
}
