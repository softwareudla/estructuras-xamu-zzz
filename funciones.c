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

void registrarLibros(struct Libro libros[], int *n, int *contadorId) {
    if (*n >= 20) {
        printf("No se pueden registrar más libros. Límite alcanzado.\n");
        return;
    }

    printf("\n--- Registrar Libro ---\n");
    libros[*n].id = (*contadorId)++; // Generar ID automáticamente
    printf("Título: ");
    scanf(" %[^\n]", libros[*n].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", libros[*n].autor);
    printf("Año de publicación (máximo 2024): ");
    while (scanf("%d", &libros[*n].anio) != 1 || libros[*n].anio < 0 || libros[*n].anio > 2024) {
        printf("Error: El año debe ser un número positivo y no mayor a 2024.\n");
        while (getchar() != '\n'); // Limpiar buffer
    }
    strcpy(libros[*n].estado, "Disponible");
    (*n)++;
    printf("Libro registrado con éxito. ID asignado: %d\n", libros[*n - 1].id);
}

void mostrarLibros(struct Libro libros[], int n) {
    printf("\n--- Lista de Libros ---\n");
    printf("ID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t%s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibroId(struct Libro libros[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("\n--- Libro Encontrado ---\n");
            printf("ID: %d\n", libros[i].id);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año: %d\n", libros[i].anio);
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
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Año: %d\n", libros[i].anio);
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
            return 1;
        }
    }
    return 0;
}

int eliminarLibro(struct Libro libros[], int *n, int id) {
    for (int i = 0; i < *n; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*n)--;
            printf("Libro eliminado con éxito.\n");
            return 1;
        }
    }
    return 0;
}
