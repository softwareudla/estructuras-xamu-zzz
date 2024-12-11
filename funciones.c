#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opc;
    printf("\n--- Biblioteca ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por ID\n");
    printf("4. Buscar libro por Titulo\n");
    printf("5. Actualizar estado de un libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void registrarLibros(struct Libro libros[], int *n) {
    if (*n >= 20) {
        printf("No se pueden registrar mas libros. Limite alcanzado.\n");
        return;
    }

    printf("\n--- Registrar Libro ---\n");
    printf("ID: ");
    if (scanf("%d", &libros[*n].id) != 1) {
        printf("Error: El ID debe ser un numero.\n");
        while (getchar() != '\n'); // Limpiar buffer
        return;
    }
    printf("Titulo: ");
    scanf(" %[^\n]", libros[*n].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", libros[*n].autor);
    printf("Ano de publicacion: ");
    scanf("%d", &libros[*n].anio);
    strcpy(libros[*n].estado, "Disponible");
    (*n)++;
    printf("Libro registrado con exito.\n");
}

void mostrarLibros(struct Libro libros[], int n) {
    printf("\n--- Lista de Libros ---\n");
    printf("ID\tTitulo\t\tAutor\t\tAno\tEstado\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibroId(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("\n--- Libro Encontrado ---\n");
            printf("ID: %d\n", libros[i].id);
            printf("Titulo: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Ano: %d\n", libros[i].anio);
            printf("Estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void buscarLibroTitulo(struct Libro libros[], int n, char *titulo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("\n--- Libro Encontrado ---\n");
            printf("ID: %d\n", libros[i].id);
            printf("Titulo: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Ano: %d\n", libros[i].anio);
            printf("Estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

int actualizarEstadoLibro(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("\nEstado actual: %s\n", libros[i].estado);
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado: %s\n", libros[i].estado);
            return 1; // Libro encontrado y actualizado
        }
    }
    return 0; // Libro no encontrado
}

int eliminarLibro(struct Libro libros[], int *n, int id) {
    for (int i = 0; i < *n; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                libros[j] = libros[j + 1]; // Desplazar los libros para llenar el hueco
            }
            (*n)--; // Reducir el contador de libros
            printf("Libro eliminado con exito.\n");
            return 1; // Libro encontrado y eliminado
        }
    }
    return 0; // Libro no encontrado
}