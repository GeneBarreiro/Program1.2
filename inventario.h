#define inventario_h

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

void ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int *cantidad);
float calcularTotal(float precios[MAX_PRODUCTOS], int cantidad);
int buscarMasCaro(float precios[MAX_PRODUCTOS], int cantidad);
int buscarMasBarato(float precios[MAX_PRODUCTOS], int cantidad);
float calcularPromedio(float precios[MAX_PRODUCTOS], int cantidad);
int iguales(char a[], char b[]);
int buscarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidad, char buscado[MAX_NOMBRE]);


