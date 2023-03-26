/**
    Hacer una función que reciba como parámetros un vector de enteros de 10
    elementos y un número entero, y que devuelva la cantidad de veces que el
    número recibido como parámetro se repite dentro del vector.
**/

#include <iostream>
using namespace std;

int getCantIteraciones(int*, int, int);

int main(void){
    const int TAM = 10;
    int v[TAM] = {1, 2,3,4,5,3,7,3,9,10};
    int num = 3;

    int iteraciones = getCantIteraciones(v, TAM, num);

    if(iteraciones)
    {
        cout << "Cantidad de iteraciones de ese numero: " << iteraciones;
    }
    else
    {
        cout << "No existe como Boca Jn";
    }

  return 0;
}

getCantIteraciones(int* v, int tam, int num)
{
    int cantIteraciones = 0;

    for(int i = 0; i < tam; i++)
    {
        if(num == v[i])
        {
            cantIteraciones++;
        }
    }

    return cantIteraciones;
}
