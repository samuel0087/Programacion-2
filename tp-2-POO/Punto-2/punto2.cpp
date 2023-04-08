/**
3. Hacer una clase de nombre Fecha con las siguientes propiedades:
Día
Mes
Año
Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.

4. Hacer una clase de nombre Cliente con las siguientes propiedades:
DNI
Fecha de nacimiento
Nombre
Apellido
Email
Teléfono
Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.
Un constructor para asignar valor sólo a la propiedad nombre.
La propiedad fecha de nacimiento debe ser un objeto de la clase Fecha
5. A partir de la clase Cliente del ejercicio anterior desarrollar las siguientes funciones:
a) Cargar un vector de 10 clientes
b) Listar todos los artículos del vector.
c) Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado.
d) A partir de un valor de DNI recibido como parámetro, devolver la posición del objeto que contiene ese DNI. De no encontrarlo devolver -1.
e) Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el DNI. De no encontrar el código la función debe
devolver un objeto Cliente con un valor de -1 en el DNI.
f) Dado una fecha que se recibe como parámetro devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido.
Todas las funciones reciben el vector de Cliente y la cantidad de elementos del vector, además de los parámetros específicos.
Desarrollar un proyecto de CodeBlock con un menú que llame a cada una de las funciones

*/

#include <iostream>
#include <cstring>
using namespace std;

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha(int dia = 0, int mes = 0, int anio = 0){
            _dia = dia;
            _mes = mes;
            _anio = anio;
        }

        void setDia(int dia){
            _dia = dia;
        }

        void setMes(int mes){
            _mes = mes;
        }

        void setAnio(int anio){
            _anio = anio;
        }

        int getDia(){
            return _dia;
        }

        int getMes(){
            return _mes;
        }

        int getAnio(){
            return _anio;
        }

        //declaracion de funciones de clases
        void cargar();
        void mostrar();
};

class Cliente{
    private:
        int _dni;
        Fecha _fechaNaciomiento;
        char _nombres[20];
        char _apellidos[20];
        char _email[30];
        int _telefono;

    public:
        Cliente(int dni = 0,Fecha f; const char* nombre = "NOMBRE", const char* apellido = "APELLIDO", const char* email="EMAIL", int telefono){
            _dni = dni;
            strcpy(_nombres,nombre);
            strcpy(_apellido,apellido);
            strcpy(_email,email);
            _telefono = telefono;

        }
};

int main(){
    Fecha fech;

    fech.cargar();
    fech.mostrar();

    return 0;
}

//funciones de clase
void Fecha::cargar(){
    int dia, mes, anio;

    cout << "Ingrese fecha" << endl;

    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::mostrar(){
    cout << getDia() << "/";
    cout << getMes() << "/";
    cout << getAnio() << endl;
}

