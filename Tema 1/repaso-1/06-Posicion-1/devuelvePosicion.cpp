/**
    . Hacer una función que reciba como parámetros un vector de enteros de 10
    elementos y un número entero, y que devuelva la posición si el número recibido
    existe en el vector, o -1 si no existe.
**/

int searchNumber(int*, int, int);

#include <iostream>
using namespace std;

int main(void){
    const int TAM = 10;
    int v[TAM] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
    int num = 15;

    int position = searchNumber(v, TAM, num);

    if(position != -1)
    {
        cout << "La posicion del numero buscado es: " << position << endl;
    }
    else
    {
        cout << "No se enconto numero";
    }

  return 0;
}


int searchNumber(int* v, int tam, int num)
{
    int position = -1;

    for(int i = 0; i < tam; i++)
    {
        if(num == v[i])
        {
            position = i + 1;
        }
    }

    return position;

}
