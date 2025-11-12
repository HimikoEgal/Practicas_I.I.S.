#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
void llenar_arreglo(char **p_texto);
void mostrar_arreglo(char *p_texto);
void buscar_y_reemplazar(char *p_texto);

int main()
{
    char *p_texto = NULL;

    // Llenamos el arreglo con la función.
    llenar_arreglo(&p_texto);

    // Función para buscar y reemplazar
    buscar_y_reemplazar(p_texto);

    // Liberamos memoria
    free(p_texto);

    return 0;
}

// Función para llenar el arreglo dinámicamente
void llenar_arreglo(char **p_texto){
    char texto[100];
    printf("Escriba un texto [100 caracteres max.]: \n");
    fgets(texto, sizeof(texto), stdin);

    // Eliminamos el salto de línea que pone fgets
    texto[strcspn(texto, "\n")] = 0;

    *p_texto = (char *)calloc(strlen(texto) + 1, sizeof(char));
    if(*p_texto == NULL){
        printf("Error en asignar memoria.\n");
        exit(1);
    }
    strcpy(*p_texto, texto);

    mostrar_arreglo(*p_texto);
}

// Función para mostrar el arreglo
void mostrar_arreglo(char *p_texto){
    system("clear");
    printf("El texto escrito es: \n%s\n", p_texto);
}

// Función para buscar y reemplazar una palabra
void buscar_y_reemplazar(char *p_texto){
    char buscar[20], reemplazar[20];
    char *pos;

    printf("\nIngrese palabra a buscar en su texto: \n");
    scanf("%19s", buscar);

    printf("Ingrese palabra para reemplazar: \n");
    scanf("%19s", reemplazar);

    pos = strstr(p_texto, buscar);

    if(pos != NULL && strlen(buscar) == strlen(reemplazar)){
        strncpy(pos, reemplazar, strlen(reemplazar));
        printf("\nTexto final: %s\n", p_texto);
    }
    else if(pos != NULL){
        printf("\nLa palabra de reemplazo tiene distinta longitud, se requiere reacomodar el texto.\n");
    }
    else{
        printf("Palabra no encontrada.\n");
    }
}