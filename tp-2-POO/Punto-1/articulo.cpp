#include <iostream>
#include <cstring>
using namespace std;

void cargarCadena(char*, int);

class Articulo{
    private:
        char _codigo[5];
        char _descripcion[30];
        float _precio;
        int _stock;
        bool _estado;

    public:
        Articulo(const char* c = "Cod", const char* d = "Descripcion..", float p = 0.0f, int s = 0, bool status = false){
            strcpy(_codigo, c);
            strcpy(_descripcion, d);
            _precio = p;
            _stock = s;
            _estado = status;
        }
       /* Articulo(const char* d ="Descripcion de producto"){
            strcpy(_descripcion, d);
        }
        */

        ///sets
        void setCodigo(const char* cod){
            strcpy(_codigo, cod);
        }

        void setDescripcion(const char* des){
            strcpy(_descripcion, des);
        }

        void setPrecio(float pres){
            _precio = pres;
        }

        void setStock(int stock){
            _stock = stock;
        }

        void setEstado(bool status){
            _estado = status;
        }

        ///gets

        const char* getCodigo(){
            return _codigo;
        }

        const char* getDescripcion(){
            return _descripcion;
        }

        float getPrecio(){
            return _precio;
        }

        int getStock(){
            return _stock;
        }

        bool getEstado(){
            return _estado;
        }

        ///Funciones de la clase

        void cargar();
        void mostrar();
};

int main(){
    Articulo mema;

    mema.mostrar();

    cout << endl << "----------------------" << endl;

    mema.cargar();

    cout << endl << "----------------------" << endl;

    mema.mostrar();

    cout << endl << "----------------------" << endl;


  return 0;
}

//Funcion Cargar de la clase articulo
void Articulo::cargar(){
    char cod[5], des[30];
    int stock;
    float precio;
    bool status;

    cout << "Ingrese codigo: ";
    cargarCadena(cod, 5);

    cout << "Ingrese descripcion: ";
    cargarCadena(des, 30);

    cout << "Ingrese precio del articulo: ";
    cin >> precio;

    cout << "Ingrese la cantidad de stock del articulo: ";
    cin >> stock;

    setCodigo(cod);
    setDescripcion(des);
    setPrecio(precio);
    setStock(stock);
    setEstado(true);
}

void Articulo::mostrar(){
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Descipcion: " << getDescripcion() << endl;
    cout << "Precio: " << getPrecio() << endl;
    cout << "Cantidad en stock: " << getStock() << endl;

    if(getEstado()){
        cout << "Articulo disponible :)" << endl;
    }
    else{
        cout << "Articulo No disponible :(" << endl;
    }
}



//Cargar las cadenas de caracteres
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);

  for(i=0;i<tam;i++){
      pal[i]=cin.get();

      if(pal[i]=='\n'){
        break;
      }
    }

  pal[i]='\0';
  fflush(stdin);
}

