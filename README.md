# Proyecto para Tienda Departamental Pequeña
### Iram Kim Pichardo #A01710231
Este proyecto esta dirigido para gestionar una tienda departamental que funcione para crear un catalogo e inventario de manera digital. De esta manera, se gestionan los productos y los tipos de producto que estan disponibles y mostrar los detalles de cada producto. Ya que por ejemplo, las prendas de ropa llevan tallas pero un muñeco de coleccion no. Se podran agregar objetos (productos) y clasificarlos en uno de los tres tipos de productos que esta tienda ofrece. De esta manera el programa nos puede proporcionar un arreglo de todos los productos en la tienda e informacion detalla de ellos.

## UML
En el diagrama la clase "Tienda" es la principal y se asocian las clases "Departamento" y "Producto", De esta manera la tienda contara con departamentos que contendran los productos de la clase "Producto". Esta clase contendra clases hijas de las cuales se derivaran los tipos de productos que hay, como la "Ropa", "Zapatos" y "Coleccionables". "Producto" es una clase abstracta ya que solo contiene la información mas util de un producto y no se pueden crear instancias directamente de esta.

## Casos en el que el proyecto dejaria de funcionar
Este codigo esta diseñado para un sistema de inventario muy pequeño y no para generar grandes cantidades de tiendas, departamentos y productos. Ya que si se aplicaran a estos casos el codigo inevitablemente colapsaria. Otro caso seria en el cual se tengan que cambiar los datos de los productos constantemente (variables continuas). Ya que se tendrian que reestablecer los vectores y/o arreglos que contienen objetos de cada clase.
