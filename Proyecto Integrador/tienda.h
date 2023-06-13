#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Departamento;
class Producto;

class Tienda{ //Clase Base
    private:
        string nombre_tienda;

    protected:
        Departamento *departamentos[20];
        int indice1 = 0;
    
    public:
        Tienda(); //Constructor Default
        Tienda(string nombre_tienda); //Constructor
        string getNombre();
        void setNombre(string str_nombre);
        void agregarDepartamento(Departamento*);
};


class Departamento : public Tienda{
    private:
        string nombre_dep;
    protected:
        Producto *productos[100];
        int indice2 = 0;
    public:
        Departamento(); //Constructor Default
        Departamento(string dep, string nombre_t); //Constructor
        void agregaProducto(Producto*);
        void muestraProductos();
        
};
        
class Producto : public Departamento{
    protected:
        string nombre;
        float precio;
    public:
        Producto() = delete; //Se elimina el Constructor Default para evitar crear objetos de esta clase abstr.
        Producto(string dep,string nombre_t,string nom_prod, float prec); //Constructor
        virtual string getProducto() const;
        virtual float getPrecio() const; 
        virtual void mostrarInfo() const = 0; //Sobreescritura y Delaracion de clase abstracta
};

class Ropa : public Producto{
    protected:
        string talla;
        string seccion;
    public:
        Ropa(string dep, string nombre_t, string nom_prod, float prec, string tal, string secc); //Constructor
        //Los getters posteriores declarados no se utilizan en el programa,
        // son solo por si el usuario utilizando el codigo lo requiere 
        string getTalla();
        void mostrarInfo() const override; //Sobreescritura
};

class Zapatos : public Producto{
    protected:
        float numero_talla;
        string seccion;
    public:
        Zapatos(string dep, string nombre_t, string nom_prod, float prec, int num_talla, string secc); //Constructor
        float getNum();
        void mostrarInfo() const override; //Sobreescritura
};


class Coleccionables : public Producto{
    protected:
        string tipo;
    public:
       Coleccionables(string dep,string nombre_t, string nom_prod, float prec, string tip); //Constructor
        string getTipo();
        void mostrarInfo() const override; //Sobreescritura

};

//Funciones y Metodos

Tienda::Tienda(){
    nombre_tienda = "";
}

Tienda::Tienda(string nombre_t){ 
    nombre_tienda = nombre_t;
};

string Tienda::getNombre(){
    return nombre_tienda;
};

void Tienda::setNombre(string str_nombre){
    nombre_tienda = str_nombre;
}

void Tienda::agregarDepartamento(Departamento* dep) {
        if (indice1 < 20) {
        departamentos[indice1] = dep;
        indice1 ++;
        }
        else {
        cout << "Se alcanzo el limite maximo de departamentos" <<endl;
        }
}


Departamento::Departamento(){
    nombre_dep = "";
}

Departamento::Departamento(string dep, string nombre_t):Tienda(nombre_t){
    nombre_dep = dep;
}

void Departamento::agregaProducto(Producto* prod) {
    if (indice2 < 100) {
    productos[indice2] = prod;
    indice2 ++;
    }
    else {
        cout << " Se alcanzo el limite maximo de productos" <<endl;
    }
}

void Departamento::muestraProductos(){
    for(int i = 0; i < indice2; i++){
    string NombreProd = productos[i]->getProducto();
    float PrecProd = productos[i]->getPrecio();
    cout << NombreProd << ": $" << PrecProd << endl;
    }
cout << endl;
}

Producto::Producto(string dep, string nombre_t, string nom_prod, float prec):Departamento(dep,nombre_t){
    nombre = nom_prod;
    precio = prec;  
}

float Producto::getPrecio() const{
    return precio;
}

string Producto::getProducto() const{
    return nombre;
}

Ropa::Ropa(string dep,string nombre_t, string nom_prod, float prec, string tal, string secc):Producto(dep,nombre_t,nom_prod,prec){
    talla = tal;
    seccion = secc;
}

string Ropa::getTalla() {
    return talla;

}

void Ropa::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Talla: " << talla << endl;
    cout << "Seccion: " << seccion << endl;
    cout << endl;
}

Zapatos::Zapatos(const string dep,string nombre_t, string nom_prod, float prec, int num_talla, string secc):Producto(dep,nombre_t,nom_prod,prec){
    numero_talla = num_talla;
    seccion = secc;
}

void Zapatos::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Talla: " << numero_talla << endl;
    cout << "Seccion: " << seccion << endl;
    cout << endl;
}

float Zapatos::getNum() {
    return numero_talla;
}

Coleccionables::Coleccionables(string dep,string nombre_t, string nom_prod, float prec, string tip):Producto(dep,nombre_t,nom_prod,prec){
    tipo = tip;
}

string Coleccionables::getTipo() {
    return tipo;
}

void Coleccionables::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << endl;
}

#endif




