/**
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

void cargarCadena(char*, int);

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

class Cliente : public Fecha{
    private:
        int _dni;
        Fecha _fechaNacimiento;
        char _nombres[20];
        char _apellidos[20];
        char _email[30];
        int _telefono;

    public:
        Cliente(int dni = 0,const char* nombre = "NOMBRE", const char* apellido = "APELLIDO",const char* email="EMAIL", int telefono = 0){
            _dni = dni;
            strcpy(_nombres,nombre);
            strcpy(_apellidos,apellido);
            strcpy(_email,email);
            _telefono = telefono;
        }

        void setDni(int dni){
            _dni = dni;
        }

        setFecha(Fecha f){
            _fechaNacimiento.setDia(f.getDia());
            _fechaNacimiento.setMes(f.getMes());
            _fechaNacimiento.setAnio(f.getAnio());
        }

        void setNombres(const char* nombres){
            strcpy(_nombres, nombres);

        }

        void setAppellidos(const char* apellidos){
            strcpy(_apellidos, apellidos);
        }

        void setEmail(const char* email){
            strcpy(_email, email);
        }

        void setTelefono(int tel){
            _telefono = tel;
        }

        //getters
        int getDni(){
            return _dni;
        }

        const char* getNombre(){
            return _nombres;
        }

        const char* getApellidos(){
            return _apellidos;
        }

        const char* getEmail(){
            return _email;
        }

        int getTelefono(){
            return _telefono;
        }



        void cargar();
        void mostrar();

};


void cargarClientes(Cliente*, int );
void listarClientes(Cliente*, int );
void listarDniMayor(Cliente*, int, int);
int buscarPosicionCliente(Cliente*, int, int);
Cliente buscarCliente(Cliente*, int, int);
int cantidadFechasAnteriores(Cliente*, int, Fecha);


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

void Cliente::cargar(){
    Fecha f;
    int dni, tel;
    char vN[20], vA[20], vE[30];

    cout << "Ingrese DNI: ";
    cin >> dni;

    f.cargar();

    cout << "Ingrese nombre: ";
    cargarCadena(vN, 20);

    cout << "Ingrese apellidos: ";
    cargarCadena(vA, 20);

    cout << "Ingrese email: ";
    cargarCadena(vE, 30);

    cout << "Ingrese telefono: ";
    cin >> tel;
}

void Cliente::mostrar(){
}


//funciones generales
void cargarClientes(Cliente* clientes, int tam){
    cout << "Carga de datos de los clientes " << endl;

    for(int i = 0; i < tam; i++){
        cout << "-------------------" << endl;
        clientes[i].cargar();
        cout << endl;
    }
}

void listarClientes(Cliente* clientes, int tam){
    cout << "Listado de clientes " << endl;

    for(int i = 0; i < tam; i++){
        cout << "-------------------" << endl;
        clientes[i].mostrar();
        cout << endl;
    }
}

///Busca DNI mayores al DNI que se pasa como parametro
void listarDniMayor(Cliente* clientes, int tam, int dni){
    cout << "Lista de clientes con DNI mayores al ingresado";

    for(int i = 0; i < tam; i++){
        cout << "-------------------" << endl;

        if(clientes[i].getDni() > dni){
            clientes[i].mostrar();
        }

        cout << endl;
    }
}

int buscarPosicionCliente(Cliente* clientes, int tam, int dni){

    for(int i = 0; i < tam; i++){
        if(clientes[i].getDni() == dni){
            return (i+1);
        }
    }

    return -1;
}

Cliente buscarCliente(Cliente* clientes, int tam, int dni){

    for(int i = 0; i < tam; i++){
        if(clientes[i].getDni() == dni){
            return clientes[i];
        }
    }

    Cliente result;
    result.setDni(-1);

    return result;
}

int cantidadFechasAnteriores(Cliente* clientes, int tam, Fecha fechaN){
    int cont = 0;

    for(int i = 0; i < tam; i++){

        if(clientes[i].getAnio() < fechaN.getAnio()){
           cont++;
        }
        else{
             if(clientes[i].getAnio() == fechaN.getAnio() && clientes[i].getMes() < fechaN.getMes()){
                cont++;
             }
             else{
                if(clientes[i].getAnio() == fechaN.getAnio() && clientes[i].getMes() == fechaN.getMes() && clientes[i].getDia() <= fechaN.getDia()){
                    cont++;
                }
             }
        }
    }

    return cont;
}


void cargarCadena(char *pal, int tam){
  int i;

  fflush(stdin);

  for(i=0;i<tam;i++){
      pal[i]=cin.get();

	  if(pal[i]=='\n') break;

	  }

  pal[i]='\0';
  fflush(stdin);
}

