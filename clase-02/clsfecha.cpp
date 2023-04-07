# include<iostream>
# include<cstdlib>
# include <cstring>

using namespace std;

void cargarCadena(char *pal, int tam);


class Fecha
{
    private:///todo lo que se defina acá sólo va a ser accesible dentro de la clase
        int dia, mes, anio;
    public:
        ///constructor tiene el mismo nombre que la clase; no devuelve NADA; se ejecuta de manera automática cuando el objeto nace
        Fecha(int dia=0, int mes=0, int anio=0)
        {
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }


        void Cargar() ///método o función de la clase
        {
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar() ///método o función de la clase
        {
            cout <<dia<< "/";
            cout <<mes<< "/";
            cout <<anio<<endl<<endl;
        }
        ///sets
        void setDia(int x)
        {
            if(x>0 && x<32)
            {
                dia=x;
            }
        }

        void setMes(int x)
        {
            if(x>0 && x<13)
            {
                mes=x;
            }
        }

        void setAnio(int x)
        {
            anio=x;
        }
        ///gets
        int getDia()
        {
            return dia;
        }
        int getMes()
        {
            return mes;
        }
        int getAnio()
        {
            return anio;
        }

};

class Cliente
{
    private:
        int _dni;
        Fecha _fechaNacimiento;
        char _nombre[21];
        char _apellido[11];
        int _telefono;
        char _email[21];

    public:
        Cliente(int dni = 0, const char* nom = "Nombre", const char* ape ="Apellido", int tel = 0,const char* email = "EMAIL")
        {
            _dni = dni;
            strcpy(_nombre, nom);
            strcpy(_apellido, ape);
            _telefono = tel;
            strcpy(_email, email);
        }


        void setDni(int dni)
        {
            _dni = dni;
        }

        void setNombre(const char* nombre)
        {
            strcpy(_nombre, nombre);
        }

        void setApellido(const char* ape)
        {
            strcpy(_apellido, ape);
        }

        void setTelefono(int telefono)
        {
            _telefono = telefono;
        }

        void setEmail(const char* email)
        {
            strcpy(_email, email);
        }


        //gets

        int getDni()
        {
            return _dni;
        }


        const char *getNombre()
        {
            return _nombre;
        }

        const char *getApellido()
        {
            return _apellido;
        }

        int getTelefono()
        {
            return _telefono;
        }

        const char *getEmail()
        {
            return _email;
        }


        void cargar();

        void mostrar();

};


void Cliente::cargar()
{
    int dni, telefono;
    char nombre[21], apellido[21], mail[21];
    cout << "Ingrese DNI: ";
    cin >> dni;

    cout << "Ingrese nombre: ";
    cargarCadena(nombre, 20);

    cout << "Ingrese apellido";
    cargarCadena(apellido, 20);

    cout << "Ingrese Telefono: ";
    cin >> telefono;

    cout << "Ingrese el email: ";
    cargarCadena(mail, 20);

    cout << "Fecha de nacimiento: ";
    _fechaNacimiento.Cargar();



    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(mail);


}

void Cliente::mostrar()
{
    cout << "DNI: ";
    cout << getDni() << endl;

    cout << "nombre: ";
    cout << getNombre() << endl;

    cout << "apellido: ";
    cout << getApellido() << endl;

    cout << "Telefono: ";
    cout << getTelefono() << endl;

    cout << "mail: ";
    cout << getEmail() << endl;

    cout << "Fecha de nacimiento: ";
    _fechaNacimiento.Mostrar();

}





int main()
{
    Cliente obj;

    obj.cargar();

    obj.mostrar();

    return 0;
}


void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
