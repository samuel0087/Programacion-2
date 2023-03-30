/*
Las autoridade sde la carrera de TUP estan realizando un analisis de los recursos vitales de las distintas
materias por cada una de las 20 materias de la carrera tiene la siguiente informacion:
-numero de materia (entre 1 y 20)
-nombre
-cantidd de alumnos inscriptos
-cantidad de profesores

ademas por cada ingreso de los estudiantes al aula virtual se registra lo siguiente:
-legajo
-fecha de acceso( dia y mes)
-numero de materia a la que ingreso
-cantidad de horas(real)

La carga se termina con un numero de legajo igual a 0
se requiere lo siguiente:
a ) las materias que no tuvieron acceso de alumnos nunca
b ) la materia que mas cantidad de horas registro de acceso de alumnos
c ) por cada materia y dia de marzo, la cantoidad de acceso de alumnos a las aulas virtuales
*/

#include <iostream>
#include <iomanip>

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
void cargaIngresos(float*, int);
int traerMateria(materia*, int, int);
void materiasSinAcceso(materia*, float*, int);

int main()
{
    const int TAM = 5;
    materia materias[TAM];
    float vCanAcceso[20] = {};
    int opc = 1;

    while(opc)
    {

        system("cls");

        cout << "Menu de inicio" << endl;
        cout << "----------------------------" << endl;

        cout << "1 - CARGAR MATERIAS" << endl;
        cout << "2 - MOSTRAR MATERIAS" << endl;
        cout << "3 - CARGAR INGRESOS" << endl;
        cout << "4 - MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS" << endl;
        cout << "5 - MATERIAS QUE MAS HORAS REISTRARON" << endl;
        cout << "6 - POR CADA MATERIA Y DIA DE MARZO , CANTIDAD DE ACCESO" << endl;
        cout << "0 - SALIR DEL PROGRAMA" << endl;
        cout << endl;

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
            cargaIngresos(vCanAcceso, TAM);
            break;

        case 4:
            materiasSinAcceso(materias, vCanAcceso, TAM);
            break;

        case 5:
            break;

        case 6:
            break;

        case 0:
            break;
        }

        system("pause");
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

        cout << "Ingrese cantidad de alumnos: ";
        cin >> materias[i].cantAlumnos;

        cout << "Ingrese cantidad de profesores: ";
        cin >> materias[i].cantProfesores;
        cout << endl;

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
    cout << left;
    cout << "---------------------------------------------------" << endl;
    cout << setw(4) << "NUM";
    cout << "|";
    cout << setw(30) << "MATERIA";
    cout << "|";
    cout << setw(7)  << "ALUMNOS";
    cout << "|";
    cout << setw(7) << "PROFES";
    cout << "|";
    cout << endl;
    cout << "---------------------------------------------------" << endl;

    for(int i = 0; i < tam; i++)
    {
    cout << right;
       cout << setw(4) << m[i].numMateria;
       cout << "|";
       cout << left;
       cout << setw(30) << m[i].nomMateria;
       cout << "|";
       cout << setw(7) << m[i].cantAlumnos;
       cout << "|";
       cout << setw(7) << m[i].cantProfesores;
       cout << "|";
       cout << endl;
       cout << "---------------------------------------------------" << endl;

    }
}

void cargaIngresos(float* v, int tam){
    int numMateria, numLegajo, dia, mes;
    float canHoras;

    cout << "Ingrese num de legajo del estudiante: ";
    cin >> numLegajo;

    while(numLegajo != 0)
    {
        cout << "Ingrese dia de acceso: ";
        cin >> dia;

        cout << "Ingrese mes de acceso: ";
        cin >> mes;

        cout << "ingrese numero de materia: ";
        cin >> numMateria;

        cout << "Ingrese cantidad de Horas que ingreso: ";
        cin >> canHoras;
        cout << endl;

        v[numMateria-1] += canHoras;


        cout << "Ingrese num de legajo del estudiante: ";
        cin >> numLegajo;
    }
}

void materiasSinAcceso(materia* mat, float* va, int tam)
{
    int index;
    cout << left;
    cout << "|"<< setw(40) << "MATERIAS SIN ACCESO DE ALUMNOS " << "|" <<endl;
    cout << "|" << setw(40) << "----------------------------------------" <<  "|" <<endl;

    for(int i = 0; i < tam; i++)
    {
        if(va[i] == 0)
        {
            index = traerMateria(mat, i+1, tam);
            cout << "|"<< setw(40) << mat[index].nomMateria << "|" <<endl;
            cout << "|"<< setw(40)  << "----------------------------------------" << "|"<< endl;
        }
    }

}

int traerMateria(materia* mat, int num, int tam)
{
    int index;

    for(int i = 0; i < tam; i++)
    {
        if(mat[i].numMateria == num)
        {
            index = i;
        }
    }

    return index;
}
