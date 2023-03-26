/**
. Hacer una funci�n que reciba como par�metros un vector de enteros y un
    n�mero entero que indica la cantidad de componentes del vector, y que devuelva
    el valor m�nimo contenido en ese vector.

**/

#include <iostream>
using namespace std;

int getMayor(int* v, int tam){
    int mayor = v[0];

    for(int i = 1; i < tam; i++)
    {
        if(v[i] > mayor)
        {
            mayor = v[i];
        }
    }

    return mayor;
}

int main()
{
    int const TAM = 5;
    int mayor, vec[TAM] = {25, 50, 100, -5, 0};

    mayor = getMayor(vec, TAM);

    cout << "El numero mayor es: " << mayor;


    return 0;
}


