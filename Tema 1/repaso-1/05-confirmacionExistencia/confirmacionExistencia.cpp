/**
 Hacer una función que reciba como parámetros un vector de enteros de 10
elementos y un número entero, y que devuelva verdadero si el número recibido
existe en el vector, o falso si no existe.
**/

#include <iostream>
using namespace std;

bool searchNumber(int*, int, int);

int main(void)
{
    const int TAM = 10;
    int v[TAM] ={2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int num = 2;

    if(searchNumber(v, TAM, num))
    {
        cout << "EXISTE";
    }
    else
    {
        cout << "NO EXISTE";
    }


    return 0;
}

bool searchNumber(int* v, int tam, int num)
{
    bool exist = false;

    for(int i = 0; i < tam; i++)
    {
        if(num == v[i])
        {
            exist = true;
        }
    }

    return exist;
}
