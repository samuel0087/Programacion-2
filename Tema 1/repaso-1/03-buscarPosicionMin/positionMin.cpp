/**
    3. Hacer una función que reciba como parámetros un vector de enteros y un
    número entero que indica la cantidad de componentes del vector, y que devuelva
    la posición que cupa el valor mínimo contenido en ese vector.
**/

#include <iostream>
using namespace std;

int getMinPosition(int*, int);

int main(void)
{
    int const TAM = 5;
    int v[TAM] = {1, 44, 66, -6, 8};

    int position = getMinPosition(v, TAM);

    cout << "El numero minimo es: " << v[position-1] << endl;
    cout << "Posicion n: " << position;

  return 0;
}

int getMinPosition(int* v, int tam)
{
    int position = 1;
    int minimNumber = v[0];

    for(int i = 1; i < tam; i++)
    {
        if(v[i] < minimNumber)
        {
            minimNumber = v[i];
            position = i + 1;
        }
    }

    return position;

}
