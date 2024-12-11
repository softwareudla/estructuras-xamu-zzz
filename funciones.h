struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[10];
};

int menu();
void registrarLibros(struct Libro libros[], int *n, int *contadorId);
void mostrarLibros(struct Libro libros[], int n);
void buscarLibroId(struct Libro libros[], int n, int id);
void buscarLibroTitulo(struct Libro libros[], int n, char *titulo);
int actualizarEstadoLibro(struct Libro libros[], int n, int id);
int eliminarLibro(struct Libro libros[], int *n, int id);