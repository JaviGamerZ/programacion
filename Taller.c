#include <stdio.h>

// Definimos cuántos estudiantes hay en total
#define CANTIDAD_ESTUDIANTES 5

// Estructura para guardar el código y la nota de cada estudiante
typedef struct {
    int codigo;
    float nota;
} Estudiante;

// Lista de estudiantes con sus códigos y notas ya asignadas
Estudiante estudiantes[CANTIDAD_ESTUDIANTES] = {
    {2025101, 4.3},
    {2025102, 2.8},
    {2025103, 3.5},
    {2025104, 4.7},
    {2025105, 3.9}
};

// Función recursiva para buscar la nota más alta
float buscarNotaMaxima(int i) {
    // Caso base: si estamos en el último estudiante, devolvemos su nota
    if (i == CANTIDAD_ESTUDIANTES - 1) {
        return estudiantes[i].nota;
    }

    // Llamamos a la misma función para ver cuál es la nota más alta del resto
    float maxResto = buscarNotaMaxima(i + 1);

    // Comparamos la nota actual con la del resto y devolvemos la mayor
    if (estudiantes[i].nota > maxResto) {
        return estudiantes[i].nota;
    } else {
        return maxResto;
    }
}

// Función recursiva para sumar todas las notas
float sumarNotas(int i) {
    // Caso base: si llegamos al final, devolvemos 0 para empezar a sumar
    if (i == CANTIDAD_ESTUDIANTES) {
        return 0;
    }

    // Sumamos la nota actual con la suma de las siguientes
    return estudiantes[i].nota + sumarNotas(i + 1);
}

// Función para intercambiar dos estudiantes de posición (sirve para ordenar)
void intercambiar(int a, int b) {
    Estudiante temp = estudiantes[a];
    estudiantes[a] = estudiantes[b];
    estudiantes[b] = temp;
}

// Función recursiva para ordenar los estudiantes por código (Selection Sort)
void ordenar(int index) {
    // Caso base: cuando ya no hay más elementos por ordenar
    if (index == CANTIDAD_ESTUDIANTES) {
        return;
    }

    // Buscamos el índice del estudiante con el código más pequeño en el resto
    int minIndex = index;
    for (int i = index + 1; i < CANTIDAD_ESTUDIANTES; i++) {
        if (estudiantes[i].codigo < estudiantes[minIndex].codigo) {
            minIndex = i;
        }
    }

    // Si encontramos uno más pequeño, lo cambiamos de lugar
    if (minIndex != index) {
        intercambiar(index, minIndex);
    }

    // Llamamos a la función para seguir ordenando el resto
    ordenar(index + 1);
}

// Función para mostrar todos los estudiantes con su código y nota
void mostrarEstudiantes() {
    for (int i = 0; i < CANTIDAD_ESTUDIANTES; i++) {
        printf("Codigo: %d - Nota: %.2f\n", estudiantes[i].codigo, estudiantes[i].nota);
    }
    printf("\n");
}

// Función principal que muestra el menú y permite elegir opciones
int main() {
    int opcion;

    do {
        // Mostramos el menú de opciones
        printf("========= MENU =========\n");
        printf("1. Mostrar nota maxima\n");
        printf("2. Calcular promedio\n");
        printf("3. Ordenar por codigo\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        // Ejecutamos lo que el usuario elija
        switch(opcion) {
            case 1:
                // Llamamos a la función para buscar la nota más alta
                printf("La nota maxima es: %.2f\n\n", buscarNotaMaxima(0));
                break;
            case 2:
                // Calculamos y mostramos el promedio (suma total / cantidad)
                printf("El promedio del curso es: %.2f\n\n", sumarNotas(0) / CANTIDAD_ESTUDIANTES);
                break;
            case 3:
                // Ordenamos los estudiantes por código y los mostramos
                ordenar(0);
                printf("Estudiantes ordenados:\n");
                mostrarEstudiantes();
                break;
            case 4:
                // Salimos del programa
                printf("Saliendo...\n");
                break;
            default:
                // Si la opción no es válida
                printf("Opcion no valida\n\n");
        }

    } while (opcion != 4); // El menú se repite hasta que elijan salir

    return 0;
}

