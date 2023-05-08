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
        std::string toString();
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


        void setDni(int dni){
            _dni = dni;
        }

        void setFecha(Fecha f){
            _fechaNacimiento.setDia(f.getDia());
            _fechaNacimiento.setMes(f.getMes());
            _fechaNacimiento.setAnio(f.getAnio());
        }

        void setNombres(const char* nombres){
            strcpy(_nombres, nombres);

        }

        void setApellidos(const char* apellidos){
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

        Fecha getFechaNacimiento(){
            return _fechaNacimiento;
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



int cargarArchivoCliente();
bool mostrarArchivoCliente();
Cliente buscarClienteDni( int);

int main(void){
    int opc, dni;
    Cliente cAux = Cliente();



    do{

    system("cls");
    cout << "---------------------------" << endl;
    cout << "          ARCHIVOS         " << endl;
    cout << "---------------------------" << endl;

    cout << "1 - AGREGAR REGISTRO DE CLIENTE "<< endl;
    cout << "2 - MOSTRAR REGISTRO DE CLIENTES "<< endl;
    cout << "3 - BUSCAR REGISTRO MEDIANTE DNI "<< endl;
    cout << "0 - SALIR";

    cout << endl << "INGRESE UNA OPCION: ";
    cin >> opc;

    system("cls");



    switch(opc){
        case 1:
            if(cargarArchivoCliente() != 1){
                cout << "NO SE PUDO CREAR EL ARCHIVO O LEER " << endl;
            }
            else{
                cout << "REGISTRO AGREGADO" << endl;
            }

            break;

        case 2:
            mostrarArchivoCliente();

            break;

        case 3:

            cout << "Ingrese un numero de DNI: ";
            cin >> dni;

            cAux = buscarClienteDni(dni);

            if(cAux.getDni() != 0){
                cAux.mostrar();
            }
            else{
                cout << "Cliente no encontrado" << endl;
            }

            break;

        case 0:
            return 0;
            break;
    }

    system("pause");

    }while(opc != 0);

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
}

void Cliente::mostrar(){

        cout << getDni() << endl;
        cout << getFechaNacimiento().toString() << endl;
        cout << getNombre() << endl;
        cout << getApellidos() << endl;
        cout << getEmail() << endl;
        cout << getTelefono() << endl;
        cout << "-----------------------------------" << endl;
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

int cargarArchivoCliente(){
    Cliente reg;
    FILE* pCliente;

    pCliente = fopen("cliente.txt", "ab");

    if(pCliente == NULL){
        cout << "No se pudo crear o leer el archivo" << endl;
        return -1;
    }

    reg.cargar();
    int valor = fwrite(&reg, sizeof reg, 1, pCliente);
    fclose(pCliente);

    return valor;

}

bool mostrarArchivoCliente(){
    Cliente reg;
    FILE* pCliente;

    pCliente = fopen("cliente.txt", "rb");

    if(pCliente == NULL){
        cout << "No se pudo crear o leer el archivo" << endl;
        return false;
    }

    while( fread(&reg, sizeof reg, 1, pCliente) == 1){
        reg.mostrar();
        cout << endl;
    }

    fclose(pCliente);

    return true;
}


Cliente buscarClienteDni(int dni){
    Cliente reg;
    FILE* pCliente;

    pCliente = fopen("cliente.txt", "rb");

    if(pCliente == NULL){
        return false;
    }

     while( fread(&reg, sizeof reg, 1, pCliente) == 1){
        if(reg.getDni() == dni){
            fclose(pCliente);
            return reg;
        }
    }

    fclose(pCliente);

    return Cliente();
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
