#include <iostream>
#include <math.h> ///libreeria de c++ de matematica
#include <iomanip>
using namespace std;

#include "Funciones.h"

void calculadoraDescriptiva(){

    int opcion, variables, i, j, tam, mayor, filas;
    cout << "ingrese la cantidad de variables: ";
    cin >> variables;

    float matriz[variables] {-1}, listNumeros[variables] {-1}, fi[variables] {0}, Fi[variables] {}, hi[variables] {}, Hi[variables] {}, moda, mediana=0, promedio =0, varianza =0, desvio = 0, cv=0;

    cout << "ingrese la lista de numeros que solicita el enunciado: " << endl;
    for(i=0; i<variables; i++)
    {
        matriz[i]=i;
        cin >> listNumeros[i];
    }

    system("cls");
    cout << endl;
  for(i=0; i<variables; i++)
    {
        cout << listNumeros[i] << "  ";
    }

    cout << endl;
///buscamos los n£meros repetidos comparando ambos arrays (fi)
    for(i=0; i<variables; i++)
    {
        for(j=0; j<variables; j++)
        {
            if(matriz[i]==listNumeros[j])
            {
                fi[i]+=1;
            }
        }
        if(fi[i] != 0)
        {
            tam = i;
        }
    }
    filas = fi[0];
    for(i=0; i<tam; i++){
        if(fi[i+1] > filas){
            filas = fi[i+1];
        }
    }

    ///calcularemos la FI (frecuencia absoluta acumulada)
    Fi[0]=fi[0];
    for(i=0; i<variables; i++)
    {
        if(fi[i+1] != 0)
        {
            Fi[i+1]= Fi[i]+fi[i+1];
        }
    }

    ///calculamos frecuencia relativa simple hi o fr (fi / total de variables)
    for(i=0; i<variables; i++)
    {
        hi[i] = fi[i]/variables;
    }

    ///calculamos frecuencia relativa acumulada (Hi o Fr)
    Hi[0]=hi[0];
    for(i=0; i<=tam; i++)
    {
        if(hi != 0)
        {
            Hi[i+1]= hi[i+1]+Hi[i];
        }
    }

    ///mostramos tabla en pantalla
    cout << "-------------------------------------------------------" << endl;
    for(i=0; i<=tam; i++)
    {
      if (fi[i] != 0 && matriz[i] < variables){

        cout << matriz[i] << "   " << fi[i]<< "  " << Fi[i] << "     " << hi[i] << "     " << Hi[i] <<endl;
      }
    }

    ///calculamos moda (el que m s se repite)
    mayor = fi[0];
    for(i=1; i<=tam; i++)
    {
        if(fi[i]>mayor)
        {
            moda = i;
            mayor = fi[i];
        }
    }

    ///calculamos mediana (el n£mero del medio)
    if((tam+1)%2 != 0)
    {
        mediana = tam / 2;
    }
    else
    {
        mediana = (tam+1) / 2;
        mediana -= 0.5;
    }
    /// si tengo muchos numeros, por ejemplo  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    ///hago (todos los nums + 1)/ 2, asi. (20 + 1) / 2 = 10,5 que est  entre 10 y 11.
    ///entonces busco 10 y busco 11, y los promedio.

    ///calculamos promedio o media aritm‚tica
    for(i=0; i<=tam; i++)
    {
        promedio += matriz[i]*fi[i];
    }
    promedio = promedio / variables;

    ///calculamos la varianza
    ///S2 = ((numero de dato - promedio) cuadrado * frecuencia del valor + ....) / N(poblaci¢n) o n-1 (muestra)
    cout << "Es poblacional(1) o muestral (otro)?"<< endl;
    cin >> opcion;
    for(i=0; i<=tam; i++)
    {
        varianza += (pow((matriz[i] - promedio),2) * fi[i]);
    }
    if(opcion==1)
    {
        varianza = varianza / variables;
    }
    else
    {
        varianza = varianza / (variables - 1);

    }

    ///calculamos el desv¡o (raiz cuadrada de varianza)
    desvio = sqrt(varianza);

    ///calculamos coeficiente de variacion
    ///(desvio/promedio)*100
    cv = (desvio / promedio) * 100;



    cout << "El n£mero que mas se repite es: " << moda << endl;
    cout << "el numero de la mediana es: " << mediana << endl;
    cout << "el promedio o media aritmetica es: " << promedio << endl;
    cout << "la varianza es: " << varianza << endl;
    cout << "el desv¡o es: " << desvio << endl;
    cout << "el coeficiente de variaci¢n es: " << cv << endl;



    cout << "-------------------------------------------------------" << endl;
    cout << endl;
    ///armamos gr fico
    // Crear la matriz din mica
    char** matrizG = new char*[filas + 1];
    for(int i = 0; i <= filas; i++) {
        matrizG[i] = new char[tam + 2];
    }

    // Inicializaci¢n de la matriz
    for(int i = 0; i <= filas; i++) {
        for(int j = 0; j <= tam+1; j++) {
            if (j == 0) {
                matrizG[i][j] = '0' + (filas - i); // N£meros de la escala vertical
            }
            else if(i == filas ) {
                matrizG[i][j] = '0' + (j - 1); // N£meros de la escala horizontal
            }
            else{
                matrizG[i][j] = ' '; // Inicializar con espacios
            }
        }
    }


    // Rellenar las barras seg£n los valores en el arreglo 'fi'
    for(int j = 0; j <= tam; j++) {
        for(int i = 1; i <= fi[j]; i++) {
            matrizG[filas - i][j + 1] = '|';
        }
    }

    // Imprimir la matriz
    for(int i = 0; i <= filas; i++) {
        for(int j = 0; j <= tam+1 ; j++) {
            cout << setw(2) << matrizG[i][j] << ' ';
        }
        cout << '\n';
    }

    // Liberar la memoria din mica
    for(int i = 0; i <= filas; i++) {
        delete[] matrizG[i];
    }
    delete[] matrizG;

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
