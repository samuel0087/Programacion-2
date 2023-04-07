/**
Las autoridade sde la carrera de TUP estan realizando un analisis de los recursos vitales de las distintas
materias por cada una de las 20 materias de la carrera tiene la siguiente informacion:
-numero de materia (entre 1 y 20)
-nombre
-cantidd de alumnos inscriptos
-cantidad de profesores

ademas por cada ingreso de los estudianres al aula virtual se registra lo siguiente:
-legajo
-fecha de acceso( dia y mes)
-numero de materia a la que ingreso
-cantidad de horas(real)

se requiere lo siguiente:
a ) las materias que no tuvieron acceso de alumnos nunca
b ) la materia que mas cantidad de horas registro de acceso de alumnos
c ) por cada materia y dia de marzo, la cantoidad de acceso de alumnos a las aulas virtuales
*/

#include <iostream>

using namespace std;


struct materia
{
    int numMateria;
    char nomMateria[30];
    int cantAlumnos;
    int cantProfesores;
};

void cargaCadena(char*);
void cargaMaterias(materia*, int);
void mostrarMaterias(materia*, int);

int main()
{
    const int TAM = 20;
    materia materias[TAM];
    int opc = 1;

    while(opc)
    {

        cout << "Menu de inicio" << endl;
        cout << "----------------------------" << endl;

        cout << "1 - CARGAR MATERIAS" << endl;
        cout << "2 - MOSTRAR MATERIAS" << endl;
        cout << "3 - CARGAR INGRESOS" << endl;
        cout << "4 - MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS" << endl;
        cout << "5 - MATERIAS QUE MAS HORAS REISTRARON" << endl;
        cout << "6 - POR CADA MATERIA Y DIA DE MARZO , CANTIDAD DE ACCESO" << endl;
        cout << "0 - SALIR DEL PROGRAMA" << endl;

        cin >> opc;

        system("cls");

        switch (opc)
        {

        case 1:
            cargaMaterias(materias, TAM);
            break;

        case 2:
            mostrarMaterias(materias, TAM);
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 0:
            break;
        }
    }

    return 0;
}


void cargaMaterias(materia* materias, int tam)
{

    for(int i = 0; i < tam; i++)
    {
        cout << "Ingrese numero de la materia: ";
        cin >> materias[i].numMateria;

        cout << "Ingrese nombre de la materia: ";
        cargaCadena(materias[i].nomMateria);

    }

}

void cargaCadena(char* nombre)
{
    int i;
    fflush(stdin);

    for(i = 0; i < 29; i++)
    {
        cin.get(nombre[i]);

        if(nombre[i] == '\n')
        {
            break;
        }
    }

    fflush(stdin);
    nombre[i] = '\0';
}

void mostrarMaterias(materia* m, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        cout << "materia: " << m[i].nomMateria << endl;
    }
}
