#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void cargarCadena(char*, int);

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha(int dia, int mes, int anio);
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        int getDia();
        int getMes();
        int getAnio();

        //declaracion de funciones de clases
        void cargar();
        void mostrar();
        std::string toString();
};


Fecha::Fecha(int dia = 0, int mes = 0, int anio = 0){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
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
    cout << getMes() << "/";
    cout << getAnio() << endl;
    cout << getDia() << "/";
}

std::string Fecha::toString() {
	std::string DD = std::to_string(_dia);
	std::string MM = std::to_string(_mes);
	std::string YYYY = std::to_string(_anio);

	if (_dia < 10) {
		DD = "0" + std::to_string(_dia);
	}

	if (_mes < 10) {
		MM = "0" + std::to_string(_mes);
	}

	std::string fech =  DD + "/" + MM + "/" + YYYY;

	return fech;
}


class Cliente : public Fecha{
    private:
        int _dni;
        Fecha _fechaNacimiento;
        char _nombres[20];
        char _apellidos[20];
        char _email[30];
        int _telefono;
        bool _estado;

    public:

        Cliente(int dni,const char* nombre, const char* apellido ,const char* email, int telefono);
        void setDni(int dni);
        void setFecha(Fecha f);
        void setNombres(const char* nombres);
        void setApellidos(const char* apellidos);
        void setEmail(const char* email);
        void setTelefono(int tel);
        void setEstado(bool status);

        //getters
        int getDni();
        const char* getNombre();
        const char* getApellidos();
        const char* getEmail();
        int getTelefono();
        Fecha getFechaNacimiento();
        bool getEstado();

        void cargar();
        void mostrar();

};

Cliente::Cliente(int dni = 0,const char* nombre = "NOMBRE", const char* apellido = "APELLIDO",const char* email="EMAIL", int telefono = 0){

    if(dni != 0){
          _dni = dni;
        strcpy(_nombres,nombre);
        strcpy(_apellidos,apellido);
        strcpy(_email,email);
        _telefono = telefono;
    }
    else{
        _dni = 0;
        strcpy(_nombres,"");
        strcpy(_apellidos, "");
        strcpy(_email,"");
        _telefono = 0;
    }
}


void Cliente::setDni(int dni){
    _dni = dni;
}

void Cliente::setFecha(Fecha f){
    _fechaNacimiento.setDia(f.getDia());
    _fechaNacimiento.setMes(f.getMes());
    _fechaNacimiento.setAnio(f.getAnio());
}

void Cliente::setNombres(const char* nombres){
    strcpy(_nombres, nombres);

}

void Cliente::setApellidos(const char* apellidos){
    strcpy(_apellidos, apellidos);
}

void Cliente::setEmail(const char* email){
    strcpy(_email, email);
}

void Cliente::setTelefono(int tel){
    _telefono = tel;
}

void Cliente::setEstado(bool status){
    _estado = status;
}

//getters
int Cliente::getDni(){
    return _dni;
}

const char* Cliente::getNombre(){
    return _nombres;
}

const char* Cliente::getApellidos(){
    return _apellidos;
}

const char* Cliente::getEmail(){
    return _email;
}

int Cliente::getTelefono(){
    return _telefono;
}

Fecha Cliente::getFechaNacimiento(){
    return _fechaNacimiento;
}

bool Cliente::getEstado(){
    return _estado;
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

    setDni(dni);
    setFecha(f);
    setNombres(vN);
    setApellidos(vA);
    setEmail(vE);
    setTelefono(tel);
    setEstado(true);
}

void Cliente::mostrar(){
    if(getEstado()){
        cout << getDni() << endl;
        cout << getFechaNacimiento().toString() << endl;
        cout << getNombre() << endl;
        cout << getApellidos() << endl;
        cout << getEmail() << endl;
        cout << getTelefono() << endl;
        cout << "-----------------------------------" << endl;
    }

}


//CLASE ARCHIVOS DE CLIENTES: PARA MANEJAR EL ARCHIVO DE CLIENTES
class ArchivoCliente{
    private:
        char _nombre[50];

