#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[20];
    int opc;
    int n = 0; // Contador de libros registrados
    int contadorId = 1; // ID inicial para los libros

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibros(libros, &n, &contadorId);
                break;
            case 2:
                mostrarLibros(libros, n);
                break;
            case 3: {
                int id;
                printf("Ingrese el ID del libro a buscar: ");
                scanf("%d", &id);
                buscarLibroId(libros, n, id);
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                scanf(" %[^\n]", titulo);
                buscarLibroTitulo(libros, n, titulo);
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el ID del libro para actualizar su estado: ");
                scanf("%d", &id);
                if (!actualizarEstadoLibro(libros, n, id)) {
                    printf("El libro con ID %d no existe.\n", id);
                }
                break;
            }
            case 6: {
                int id;
                printf("Ingrese el ID del libro a eliminar: ");
                scanf("%d", &id);
                if (!eliminarLibro(libros, &n, id)) {
                    printf("El libro con ID %d no existe.\n", id);
                }
                break;
            }
        }
    } while (opc != 7);

    return 0;
}
