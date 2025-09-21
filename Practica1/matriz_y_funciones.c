/*Realizar un programa que utilice un arreglo bidimensional 
entero de igual tamaño filas y columnas no mayor de 10. 
	-Ser llenado por una función random con valores entre 1 y 100
    -Mostrar el arreglo completo. 
    -Mostrar la suma de todos sus elementos
    -Mostrar la cantidad de elementos pares e impares
    -Mostrar cantidad de los elementos divisibles entre 7
    -Obtener el Arreglo Transpuesto y mostrarlo a través de una función.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void operaciones_fun(int tam, int a[tam][tam]); //prototipo de función que realioza las operaciones.

int main(){
	int tam_array; //tamaño del arreglo.
    int i, j, n; //variables para los bucles y para asignar valores random.
    
    //Pedir tamaño de arreglo al usuario:
    do{
    system("clear"); //limpiamos pantalla por si el usuario se equivoca. 
    printf("Ingresar un número entre 1 y 10: \n");scanf("%i", &tam_array); 
    //Validamos que el número esté entre 1 y 10.
    if(tam_array<1 || tam_array>10){
    printf("\nEl numero es incorrecto, pulse una tecla para volver a intentar.");
    getchar();getchar(); //Hacemos doble getchar para que espere a que el usuario pulse una tecla.
    }
    }while(tam_array<1 || tam_array>10); //si el numero es incorrecto el bucle se repite.
    
    //Asiganr valores random e imprimirlos en pantalla.
    int rand_array[tam_array][tam_array]; //Declaramos el arreglo.
    srand(time(NULL)); //inicializamos la semilla para los números random.
    for(i=0;i<tam_array;i++){
        for(j=0;j<tam_array;j++){
        n = (rand() % (100 - 1 + 1)) + 1;
        rand_array[i][j] = n;
        } 
    }
    //Imprimimos el arreglo principal.
    system("clear");
    printf("\tEl arreglo[%i][%i] es:\n\n", tam_array, tam_array);
    for(i=0;i<tam_array;i++){
        for(j=0;j<tam_array;j++){
        if(rand_array[i][j]<10){
        printf("0"); //Imprimimos "0" para que los números menores de 10 se vean alineados. 
        }
        printf("%i  ", rand_array[i][j]);
        }
    printf("\n"); 
    }
    
    operaciones_fun(tam_array, rand_array);//Llamamos a la función que hará las operaciones.
    return 0;
}

void operaciones_fun(int tam, int a[tam][tam]){
	int suma=0, i, j, par=0, impar=0, div=0;
    int trans_array[tam][tam]; //declaramos el arreglo transpuesto.
    
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
        //contamos pares e impares.
        if(a[i][j]%2==0){
            par++; //si el número es par, aumentamos el contador de pares.
        }
        else{
        	impar++; //si no, aumentamos el contador de impares.
        }
        //contamos divisibles entre 7.
        if(a[i][j]%7==0){
        	div++;
        }
        trans_array[j][i] = a[i][j];
        //sumamos los elementos del arreglo.
        suma += a[i][j];
        }
	}

    //Imprimimos el arreglo transpuesto.
    printf("\nEl arreglo transpuesto[%i][%i] es:\n\n", tam, tam);

    for(i=0;i<tam;i++){
    	for(j=0;j<tam;j++){
        if(trans_array[i][j]<10){
        printf("0");
        }
        printf("%i  ", trans_array[i][j]);
        }
    printf("\n"); 
    } 
    //Imprimimos los resultados de las operaciones.
    printf("\nLa suma de sus elementos es: %i", suma);
    printf("\nLos numeros pares son: %i", par);
    printf("\nLos numeros impares son: %i", impar);
    printf("\nLos numeros divisibles entre 7 son: %i", div);
}