    public:
        ArchivoCliente(const char* nom);

        void setNombre(const char* nom);

        int altaRegistro();         //ALTA
        int bajaRegistro();         //BAJA: LOGICA O PARCIAL
        bool modificarEmail();
        bool eliminarRegistro();
        int sobrescribirRegistro(Cliente reg, int pos);    //MODIFICACION: CAMBIA EL VALOR DE UNO O VARIOS CAMPOS
        bool listarRegistros();     //LISTADO

        int buscarDni(int dni);
        void buscarPorFecha(Fecha aux);
        Cliente leerRegistro(int pos);

        void vaciarArchivo();

};

ArchivoCliente::ArchivoCliente(const char* nom){
    strcpy(_nombre, nom);
}

void ArchivoCliente::setNombre(const char* nom){
    strcpy(_nombre, nom);
}

int ArchivoCliente::altaRegistro(){
    int valor = 0;
    Cliente reg;
    FILE* pCliente;

    pCliente = fopen(_nombre, "ab");

    if(pCliente == NULL){
        cout << "No se pudo crear o leer el archivo" << endl;
        return valor;
    }

    reg.cargar();

    if(buscarDni(reg.getDni()) == -2){
        valor = fwrite(&reg, sizeof reg, 1, pCliente);
    }
    else{
        cout << "DNI ya existente, por favor ingrese uno nuevo ";
    }

    fclose(pCliente);

    return valor;
}

bool ArchivoCliente::eliminarRegistro(){
    int dni;

    //Buscar
    cout << "Ingrese el DNI de cliente a eliminar: ";
    cin >> dni;

    int pos = buscarDni(dni);

    if(pos == -1) {
        cout << "No hay ningun cliente con este DNI" << endl;
        return false;
    }

    //leer
    Cliente reg = leerRegistro(pos);

    //modificar
    reg.setEstado(false);

    //sobreescribir
    sobrescribirRegistro(reg, pos);

    return true;

}

bool ArchivoCliente::modificarEmail(){
    int dni;

    //Buscar
    cout << "Ingrese el DNI de cliente a eliminar: ";
    cin >> dni;

    int pos = buscarDni(dni);

    if(pos == -1) {
        cout << "No hay ningun cliente con este DNI" << endl;
        return false;
    }

    //leer
    Cliente reg = leerRegistro(pos);
    reg.mostrar();
    cout << endl;

    //modificar
    char email[30];
    cout << "ngrese email nuevo: ";
    reg.setEmail(email);
    cargarCadena(email, 30);
    reg.setEmail(email);

    //sobreescribir
    int result = sobrescribirRegistro(reg, pos);

    if(result == 1){
        cout << "Se modifico el archivo correctamente" << endl;
    }
    else{
        cout << "No se pudo modificar el registro" << endl;
    }
    return true;

}

int ArchivoCliente::sobrescribirRegistro(Cliente reg, int pos){
    FILE* pCliente;
    pCliente = fopen(_nombre, "rb+");

    if(pCliente == NULL){
        cout << "No se pudo leer el registro" << endl;
        return -1;
    }

    fseek(pCliente, pos * sizeof(Cliente), 0);
    int result = fwrite(&reg, sizeof(Cliente), 1, pCliente);
    fclose(pCliente);

    return 1;
}

bool ArchivoCliente::listarRegistros(){
    Cliente reg;
    FILE* pCliente;

    pCliente = fopen(_nombre, "rb");

    if(pCliente == NULL){
        return false;
    }

    bool valor, vacio = true;
    do{
        valor =  fread(&reg, sizeof reg, 1, pCliente);

        if(valor){
            reg.mostrar();
            cout << endl;
            vacio = false;
        }
        else{
            if(vacio){
                cout << "No hay reegistros para mostrar" << endl;
            }
        }

    }while(valor == 1);



    fclose(pCliente);

    return true;
}

