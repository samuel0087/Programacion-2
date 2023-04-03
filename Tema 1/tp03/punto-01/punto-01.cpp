/**
1) Una empresa vende 5 diferentes tipos de art�culos en 3 sucursales. Por cada venta que
realiza, se anotaron los siguientes datos:
- Nro. de art�culo (1 a 5)
- Nro. de sucursal (1 a 3)
- Cantidad vendida
Este lote finaliza con un registro con nro. de art�culo igual a cero. Puede haber m�s de
un registro para el mismo art�culo en la misma sucursal. Se desea determinar e
informar:
a) Un listado con la cantidad de art�culos vendidos en cada sucursal, con el siguiente
formato:
                Sucursal 1 Sucursal 2  Sucursal 3
Art�culo 1      Xxxxx       xxxxx       xxxxx
Art�culo 2      Xxxxx       xxxxx       xxxxx
Art�culo 3      Xxxxx       xxxxx       xxxxx
Art�culo 4      Xxxxx       xxxxx       xxxxx
Art�culo 5      Xxxxx       xxxxx       xxxxx


b) Informar cual fue el nro. de art�culo m�s vendido en total en cada una de las tres
sucursales
**/

#include <iostream>
#include <iomanip>
using namespace std;

void listarArticulos(int [3][5],int,int);

int main(void){
    const int TAMART = 5;
    const int TAMSUC = 3;
    int mSucursales[TAMSUC][TAMART] = {}, vMaxSucursales[TAMSUC] = {};
    int numSucursal, numArticulo, cantVendida;

    cout << "Ingrese numero de articulo: ";
    cin >> numArticulo;

    while(numArticulo != 0) {
        cout << "Ingrese numerro de sucursal: ";
        cin >> numSucursal;

        cout << "Ingrese cantidad vendida: ";
        cin >> cantVendida;

        mSucursales[numSucursal-1][numArticulo-1] += cantVendida;

        cout << endl;
        cout << "----------------------------" << endl;
        cout << "Ingrese numero de articulo: ";
        cin >> numArticulo;
    }

    listarArticulos(mSucursales, TAMSUC, TAMART);


  return 0;
}


void listarArticulos(int m[3][5],int tamSucu,int tamArt) {
    cout << left;
    cout << setw(50) << "----------------------------------------" << endl;
    cout << setw(12) << " " << "|";
    cout << setw(8) << "SUCU 1" << "|";
    cout << setw(8) << "SUCU 2" << "|";
    cout << setw(8) << "SUCU 3" << "|" << endl;
    cout << setw(50) << "----------------------------------------" << endl;

    for(int i = 0; i < tamArt; i++){
        cout << setw(10) << "Articulo " << setw(2) << i+1 << "|";

        for(int j=0; j < tamSucu; j++ ){
            cout << setw(4) << " ";
            cout << setw(4) << m[j][i] << "|";
        }

        cout << endl;
        cout << setw(50) << "----------------------------------------" << endl;
    }
}
