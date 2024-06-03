#include <stdio.h>
#include "lectura.h"
#include "operaciones.h"

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];
int numProductos = 0;

void copiarCadena(char* destino, const char* origen) {
    while (*origen) {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

void ingresarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        printf("Ingresar nombre del producto: ");
        scanf(" %[^\n]", nombres[numProductos]);
        
        cantidades[numProductos] = leerEnteroPositivo("Ingresar cantidad: ");
        precios[numProductos] = leerFlotantePositivo("Ingresar precio: ");
        
        numProductos++;
    } else {
        printf("Inventario lleno.\n");
    }
}

void editarProducto() {
    int index = leerEnteroPositivo("Ingresar indice del producto a editar: ");
    if (index > 0 && index <= numProductos) {
        index--;
        printf("Editar nombre del producto (anterior: %s): ", nombres[index]);
        scanf(" %[^\n]", nombres[index]);
        
        cantidades[index] = leerEnteroPositivo("Ingresar nueva cantidad: ");
        precios[index] = leerFlotantePositivo("Ingresar nuevo precio: ");
    } else {
        printf("Indice fuera de rango.\n");
    }
}

void eliminarProducto() {
    int index = leerEnteroPositivo("Ingresar indice del producto a eliminar: ");
    if (index > 0 && index <= numProductos) {
        index--;
        for (int i = index; i < numProductos - 1; i++) {
            copiarCadena(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            precios[i] = precios[i + 1];
        }
        numProductos--;
        printf("Producto eliminado.\n");
    } else {
        printf("Indice fuera de rango.\n");
    }
}

void listarProductos() {
    if (numProductos > 0) {
        printf("Lista de productos:\n");
        for (int i = 0; i < numProductos; i++) {
            printf("\nIndice: %d\n", i + 1);
            printf("Nombre: %s\n", nombres[i]);
            printf("Cantidad: %d\n", cantidades[i]);
            printf("Precio: %.2f\n", precios[i]);
        }
    } else {
        printf("No hay productos en el inventario.\n");
    }
}

void mostrarMenu() {
    printf("\nSistema de Inventarios\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Salir\n");
}
