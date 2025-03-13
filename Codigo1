//Creo un codibgo que me permita almacenar datos de un estudiante de una escuela
//nombre, edad y promedio.

#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50  // Acá defino que el nombre no supere los 50 caracteres

// Defino la estructrua del estudiante
typedef struct {
    char nombre[MAX_NOMBRE];  // Nombre del estudiante
    int edad;                 // Edad del estudiante
    float promedio;           // Promedio del estudiante
} Estudiante;

// Ahora creo una función que me permita a mi ingresar los datos de mi estudiante y los guarde en la estructura anterior.
Estudiante ingresarEstudiante() {
    Estudiante estudiante;  // Creo dentro de la función una variable del estudiante

    printf("Ingrese el nombre del estudiante: ");
    scanf(" %[^\n]", estudiante.nombre);  // Para ingresar nombres con espacios

    do {
        printf("Ingrese la edad del estudiante: "); 
        scanf("%d", &estudiante.edad); //Escanea la edad y la almacena en la estructura en edad
        if (estudiante.edad <= 0) { //Si la edad es menor a 0 no se puede
            printf("No es válido.\n"); //Manda un mensaje del error
        }
    } while (estudiante.edad <= 0);  // Valida que la edad sea mayor a 0 y hace lo de abajo

    do {
        printf("Ingrese el promedio del estudiante: "); //Ingresa el promedio y lo guarda
        scanf("%f", &estudiante.promedio);
        if (estudiante.promedio < 0 || estudiante.promedio > 10) {
            printf("El promedio debe estar entre 0 y 10.\n");
        }
    } while (estudiante.promedio < 0 || estudiante.promedio > 10);  // Valida que el promedio este entre 0 y 10, porque de lo contrario no se puede

    return estudiante;  //Nos devuelve la estructura completa
}

// Función para mostrar los datos del estudiante
void mostrarEstudiante(Estudiante estudiante) {
    printf("\n--- Datos del Estudiante ---\n");
    printf("Nombre: %s\n", estudiante.nombre);
    printf("Edad: %d años\n", estudiante.edad);
    printf("Promedio: %.2f\n", estudiante.promedio); //.2f para que nos muestre 2 decimales
}

// Función principal
int main() {
    Estudiante estudiante1;  // Se declara la variable estudiante1 con  la estructura

    estudiante1 = ingresarEstudiante();  // Se guarda el resultado de la función

    mostrarEstudiante(estudiante1);  // Se muestran los datos ingresados

    return 0;  // Fin del programa
}
