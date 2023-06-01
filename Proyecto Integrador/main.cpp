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
    Ropa Prenda1("dep1","Liverpool","Playera Tommy Hilfiger",899.99,"M","Hombres");
    dep1.agregaProducto(Prenda1);

    //Crea y agrega un producto para el departamento de Zapatos
    Zapatos Tenis1("dep2","Liverpool","Nike Dunks", 2799.99, 9, "Deportivos");
    dep2.agregaProducto(Tenis1);

    //Crear y agrega un producto para el departamento de Coleccionables
    Coleccionables Figura1("dep3","Liverpool","Rengoku", 399.99,"Funko");
    dep3.agregaProducto(Figura1);

    //Obtener la lista de los departamentos de la tienda
    vector<Departamento> departamentos = Liverpool.getDepartamento();

    //Mostrar los productos de cada departamento
    for (const auto& departamento : departamentos) {
        cout << "Departamento: " << departamento.getNombre() << endl;
        vector<Producto*> productos = departamento.getProductos();
        for (const auto& producto : productos) {
           producto->mostrarInfo();
        }
        cout << endl;
    }

    return 0;
}




