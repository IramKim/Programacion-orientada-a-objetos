#include "tienda.h"

int main(){
    //Crea la tienda
    Tienda Liverpool("Liverpool");

    //Crea departamentos
    Departamento dep1("Ropa","Liverpool");
    Departamento dep2("Zapatos","Liverpool");
    Departamento dep3("Coleccionables","Liverpool");

     //Agregar departamentos a la tienda "Liverpool"
    Liverpool.agregarDepartamento(dep1);
    Liverpool.agregarDepartamento(dep2);
    Liverpool.agregarDepartamento(dep3);

    //Crear y agrega un producto para el departamento de Ropa
    Producto producto1("Playera Tommy Hilfiger", 700, "Ropa");
    dep1.agregaProducto(producto1);

    //Crea y agrega un producto para el departamento de Zapatos
    Producto producto2("Nike Dunks", 2800, "Zapatos");
    dep2.agregaProducto(producto2);

    //Crear y agrega un producto para el departamento de Coleccionables
    Producto producto3("Figura Rengoku", 800, "Coleccionables");
    dep3.agregaProducto(producto3);

    //Obtener la lista de los departamentos de la tienda
    vector<Departamento> departamentos = Liverpool.getDepartamento();

    //Mostrar los productos de cada departamento
    for (const auto& departamento : departamentos) {
        cout << "Departamento: " << departamento.getNombre() << endl;
        vector<Producto> productos = departamento.getProductos();
        for (const auto& producto : productos) {
            cout << "Producto: " << producto.getNombre() << ", $" << producto.getPrecio() << endl;
        }
        cout << endl;
    }

    return 0;
}




