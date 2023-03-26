/**
    . Hacer una función que reciba como parámetros un vector de enteros y un
    número entero que indica la cantidad de componentes del vector, y que devuelva
    el valor mínimo contenido en ese vector.

**/

#include <iostream>
using namespace std;

int getMinimo(int* v, int tam){
    int minimo = v[0];

    for(int i = 1; i < tam; i++)
    {
        if(v[i] < minimo)
        {
            minimo = v[i];
        }
    }

    return minimo;
}

int main()
{
    int const TAM = 5;
    int menor, vec[TAM] = {25, 50, 100, -5, 0};

    menor = getMinimo(vec, TAM);

    cout << "El numero menor es: " << menor;


    return 0;
}
