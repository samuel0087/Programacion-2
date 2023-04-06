#include <iostream>
#include <cstring>
using namespace std;


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

void cargarCadena(char*, int);
void cargarVector(Articulo*, int);
void listarVector(Articulo*, int);
void listarMayores(Articulo*,float, int);
char devuelveIndex(Articulo*, char*, int);
Articulo devuelveArticulo(Articulo*, char*, int);
int devuelveCantMenores(Articulo*, int, int);
void cambiarPrecios(Articulo*, float, int);

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

//funciones generales
void cargarVector(Articulo* v, int tam){
    for(int i = 0; i < tam; i++){
        v[i].cargar();
        cout << "-----------------" << endl;
    }
}

void listarVector(Articulo* v, int tam){
    for(int i = 0; i < tam; i++){
        v[i].mostrar();
        cout << "-----------------" << endl;
    }
}

void listarMayores(Articulo* v, float num, int tam) {
    for(int i = 0; i < tam; i++){
        if(v[i].getPrecio() > num){
            v[i].mostrar();
            cout << "-----------------" << endl;
        }
    }
}

char devuelveIndex(Articulo* vA, char* vC,int tam){
    int index = -1;

    for(int i = 0; i < tam; i++){
        if(strcmp(vA[i].getCodigo(), vC) == 0){
            int index = i;
        }
    }

    return index;
}

Articulo devuelveArticulo(Articulo* vA, char* cod, int tam){
    for(int i = 0; i < tam; i++){
        if(strcmp(vA[i].getCodigo(), cod) == 0){
            return vA[i];
        }
    }
    Articulo art;
    art.setStock(-1);

    return   art;
}

int devuelveCantMenores(Articulo* vA,int num, int tam){
    int cont = 0;

    for(int i = 0; i < tam; i++){
        if(vA[i].getStock() < num){
            cont++;
        }
    }

    return cont;
}

void cambiarPrecios(Articulo* vA, float aumento, int tam){
    aumento = (aumento + 100.0f) / 100.0f;

    for(int i = 0; i < tam; i ++){
        vA[i].setPrecio((vA[i].getPrecio() * aumento));
    }
}