int ArchivoCliente::buscarDni(int dni){
    Cliente reg;
    FILE* pCliente;
    int pos = 0;

    pCliente = fopen(_nombre, "rb");

    if(pCliente == NULL){
        return -1;
    }

     while( fread(&reg, sizeof reg, 1, pCliente) == 1){
        if(reg.getDni() == dni){
            fclose(pCliente);
            return pos;
        }
        pos ++;
    }

    fclose(pCliente);

    return -2;
}

Cliente ArchivoCliente::leerRegistro(int posC){
    Cliente reg;
    FILE* pCliente;
    int pos = 0;

    pCliente = fopen(_nombre, "rb");

    if(pCliente == NULL){
        return reg;
    }

    fseek(pCliente, sizeof reg * posC, SEEK_SET); // fseek(puntero FILE sobre el que se ario el archivo, cantidad de byte a desplazarse, de donde comienza a desplazarse);

    //desde 0, SEEK_SET, el desplazamiento va desde el principio del archivo
    //desde 1, SEEK_CUT, el desplazamiento va desdedonde se encuetra el indicador del  puntero file
    //desde 2, SEEK_END, el desplazamiento va desde el final del archivo

    fread(&reg, sizeof reg, 1, pCliente);
    fclose(pCliente);

    return reg;
}

void ArchivoCliente::buscarPorFecha(Fecha aux){
    Cliente reg;
    FILE* pCliente;
    pCliente = fopen(_nombre, "rb");

    if(pCliente == NULL){
        cout << "No se puede abrir el archivo." << endl;
        return;
    }

    while(fread(&reg, sizeof(Cliente), 1, pCliente) != 0){
        if(reg.getFechaNacimiento().toString() == aux.toString()){
            reg.mostrar();
        }
    }

    fclose(pCliente);
}


void ArchivoCliente::vaciarArchivo(){
    FILE* pCliente;
    pCliente = fopen(_nombre, "wb");

    if(pCliente == NULL){
        cout << "No se puede leer el archivo" << endl;
        return;
    }

    fclose(pCliente);
}


void cargarClientes(Cliente*, int);
void listarClientes(Cliente*, int);
void listarDniMayor(Cliente*, int, int);
int buscarPosicionCliente(Cliente*, int, int);
Cliente buscarCliente(Cliente*, int, int);
int cantidadFechasAnteriores(Cliente*, int, Fecha);



int main(void){
    int opc, dni, pos;
    Cliente cAux;
    Fecha fechaAux;
    ArchivoCliente obj("cliente.dat");

    do{

    system("cls");
    cout << "---------------------------" << endl;
    cout << "          ARCHIVOS         " << endl;
    cout << "---------------------------" << endl;

    cout << "1 - AGREGAR REGISTRO DE CLIENTE "<< endl;
    cout << "2 - MOSTRAR REGISTRO DE CLIENTES "<< endl;
    cout << "3 - BUSCAR REGISTRO MEDIANTE DNI "<< endl;
    cout << "4 - BUSCAR REGISTRO MEDIANTE FECHA NACIMIENTO "<< endl;
    cout << "5 - ELIMINAR CLIENTE DEL ARCHIVO "<< endl;
    cout << "6 - MODIFICAR EMAIL "<< endl;

    cout << "0 - SALIR";

    cout << endl << "INGRESE UNA OPCION: ";
    cin >> opc;

    system("cls");

    switch(opc){
        case 1:
            if(obj.altaRegistro()){
                cout << "REGISTRO AGREGADO" << endl;
            }

            break;

        case 2:
           obj.listarRegistros();

            break;

        case 3:

            cout << "Ingrese un numero de DNI: ";
            cin >> dni;

            pos = obj.buscarDni(dni);
            cAux = obj.leerRegistro(pos);

            if(cAux.getDni() != 0){
                cAux.mostrar();
            }
            else{
                cout << "Cliente no encontrado" << endl;
            }

            break;

        case 4:
            cout << "Ingrese fecha nacimiento: ";
            fechaAux.cargar();

            obj.buscarPorFecha(fechaAux);
            break;

        case 5:

            obj.eliminarRegistro();
            break;

        case 6:
            obj.modificarEmail();
            break;

        case 0:
            return 0;
            break;
    }

    system("pause");

    }while(opc != 0);

  return 0;

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
