#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//un programa en el cual se almacenan tareas y las podemos gestionar
//  creo la estructura de tarea, con un puntero al siguiente nodo
typedef struct Tarea {
    char descripcion[100];
    struct Tarea *siguiente;
} Tarea;

// agrega una tarea a la lista (sizeof es el tamaño de la estrcutura que son 100 bytes)
void agregarTarea(Tarea **nodo1, const char *desc) { //aca creo un doble nodo porque la lista esta vacia
    Tarea *nueva = (Tarea *)malloc(sizeof(Tarea)); //nuevo nodo, malloc reserva espacio en la memoria y después devuelve un puntero a tarea
    strcpy(nueva->descripcion, desc); // aca copio la desc (que es lo que pong ael usuario) a la descripción nueva que va en la lista.
    nueva->siguiente = NULL; //significa queel nodo no apunta a otro ya  que es el ultimo de la lista.

    if (*nodo1 == NULL) { //reviso la lista
        *nodo1 = nueva; //como no hay nada va a ser el primer nodo de la lista.
    } else { //si la lista no esta vacia la va a recorrer hasta el ultimo nodo
        Tarea *actual = *nodo1;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nueva; //cuando encuentra el ultimo nodo lo conecta al primero
    }
}

// Muestra las tareas en la lista
void mostrarTareas(Tarea *nodo1) { 
    printf("\n--- Lista de Tareas ---\n"); 
    int i = 1;
    while (nodo1 != NULL) {
        printf("%d. %s\n", i++, nodo1->descripcion); //va a printear la descripción escrita por el usuario del nodo 1
        nodo1 = nodo1->siguiente; //lo va a recorrer hasta el ultimo.
    }
}

// carga tareas desde el archivo a la lista
void cargarDesdeArchivo(Tarea **nodo1) { //doble nodo asi modifico directamente el main
    FILE *archivo = fopen("tareas.txt", "r"); //uso fopen para abrir un archivo llamado tareas.txt en modo lectura
    if (archivo == NULL) return;  //si el archivo no hace nada o no se abre salimos de la funcion

    char linea[100]; //para leer los 100 caracteres del archivo (descripción)
    while (fgets(linea, sizeof(linea), archivo)) { //lee una linea del archivo y la guarda
        linea[strcspn(linea, "\n")] = '\0'; //encuentra la posición del \n para saltar la linea y lo reemplaza por 0 para que termine ahi
        agregarTarea(nodo1, linea); //llama a agregar tarea para agregar esa linea como nueva tarea en la lista
    }

    fclose(archivo); //ciierro
}

// funcion para guardar tareas
void guardarEnArchivo(Tarea *nodo1) { //un puntero a la lista para guardarla
    FILE *archivo = fopen("tareas.txt", "w"); //abro el archivo tareas en w (modo escritura)
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n"); //si hay un problema en abrirlo se cancela la ufncion
        return;
    }

    while (nodo1 != NULL) { //recorre la lista nodo por nodo
        fprintf(archivo, "%s\n", nodo1->descripcion); //y agrega la descripción escrita
        nodo1 = nodo1->siguiente; //asi hasta el final y agregando \n para que quede estético
    }

    fclose(archivo); //lo cierro
}

// Libero memoria de la lista
void liberarLista(Tarea *nodo1) { //puntero a la tarea
    Tarea *temp; //guarda el nodo actual en temp
    while (nodo1 != NULL) { 
        temp = nodo1;
        nodo1 = nodo1->siguiente;
        free(temp); //cuando avanzo al siguiente libero la memoria del nodo anterior
    }
}

// la funcion main
int main() {
    Tarea *lista = NULL; //declaro un puntero lista que al principio esta vacio
    cargarDesdeArchivo(&lista); //llamo a la funcion para cargar tareas  del archivo en la lista
 
    int opcion; //variable para el menu
    char descripcion[100]; //variable para guardar el texto

    do {
        printf("\n1. Agregar tarea\n2. Mostrar tareas\n3. Salir\nOpción: "); //menu
        scanf("%d", &opcion); //leo la opcion
        getchar(); // limpia el \n que deja scanf

        switch (opcion) { //hago un switch de las distintas opciones.
            case 1:
                printf("Ingrese la descripción: ");
                fgets(descripcion, sizeof(descripcion), stdin);
                descripcion[strcspn(descripcion, "\n")] = '\0'; // quita \n
                agregarTarea(&lista, descripcion);
                guardarEnArchivo(lista);
                break; //este es en caso de agregar la tarea, que guarda en la lista.
            case 2:
                mostrarTareas(lista);
                break; //muestra las tareas actuales que estan en la lista
            case 3:
                printf("Saliendo...\n");
                break; //se sale del programa
            default:
                printf("Opción inválida.\n"); //en caso de que no  se  pueda ninguna de las 3 opciones anteriores
        }

    } while (opcion != 3); //se repite mientras no sea la 3

    liberarLista(lista); //liberamos la memoria al temrinar
    return 0;
}
