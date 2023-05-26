#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>

using namespace std;

class Departamento;
class Producto;

class Tienda{
    private:
        string nombre;

    protected:
        vector<Departamento> departamentos;
    
    public:
        Tienda(string nombre); //Constructor
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
        Departamento(string dep, string nombre); //Constructor
        vector<Producto> getProductos() const;
        void agregaProducto(const Producto& producto);
        void eliminarProducto(const string& producto);
};
        
class Producto : public Departamento{
    private:
        string nombre;
        float precio;
    public:
        Producto(string nom_prod, float precio, string dep); //Constructor
        void setPrecio(float int_precio);
        float getPrecio() const;
};

//Funciones y Metodos

Tienda::Tienda(string str_nombre){ 
    nombre = str_nombre;
};

string Tienda::getNombre() const{
    return nombre;
};

void Tienda::setNombre(string str_nombre){
    nombre = str_nombre;
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

Departamento::Departamento(string nom, string nombre):Tienda(nombre){
    nombre_dep = nom;
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

Producto::Producto(string nom_prod, float precio, string dep):Departamento(dep,nombre){
    nombre = nom_prod;  
}


void Producto::setPrecio(float int_precio){
    precio = int_precio;
}

float Producto::getPrecio() const{
    return precio;
}

#endif



