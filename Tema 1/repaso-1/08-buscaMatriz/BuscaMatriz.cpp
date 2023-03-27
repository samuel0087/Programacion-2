/**
    1. Hacer una función que reciba como parámetros una matriz de enteros de 10x10
    y un número entero (entre 0 y 9), y devuelva el máximo de la fila indicada por el
    segundo parámetro.
**/

#include <iostream>
using namespace std;

int buscaMatriz(int [10][10], int);

int main(void){
    const int TAM = 10;
    int num = 7;

    int m[TAM][TAM] = {
        {1,2,3,4,5,66,7,8,9,19},
         {1,2,3,4,55,6,7,8,9,19},
         {1,2,3,4,5,6,7,8,9,19},
         {1,2,3,4555,5,46,7,8,9,19},
         {1,2,37,4,5,6,7,8,96,19},
         {1,2,3,4,5,56,7,8,95,19},
         {1,2,3,42,5,6,7,8,9,19},
         {1,2,3,4,5,6,777,8,9,19},
         {1,2,3,4,5,64,7,8,9,19},
         {1,2,3,4,5,6,7,8,79,19}
    };

    cout << buscaMatriz(m, num-1);


  return 0;
}

int buscaMatriz(int m[][10], int num)
{
    const int TAM = 10;
    int numMayor = m[num][0];

    for(int i = 1; i < TAM; i++)
    {
        if(m[num][i] > numMayor)
        {
            numMayor = m[num][i];
        }
    }

    return numMayor;
}
