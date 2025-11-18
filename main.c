#include <stdio.h>
#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidad;

    ingresarProductos(nombres, precios, &cantidad);

    printf("\n--- RESULTADOS ---\n");

    float total = calcularTotal(precios, cantidad);
    printf("Total del inventario: %.2f\n", total);

    int caro = buscarMasCaro(precios, cantidad);
    printf("Más caro: %s (%.2f)\n", nombres[caro], precios[caro]);

    int barato = buscarMasBarato(precios, cantidad);
    printf("Más barato: %s (%.2f)\n", nombres[barato], precios[barato]);

    printf("Promedio: %.2f\n", calcularPromedio(precios, cantidad));

    char buscado[MAX_NOMBRE];
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%s", buscado);

    buscarProducto(nombres, precios, cantidad, buscado);

    return 0;
}
