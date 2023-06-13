#include "tienda.h"

int main(){

//Crear una Tienda
Tienda Liverpool("Liverpool");

//Crear Departamentos

Departamento* Dep1 = new Departamento("Prendas","Liverpool");
Departamento* Dep2= new Departamento("Zapatos","Liverpool");
Departamento* Dep3 = new Departamento("Juguetes","Liverpool");

//Agrega Departamentos a la Tienda 
Liverpool.agregarDepartamento(Dep1);
Liverpool.agregarDepartamento(Dep2);
Liverpool.agregarDepartamento(Dep3);

//Crea Productos de cada Categoria

Producto* Pl1 = new Ropa("Dep1",Liverpool.getNombre(),"Playera Tommy Hilfiger",699.99f,"L","Hombres");
Producto* Chm1 = new Ropa("Dep1",Liverpool.getNombre(),"Sudadera Adidas",999.99f,"M","Ninos");
Producto* Pant1 = new Ropa("Dep1",Liverpool.getNombre(),"Jeans Levis 501",1299.99f,"30/32","Hombres");

Producto* Ten1 = new Zapatos("Dep2",Liverpool.getNombre(),"Tenis Nike",1299.99f,3,"Mujeres");
Producto* Botas1= new Zapatos("Dep2",Liverpool.getNombre(),"Botas Timberland",1099.99f,10,"Hombres");

Producto* Funk1 = new Coleccionables("Dep3",Liverpool.getNombre(),"Funko Pop Rengoku",399.99f,"Funko");

//Agregar Productos a su respectivo Departamento
Dep1->agregaProducto(Pl1);
Dep1->agregaProducto(Chm1);
Dep1->agregaProducto(Pant1);

Dep2->agregaProducto(Ten1);
Dep2->agregaProducto(Botas1);

Dep3->agregaProducto(Funk1);

//Imprime todos los productos del Dep1
Dep1->muestraProductos();

//Imprime todos los productos del Dep2
Dep2->muestraProductos();

//Imprime la información de productos (Funk1 y Botas1)
Funk1->mostrarInfo();
Botas1->mostrarInfo();

//Liberar memoria

delete Pl1;
delete Chm1;
delete Pant1;
delete Ten1;
delete Botas1;
delete Funk1;

}


