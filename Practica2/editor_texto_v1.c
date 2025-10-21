/******************************************************************************
Realizar un programa que simule un editor de texto básico con una función de
buscar texto y reemplazar por otro. Utilizando Arreglo o Buffer, apuntadores y
funciones
 Ser llenado por una función --
 Mostrar el arreglo completo --
 Mostrar el texto a buscar --
 Mostrar el texto a reemplazar --
 Mostrar el texto final --
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char texto[100], *p_texto, buscar[20], reemplazar[20], *pos;
    
    printf("Escriba un texto [100 caracteres max.]: \n");fgets(texto, sizeof(texto), stdin); //Pedimos al usuario un texto.
    p_texto = calloc(strlen(texto) + 1, sizeof(char)); //Asignamos memoria.
    strcpy(p_texto, texto);//rellenamos el puntero con la cadena texto.
    
    //comprobamos si hay memoria suficiente.
    if(p_texto == NULL){
        printf("Error en asignar memoria.");
        return -1;
    }
    else{
        system("clear");
        printf("El texto escrito es: \n");
        printf("%s", p_texto);//imprimimos la cadena.
    }
    //Ahora vamos a buscar y reemplazar
    printf("\n\nIngrese palabra a buscar en su texto: \n");
    scanf("%19s", buscar);//Busca palabra.
    printf("Ingrese palabra para reemplazar: \n");
    scanf("%19s", reemplazar);//Palabra a reemplazar.
    
    pos = strstr(p_texto, buscar);
    
    //Revisamos si el texto que buscamos existe, y si la palabra de reemaplazo tienen la misma longitud.
    if(pos != NULL && strlen(buscar) == strlen(reemplazar)){
        strncpy(pos, reemplazar, strlen(reemplazar));
    } else if(pos != NULL){
        printf("\nLa palabra de reemplazo tiene distinta longitud, se requiere reacomodar el texto.\n");
        return 1;//si las longitudes son distintas, terminamos el programa, al menos en esta version.
    } else {
        printf("Palabra no encontrada.\n");
        return 1;//si no se encuentra la palabra, terminamos el programa, al menos en esta version.
    }

    printf("\nTexto final: %s\n", p_texto);

    free(p_texto);//liberamos la memoria.
    return 0;
}