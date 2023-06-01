#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>

using namespace std;

class Departamento;
class Producto;

class Tienda{
    private:
        string nombre_tienda;

    protected:
        vector<Departamento> departamentos;
    
    public:
        Tienda(); //Constructor Default
        Tienda(string nombre_tienda); //Constructor
        string getNombre() const;
        void setNombre(string str_nombre);
        void agregarDepartamento(const Departamento& dep);
        void eliminarDepartamento(const Departamento& dep);
        vector<Departamento> getDepartamento() const;
};


class Departamento : public Tienda{
    private:
        string nombre_dep;
    protected:
        vector<Producto> productos;
    public:
        Departamento(); //Constructor Default
        Departamento(string dep, string nombre_t); //Constructor
        vector<Producto> getProductos() const;
        void agregaProducto(const Producto& producto);
        void eliminarProducto(const string& producto);
};
        
class Producto : public Departamento{
    protected:
        string nombre;
        float precio;
    public:
        Producto(); //Constructor Default
        Producto(const Departamento& departamento,string nombre_t,string nom_prod, float prec); //Constructor
        void setPrecio(float int_precio);
        float getPrecio() const;
        virtual void mostrarInfo() const; //Sobreescritura
};

class Ropa : public Producto{
    protected:
        string talla;
        string seccion;
    public:
        Ropa(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, string tal, string secc); //Constructor
        string getTalla() const;
        void mostrarInfo() const override; //Sobreescritura
};

class Zapatos : public Producto{
    protected:
        float numero_talla;
        string seccion;
    public:
        Zapatos(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, int num_talla, string secc); //Constructor
        float getNum() const;
        void mostrarInfo() const override; //Sobreescritura
};


class Coleccionables : public Producto{
    protected:
        string tipo;
    public:
       Coleccionables(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, string tip); //Constructor
        string getTipo() const;
        void mostrarInfo() const override; //Sobreescritura

};

//Funciones y Metodos

Tienda::Tienda(){
    nombre_tienda = "";
}

Tienda::Tienda(string nombre_t){ 
    nombre_tienda = nombre_t;
};

string Tienda::getNombre() const{
    return nombre_tienda;
};

void Tienda::setNombre(string str_nombre){
    nombre_tienda = str_nombre;
}

void Tienda::agregarDepartamento(const Departamento& dep) {
        departamentos.push_back(dep);
}

void Tienda::eliminarDepartamento(const Departamento& dep) {
    for (int i = 0; i < departamentos.size(); ++i) {
        if (departamentos[i].getNombre() == dep.getNombre()) {
            departamentos.erase(departamentos.begin() + i);
            break;             
        }
    }
}

vector<Departamento> Tienda::getDepartamento() const{
    return departamentos;
}

Departamento::Departamento(){
    nombre_dep = "";
}

Departamento::Departamento(string dep, string nombre_t):Tienda(nombre_t){
    nombre_dep = dep;
}

void Departamento::agregaProducto(const Producto& producto) {
    productos.push_back(producto);
}

void Departamento::eliminarProducto(const string& producto) {
    for (size_t i = 0; i < productos.size(); ++i) {
        if (productos[i].getNombre() == producto) {
            productos.erase(productos.begin() + i);
            break;
        }
    }
}

vector<Producto> Departamento::getProductos() const {
    return productos;
}

Producto::Producto(){
    nombre = "";
    precio = 0.0f;
}

Producto::Producto(Departamento& departamento, string nombre_t, string nom_prod, float prec):Departamento(departamento,nombre_t){
    nombre = nom_prod;
    precio = prec;  
}


void Producto::setPrecio(float int_precio){
    precio = int_precio;
}

float Producto::getPrecio() const{
    return precio;
}

void Producto::mostrarInfo() const{
    cout << "Nombre: "<< nombre <<endl;
    cout << "Precio: "<< precio << endl;
}

Ropa::Ropa(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, string tal, string secc):Producto(departamento,tienda,nom_prod,prec){
    talla = tal;
    seccion = secc;
}

string Ropa::getTalla() const{
    return talla;

}

void Ropa::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Talla: " << talla << endl;
    cout << "Seccion: " << seccion << endl;
}

Zapatos::Zapatos(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, int num_talla, string secc):Producto(departamento,tienda,nom_prod,prec){
    numero_talla = num_talla;
    seccion = secc;
}

void Zapatos::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Talla: " << numero_talla << endl;
    cout << "Sección: " << seccion << endl;
}

float Zapatos::getNum() const{
    return numero_talla;
}

Coleccionables::Coleccionables(const Departamento& departamento, const Tienda& tienda, string nom_prod, float prec, string tip):Producto(departamento,tienda,nom_prod,prec){
    tipo = tip;
}

string Coleccionables::getTipo() const{
    return tipo;
}

void Coleccionables::mostrarInfo() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Tipo: " << tipo << endl;
}

#endif



