/*
Realizar un programa que relacion tareas, alumnos y calificaciones, A través de un
menu realizar un programa con la opción de gestionar, las tareas, los alumnos y
las calificaciones y contar con la opción de mostrar todos los datos.
     Ser llenado por una función --
     Mostrar la gestión de tareas --
     Mostrar la gestión de alumnos --
     Mostrar la asignación de calificaciones --
     Mostrar los resultados --
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura de alumnos
struct alumnos{
  char nombre[30];
  int tareas;
  float promedio;
};

//Prototipos funciones
void main_menu(struct alumnos **alumno, int *cant);
void altas_bajas(struct alumnos **alumno, int *cant);
void impresion_datos(struct alumnos *alumno, int cant);

int main() {
    //Declaración de alumnos por defecto en el sistema.    
    int cant = 3;
    struct alumnos *alumno = malloc(cant * sizeof(struct alumnos));
    strcpy(alumno[0].nombre, "Himiko"); alumno[0].tareas = 18; alumno[0].promedio = 9.0;
    strcpy(alumno[1].nombre, "Alice");  alumno[1].tareas = 10; alumno[1].promedio = 5.0;
    strcpy(alumno[2].nombre, "Adel");   alumno[2].tareas = 7; alumno[2].promedio = 3.5;
    
    //Llamado a la funcion de menu principal.
    main_menu(&alumno, &cant);
    //Liberación de memoria.
    free(alumno);
    return 0;
}

void main_menu(struct alumnos **alumno, int *cant) {
    int select;
    //Impresión de opciones del menu
    do {
        system("clear"); //Cambiiar por "cls" en windows (para limpiar pantalla)
        printf("SISTEMA ESCOLAR\n");
        printf("***************\n");
        printf("1.-Imprimir lista de alumnos.\n");
        printf("2.-Asignar alta/baja de alumno.\n");
        printf("3.-Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &select);
    //Evaluacion de la opción elegida por el usuario.
        switch(select){
            case 1: impresion_datos(*alumno, *cant); break;
            case 2: altas_bajas(alumno, cant); break;
            case 3: printf("Finalizando programa...\n"); break;
            default: printf("\n\nOpcion no valida, pulse una tecla para volver a intentar...\n"); 
            getchar();getchar(); break; //Uso getchar para simular una pausa en el sistema
        }
    } while(select != 3);
}
//Función para dar de alta un nuevo alumno.
void altas_bajas(struct alumnos **alumno, int *cant) {
    int select, i, pos;
    //Menu altas y bajas
    system("clear"); //Cambiiar por "cls" en windows (para limpiar pantalla)
    printf("\nSISTEMA DE ALTAS Y BAJAS\n");
    printf("************************\n");
    printf("Seleccione una opcion: \n");
    printf("1.-Dar de alta.\n");
    printf("2.-Dar de baja.\n");
    scanf("%i", &select);

    switch(select){
        case 1:
            (*cant)++;
            *alumno = realloc(*alumno, (*cant) * sizeof(struct alumnos));

            printf("ALTA DE ALUMNO\n");
            printf("**************\n");
            printf("Ingresar nombre: \n");
            scanf("%s", (*alumno)[(*cant)-1].nombre);
            printf("Ingresar tareas: \n");
            scanf("%d", &(*alumno)[(*cant)-1].tareas);
            (*alumno)[(*cant)-1].promedio = (*alumno)[(*cant)-1].tareas / 20.0 * 10.0; //Calculamos el promedio en base a las tareas realizadas, si se desea cambiar el total de tareas modificar el valor 20.0.
            printf("Alumno dado de alta correctamente.\n");
            break;

        case 2:
            //Primero revisamos que existan alumnos inscritos.
            if (*cant==0){
            printf("No hay alumnos para eliminar.\n");
            return;
            }
            //Mostramos cuales alumnos existen.
            printf("ALUMNOS REGISTRADOS:\n");
            for (i=0;i<*cant;i++){
            printf("%d) %s\n", i + 1, (*alumno)[i].nombre);
            }
            
            printf("Seleccione el alumno a eliminar: \n");
            scanf("%d", &pos);
            //Revisamos que la posicion del alumno exista.
            if (pos<1 ||pos>*cant){
            printf("Opción inválida.\n");
            return;
            }
            
            //Reducimos en 1 la posicion para que no se elimine al alumno incorrecto
            pos--;
            //Modifica el lugar en el arreglo del resto de los alumnos.
            for (i=pos;i<*cant-1;i++){
            (*alumno)[i] = (*alumno)[i+1];
            }
            //Reducimos la cantidad total de alumnos.
            (*cant)--;
            //Achicamos la memoria.
            *alumno = realloc(*alumno, (*cant) * sizeof(struct alumnos));
            printf("Alumno eliminado correctamente.\n");
            break;
        default:
            printf("Opción inválida.\n");
            break;
    }
}
//Funcion impresion de datos de alumnos
void impresion_datos(struct alumnos *alumno, int cant){
    int i;
    system("clear"); //Cambiiar por "cls" en windows (para limpiar pantalla)
    printf("ALUMNOS INSCRITOS\n");
    printf("*****************\n\n");
    for(int i = 0; i < cant; i++){
    printf("ALUMNO [%i]\n", i + 1);
    printf("Nombre: %s\n", alumno[i].nombre);
    printf("Tareas: %i\n", alumno[i].tareas);
    printf("Promedio: %.1f\n\n", alumno[i].promedio);
    }
    
    printf("Pulse una tecla para volver al menu principal...\n");
    getchar();getchar(); //Uso getchar para simular una pausa en el sistema
}