#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    struct Libro libros[20];
    int opc;
    int n = 0; // Contador de libros registrados

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibros(libros, &n); // Registrar un libro
                break;
            case 2:
                mostrarLibros(libros, n); // Mostrar todos los libros
                break;
            case 3: {
                int id;
                printf("Ingrese el id del libro a buscar (solo numeros): ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: El ID debe ser un numero.\n");
                    while (getchar() != '\n'); // Limpiar buffer
                    break;
                }
                buscarLibroId(libros, n, id); // Buscar un libro por ID
                break;
            }
            case 4: {
                char titulo[100];
                printf("Ingrese el titulo del libro a buscar: ");
                scanf(" %[^\n]", titulo);
                buscarLibroTitulo(libros, n, titulo); // Buscar un libro por titulo
                break;
            }
            case 5: {
                int id;
                printf("Ingrese el id del libro para actualizar su estado (solo numeros): ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: El ID debe ser un numero.\n");
                    while (getchar() != '\n'); // Limpiar buffer
                    break;
                }
                if (!actualizarEstadoLibro(libros, n, id)) { // Si no se encuentra el libro
                    printf("El libro con ID %d no existe.\n", id);
                }
                break;
            }
            case 6: {
                int id;
                printf("Ingrese el id del libro a eliminar (solo numeros): ");
                if (scanf("%d", &id) != 1) {
                    printf("Error: El ID debe ser un numero.\n");
                    while (getchar() != '\n'); // Limpiar buffer
                    break;
                }
                if (!eliminarLibro(libros, &n, id)) { // Si no se encuentra el libro
                    printf("El libro con ID %d no existe.\n", id);
                }
                break;
            }
        }
    } while (opc != 7);

    return 0;
}