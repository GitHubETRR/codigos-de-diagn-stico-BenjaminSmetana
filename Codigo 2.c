#include <stdio.h>

// Defino estructura donde voy a almacenar la fecha en q nace
struct Fecha {
    int dia;  // Almacena el día que nació
    int mes;  // Almacena el mes que nació (como número)
    int anio; // Almacena el año que nació
};

// Función q me de el nombre del mes cuando ingresan el numero y defino la variable mes (pongo const porque no puede ser modificado el valor)
const char* obtenerNombreMes(int mes) {
    // Array de cadenas con los nombres de los meses q hay
    const char* nombresMeses[] = {"", "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    
    // Si el mes esta del 1 al 12 se devuelve su nombre
    if (mes >= 1 && mes <= 12) {
        return nombresMeses[mes];
    }
    
    // Si el número del mes no es válido, devolvemos un mensaje de error
    return "mes inválido";
}

int main() {
    struct Fecha fechaNacimiento; // Variable para almacenar la fecha ingresada
    
    // Solicitamos q ingresen la fecha q nacio
    printf("Ingrese el día de nacimiento: ");
    scanf("%d", &fechaNacimiento.dia); // Guardamos el día ingresado 
    
    printf("Ingrese el mes de nacimiento (número): ");
    scanf("%d", &fechaNacimiento.mes); // Guardamos el mes ingresado 
    
    printf("Ingrese el año de nacimiento: ");
    scanf("%d", &fechaNacimiento.anio); // Guardamos el año ingresado
    
    // Mostramos la fecha en formate de que el mes se vea escrito.
    printf("La persona nació el %d de %s de %d.\n", fechaNacimiento.dia, obtenerNombreMes(fechaNacimiento.mes), fechaNacimiento.anio);
    
    return 0; // Fin del programa
}

