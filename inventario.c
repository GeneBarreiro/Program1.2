//Genesis Barreiro y Sophia Pérez
#include <stdio.h>
#include "inventario.h"


void ingresarNombreValido(char nombre[]) {
    int valido = 0;

    while (!valido) {
        valido = 1;
        printf("Nombre: ");
        scanf("%s", nombre);

        for (int i = 0; nombre[i] != '\0'; i++) {
            if (nombre[i] >= '0' && nombre[i] <= '9') {
                printf("Error: intentelo de nuevo.\n");
                valido = 0;
                break;
            }
        }
    }
}

float ingresarPrecioValido() {
    float precio;
    int valido = 0;

    while (!valido) {

        printf("Precio: ");

        
        if (scanf("%f", &precio) != 1) {
            printf("Error: ingrese un número válido.\n");

            
            while (getchar() != '\n');

            valido= 0;
        } 
        else if (precio < 0) {
            printf("Error: intentelo de nuevo.\n");
            valido= 0;
        }
        else {
            valido= 1;
        }
    }

    return precio;
}


void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int *cantidad) {

    do {
        printf("Ingrese la cantidad de productos (max 10): ");
        scanf("%d", cantidad);

        if (*cantidad <= 0 || *cantidad > MAX_PRODUCTOS) {
            printf("Cantidad inválida. Intente otra vez.\n");
        }

    } while (*cantidad <= 0 || *cantidad > MAX_PRODUCTOS);

    for (int i = 0; i < *cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);

        ingresarNombreValido(nombres[i]);
        precios[i] = ingresarPrecioValido();
    }
}


float calcularTotal(float precios[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int cantidad) {
    if (cantidad == 0) return 0;
    return calcularTotal(precios, cantidad) / cantidad;
}

int buscarMasCaro(float precios[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] > precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int buscarMasBarato(float precios[], int cantidad) {
    int indice = 0;
    for (int i = 1; i < cantidad; i++) {
        if (precios[i] < precios[indice]) {
            indice = i;
        }
    }
    return indice;
}

int iguales(char a[], char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }

    return a[i] == '\0' && b[i] == '\0';
}

int buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int cantidad, char buscado[]) {

    for (int i = 0; i < cantidad; i++) {
        if (iguales(nombres[i], buscado)) {
            printf("Producto encontrado: %s %.2f\n", nombres[i], precios[i]);
            return 1;
        }
    }

    printf("Producto no encontrado.\n");
    return 0;
}
