#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "strings.h"
#include "time.h"

#define DIM 30

//Prototipado
void menu();
void consignas();
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();
void ejercicio11();
void ejercicio12();
void ejercicio13();
void ejercicio14();
void ejercicio15();
void ejercicio16();
void ejercicio17();
int sumarElementosArray(int *ptrArray, int validos, int *sumaArray);
void convertirStringAMayuscula(char *punteroString);
void cargarArregloRandom(int *punteroArregloInt, int validos);
void mostrarArregloInt(int array[], int validos);
void eliminarNumerosImpares(int *arrayInt, int *validos);
void invertirArreglo(int *punteroArray, int validos);
void contabilizarVocalesEnString(char *string);
void copiarUnString(char *string, char *stringCopia);
void encontrarMinYMaxArray(int *array, int validos, int *min, int *max);
void concatenarStrings(char *destino, char *str);
void buscarLetra(char *string, char letra);
int *crearArrayDinamico(int validos);
char *dupliarCadenaDinamica(char *stringOriginal);
int *duplicarArrayEntero(int *arrayOriginal, int validos);
char *crearStringDinamico(char *str);
void intercambiarDosValoresConPunterosDobles(int **ptr1, int **ptr2);
void mostrarArregloConPunterosDobles(int **ptrArreglo, int validos);
/*--------------------------------------------------------------------------------------------------------*/
int main(){

menu();

}
/*--------------------------------------------------------------------------------------------------------*/

//Funciones

void menu() {
    srand(time(NULL));
    char eleccion = 's';
    int ejercicio;

    consignas();

    do {
    printf("Ingrese el Numero de ejercicio a dirigirse --> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");


    switch(ejercicio) {

    case 1:
        ejercicio1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio3();
        break;

    case 4:
        ejercicio4();
        break;

    case 5:
        ejercicio5();
        break;

    case 6:
        ejercicio6();
        break;

    case 7:
       ejercicio7();
        break;

    case 8:
        ejercicio8();
        break;

    case 9:

       ejercicio9(); //No lo pude realizar, está a medias, sin funcionar

        break;

    case 10:
        ejercicio10();
        break;

    case 11:
        ejercicio11();
        break;

    case 12:
        ejercicio12();
        break;

    case 13:
        ejercicio13();
        break;

    case 14:
        ejercicio14();
        break;

    case 15:
        ejercicio15();
        break;

    case 16:
        ejercicio16();
        break;

    case 17:
        ejercicio17();
        break;

    default:
        printf("Has ingresado un numero incorrecto, vuelve a intentarlo \n\n");
        break;
        }

        printf("\nPulse 's' para ingresar a otro ejercicio --> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");

    }while(eleccion == 's');
}

void consignas() {
    printf("1)Escribe un programa que intercambie los valores de dos variables utilizando punteros. \n");
    printf("2)Calcula la suma de los elementos de un arreglo usando punteros. \n");
    printf("3)Convierte una cadena de caracteres a mayusculas utilizando punteros. \n");
    printf("4)Elimina los numeros pares de un arreglo utilizando punteros. \n");
    printf("5)Invierte un arreglo utilizando punteros. \n");
    printf("6)Cuenta el numero de vocales en una cadena utilizando punteros. \n");
    printf("7)Copia una cadena en otra utilizando punteros. \n");
    printf("8)Encuentra el valor minimo y maximo en un arreglo utilizando punteros.\n");
    printf("9)Concatena dos cadenas utilizando punteros. \n");
    printf("10)Busca un caracter en una cadena utilizando punteros. \n ");
    printf("\nFunciones que Devuelven un Puntero: \n \n");
    printf("11)Crea un arreglo dinamico de enteros y devuelve un puntero a el. \n ");
    printf("12)Duplica una cadena y devuelve un puntero a la nueva cadena. \n ");
    printf("13)Clona un arreglo dinamico de enteros y devuelve un puntero al nuevo arreglo. \n ");
    printf("14)Crea una cadena dinamica y devuelve un puntero a ella. \n ");
    printf("\nPunteros Dobles: \n \n");
    printf("15)Funcion para intercambiar dos valores usando punteros dobles. \n ");
    printf("16)Uso de punteros dobles para acceder a un arreglo. \n ");
    printf("17)Pasar un arreglo a una funcion usando punteros dobles. \n \n ");
}

void ejercicio1() {

    int num1 = 500;
    int num2 = 100;

    int *puntero1;      //Declaración de un Puntero que apunta a NULL
    puntero1 = &num1;   //Puntero1, apunta a la dirección en memoria de num1
    printf("\n----------------------------------------------------------------- \n");
    printf("EJERCICIO 1 \n");

    printf("\n Contenido de Puntero1: %i ", *puntero1); //Una vez declarado el Puntero, el * me permite acceder al Contenido
    printf("\n Direccion en Memoria de Puntero1: %i ", puntero1); //Muestra la dirección en  memoria de Puntero1

    printf("\n");

    int *puntero2;
    puntero2 = &num2;
    printf("\n Contenido de Puntero2: %i ", *puntero2);
    printf("\n Direccion en Memoria de Puntero2: %i ", puntero2);

    printf("\n\n Intercambio de Valores \n\n");

    int aux = *puntero1;

    *puntero1 = *puntero2;
    printf(" %i \n", *puntero1);

    *puntero2 = aux;
    printf(" %i \n", *puntero2);
    printf("----------------------------------------------------------------- \n");
}

void ejercicio2() {

    int arrayInt[DIM];
    int validos;
    int sumaArray;

    printf("\n Ingrese la cantidad de numeros a cargar de forma aleatoria al Arreglo --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(&arrayInt, validos);

    int *punteroAlArreglo = &arrayInt;

//Los arreglos se degradan a un puntero al primer elemento del array, index 0. Primer bloque de memoria

printf("----------------------------------------------------------------- \n");
printf("EJERCICIO 2 \n");
printf("\n Accediendo a los index p/Aritmetica de Punteros \n");
printf("\n %i - ", *punteroAlArreglo);
printf("%i - ", *(punteroAlArreglo + 1));
printf("%i - ", *(punteroAlArreglo + 2));
printf("%i - ", *(punteroAlArreglo + 3));
printf("%i \n", *(punteroAlArreglo + 4));

sumarElementosArray(punteroAlArreglo, validos, &sumaArray);

printf("\n Suma del arreglo: %i \n", sumaArray);
printf("----------------------------------------------------------------- \n");

}
void ejercicio3() {

    char arregloStrings[DIM];
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 3 \n");
    printf("\n Ingrese una palabra o frase --> ");
    fflush(stdin);
    gets(arregloStrings);
    printf("\n");

    char *punteroAlArregloChar = &arregloStrings;

    printf("\n Minuscula --> %s \n", punteroAlArregloChar); //%s Accedo a la dirección en memoria a la que apunta el puntero hasta NULL
                                              //%c *punteroAlAregloChar me imprime el primer caracter, tengo que trabajar con aritmética de punteros y mover el bloque de memoria

    convertirStringAMayuscula(punteroAlArregloChar);
    printf(" \n Mayuscula %s \n", punteroAlArregloChar);
    printf("----------------------------------------------------------------- \n");
}

void ejercicio4() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 4 \n");
    int arrayInt[DIM];
    int validos;

    printf("\n Ingrese la cantidad de numeros a cargar de forma aleatoria al Arreglo --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(&arrayInt, validos);

    int *punteroAlArregloInt = &arrayInt; //Declaro e inicializo el puntero

    printf("Arreglo original \n \n");
    mostrarArregloInt(arrayInt, validos);

    eliminarNumerosImpares(punteroAlArregloInt, &validos);//Le paso al entorno de función la dirección de memoria de los validos para que se modifiquen

    printf("\nArreglo sin numeros pares \n \n");
    mostrarArregloInt(arrayInt,validos);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio5() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 5 \n");

    int arregloRandom[DIM];
    int validos;

    printf("\n Ingrese la cantidad de numeros a cargar de forma aleatoria al Arreglo --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(&arregloRandom, validos);
    printf("\n Mostrando arreglo original \n");
    mostrarArregloInt(arregloRandom, validos);

    int *punteroArrayRandom = &arregloRandom;

    invertirArreglo(punteroArrayRandom, validos);

    printf("\n Mostrando arreglo invertido \n");
    mostrarArregloInt(arregloRandom, validos);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio6() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 6 \n");

    char string[DIM];

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string);
    printf("\n");

    char *punteroString = &string;

    contabilizarVocalesEnString(punteroString);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio7() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 7 \n");

    char string[DIM];
    char stringCopia[DIM];

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string);
    printf("\n");

    char *punteroString = &string;

    printf("\nString Original --> %s \n", string);

    copiarUnString(string, stringCopia);

    printf("\nCopiando contenido del STR1 al STR2... \n");

    printf("\nString Copia --> %s \n", stringCopia);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio8() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 8 \n");

    int arrayRandom[DIM];
    int validos;
    int minimo, maximo;

    printf("\n Ingrese la cantidad de numeros a cargar de forma aleatoria al Arreglo --> ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(&arrayRandom, validos);
    printf("Mostrando Arreglo Cargado (Debug) --> ");
    mostrarArregloInt(arrayRandom, validos);

    int *punteroAlArray = &arrayRandom;

    encontrarMinYMaxArray(punteroAlArray, validos, &minimo, &maximo);

    printf("El minimo es --> %i\n", minimo);
    printf("El maximo es --> %i\n", maximo);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio9() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 9 \n");

    char strings[100];//Buffer que almacenará la cadena concatenada. Tener cuidado con el desbordamiento
    char string1[DIM];
    char string2[DIM];

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string1);
    printf("\n");

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string2);
    printf("\n");

    concatenarStrings(strings, string1);
    concatenarStrings(strings, string2);

    printf("Resultado --> %s \n", strings);

    printf("\n--------------------------------------------------------------------- \n");
}

void concatenarStrings(char *destino, char *str) {

    while (*destino) destino++; //Posicionamos el puntero destino al final de la cadena original para realizar la concatenación

    while(*str){
        *destino = *str;
        destino++;
        str++;
    }
    *destino = '\0';
}

void ejercicio10() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 10 \n");

    char string[DIM];
    char caracter;

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string);
    printf("\n");

    printf("\nIngrese una letra para saber si se encuentra en el String --> ");
    fflush(stdin);
    scanf("%c", &caracter);
    printf("\n");

    char *ptrString = &string;

    buscarLetra(string, caracter);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio11() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 11 \n");

    int validos;

    printf("\nIngrese la cantidad de datos que tendra el Arreglo ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    int *arrayDinamico = crearArrayDinamico(validos);

    cargarArregloRandom(arrayDinamico, validos);

    mostrarArregloInt(arrayDinamico, validos);

    free(arrayDinamico);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio12() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 12 \n");

    char string[DIM];

    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(string);
    printf("\n");

    char *stringOriginal = &string;


    char *stringDuplicado = dupliarCadenaDinamica(stringOriginal); //Función que me retorna un arrelgo dinámico

        printf("Cadena original: %s\n", stringOriginal);
        printf("Cadena duplicada: %s\n", stringDuplicado);

    free(stringDuplicado); //Liberamos la memoria

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio13() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 13 \n");

    int arrayInt[DIM];
    int validos;

    int *arrayDinamico = &arrayInt;

    printf("\nIngrese la cantidad de datos que tendra el Arreglo ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(arrayDinamico, validos);
    printf("Mostrando arreglo Original --> ");
    mostrarArregloInt(arrayDinamico, validos);
    printf("\n");

    int *arrayCopia = duplicarArrayEntero(arrayDinamico, validos);

    printf("Mostrando arreglo Duplicado -->  ");
    mostrarArregloInt(arrayCopia, validos);
    printf("\n");

    free(arrayCopia);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio14() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 14 \n");

    char string[DIM];
    char *ptrString = &string;

    char *arrayDinamico = crearStringDinamico(ptrString);


    printf("\nIngrese una palabra o frase --> ");
    fflush(stdin);
    gets(arrayDinamico);
    printf("\n");
    printf("Mostrando el contenido del Arreglo dinamico --> ");
    printf("%s", arrayDinamico);

    free(arrayDinamico);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio15() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 15 \n");

    int numero1 = 50;
    int numero2 = 10;

    int *puntero1 = &numero1;
    printf("\nMostrando el contenido de Puntero1: %i \n \n", *puntero1);
    int *puntero2 = &numero2;
    printf("Mostrando el contenido de Puntero2: %i \n", *puntero2);

    printf("\nGenerando Intercambio... \n\n");

    intercambiarDosValoresConPunterosDobles(&puntero1, &puntero2);

    printf("\nMostrando el contenido de Puntero1: %i \n \n", *puntero1);
    printf("Mostrando el contenido de Puntero2: %i \n", *puntero2);

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio16() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 16 \n");

    int arrayInt[DIM];
    int validos;

    int *punteroAlArrayInt = &arrayInt;
    int i;

    printf("\nIngrese la cantidad de datos que tendra el Arreglo ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(punteroAlArrayInt, validos);
    printf("Mostrando Arreglo cargado Aleatoriamente ---> ");
    mostrarArregloInt(punteroAlArrayInt, validos);

    printf("\nAcceso al Arreglo con punteros Dobles ---> ");

    int **punteroDoble = &punteroAlArrayInt; //Para declarar un puntero doble, se hace con doble * y luego de la igualdad le indicamos el & para darle esa dirección a la que apunta el puntero

    printf("   |%i| ", **punteroDoble);

    //Primero muestro el primer elemento ya que en el bucle a partir de el tengo que incrementar +1

    for(i = 1; i < validos; i++) {

        printf("|%i| ", *(*punteroDoble + i));
    }

    printf("\n--------------------------------------------------------------------- \n");
}

void ejercicio17() {
    printf("----------------------------------------------------------------- \n");
    printf("EJERCICIO 17 \n");

    int validos;
    int arrayInt[DIM];
    int *ptrArrayInt = &arrayInt;

    printf("\nIngrese la cantidad de datos que tendra el Arreglo ");
    fflush(stdin);
    scanf("%i", &validos);
    printf("\n");

    cargarArregloRandom(ptrArrayInt, validos);
//    printf("Debug --> Mostrando arreglo en el main \n");
//    mostrarArregloInt(ptrArrayInt, validos);

    mostrarArregloConPunterosDobles(&ptrArrayInt, validos);


    printf("\n--------------------------------------------------------------------- \n");
}

void mostrarArregloConPunterosDobles(int **ptrArreglo, int validos) {

//    printf("Debug --> Mostrando arreglo en la funcion \n");
    printf("   |%i| ", **ptrArreglo);

    for(int i = 1; i < validos; i++) {

        printf("|%i| ", *(*ptrArreglo + i));
    }
}

void intercambiarDosValoresConPunterosDobles(int **ptr1, int **ptr2) {

    int *ptrAuxiliar = *ptr1; //Almacena el 50 en Aux

    *ptr1 = *ptr2; //ptr1 = 10
    *ptr2 = ptrAuxiliar; //ptr2 = 50
}

char *crearStringDinamico(char *str) {

    size_t tamanio = strlen(str);

    char *strDinamic = (char *) malloc(tamanio * sizeof(char));

    strcpy(strDinamic, str);

    return strDinamic;
}

int *duplicarArrayEntero(int *arrayOriginal, int validos) {

    size_t tamanio = sizeof(validos);

    int *arrayCopia = (int *) malloc(validos * sizeof(int));

    if(arrayCopia == NULL) {
          printf("Error al asignar memoria\n");
    }

    for(int i = 0; i < validos; i++) {
    arrayCopia[i] = arrayOriginal[i];//Por aritmetica de punteros, el compilador entiende que se quieren igualar los contenidos
    }

    return arrayCopia;
}

char *dupliarCadenaDinamica(char *string) {

    size_t tamanio = strlen(string);

    char *stringCopia = (char *) malloc((tamanio + 1) * sizeof(char)); //Incluyo el caracter nulo

    if(stringCopia == NULL) {
        printf("Error al asignar memoria\n");
    }

    strcpy(stringCopia, string);

    return stringCopia;
}

int *crearArrayDinamico(int validos) {

    int *arrayDinamico = (int *) malloc(validos * sizeof(int));

    if(arrayDinamico == NULL) {
        printf("Error al asignar memoria \n");
        }

    return arrayDinamico;
}


void buscarLetra(char *string, char letra){

    int cantVeces = 0;
    int flag = 0;

    while(*string) {

        if(*string == letra) {
            flag = 1;
            cantVeces++;
        }
        *string++;
    }

    if(flag == 1) {
        printf("El caracter %c se encontro %i veces en la cadena de texto \n", letra, cantVeces);
    } else {
        printf("El caracter ingresado no se encontro en la cadena de texto \n");
    }
}


void encontrarMinYMaxArray(int *array, int validos, int *min, int *max) {

    int i = 0;
    *max = *array;
    *min = *array;

    for(int i = 0; i < validos; i++) {

        if(*array < *min) {
            *min = *array;
        }
        if(*array > *max) {
            *max = *array;
        }
        array++;
    }
}

void copiarUnString(char *string, char *stringCopia) {

    while(*string) {

        *stringCopia = *string;

        *stringCopia++;
        *string++;
    }
    *stringCopia = '\0';
}

void contabilizarVocalesEnString(char *string) {

    int contadorVocales = 0;
    char letra;

    while(*string) {

        letra = tolower(*string);

        if(letra == 'a'|| letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ) {
            contadorVocales++;
        }
        *string++; //Simepre que sale de la verificación incrementa un bloque en la memoria para acceder al otro caracter
    }
    printf("Se encontraron %i vocales \n", contadorVocales);
}

int sumarElementosArray(int *ptrArray, int validos, int *sumaArray) {

    int contador = 0;
    *sumaArray = 0;

    while(contador < validos) {

        *sumaArray += *ptrArray;
        ptrArray++; //Me mueve 1 bloque de memoria accediendo al próximo Index (Aritmética de Punteros)

        contador++;
    }
}

void eliminarNumerosImpares(int *arrayInt, int *validos) {

    int i = 0; //Recorre el arreglo hasta los validos - 1
    int contadorValidos = 0;
    int *punteroAux = arrayInt; //PunteroAux apunta a la dirección de memoria de Arreglo

    while(i <= *validos) {
        if((*arrayInt % 2) != 0) {   //Me quedo con los impares, entonces incremento en +1 el bloque de memoria
            *punteroAux = *arrayInt; //PunteroAux guarda el numero impar que contiene arrayInt
            arrayInt++;              //Incremento un bloque de memoria
            punteroAux++;           //Incremento el bloque de memoria de punteroAux
            contadorValidos++;
        }
        else {
            arrayInt++;              //Si el numero es par, directamente mueve un bloque de memoria, posicionandose en el próximo Index
        }
        i++;
    }
    *validos = contadorValidos;     //Los validos se modifican y se ve afectado en el main ya que lo pasamos por puntero
    }

void cargarArregloRandom(int *punteroArregloInt, int validos) {

    for(int i = 0; i < validos; i++) {
            punteroArregloInt[i] = rand()%10;
    }
}

void mostrarArregloInt(int array[], int validos) {

    int i;

    for(i = 0; i < validos; i++) {
    printf("|%i| ", array[i]);
    }
    printf("\n");

}

void invertirArreglo(int *punteroArray, int validos) {

    int auxiliar;
    int *punteroAux = punteroArray + (validos - 1); //Puntero aux, apunta a la ultima posición de los validos
    //Se coloca el -1 ya que siempre se apunta al primer bloque de memoria

    for(int i = 0; i <= (validos / 2); i++) { //Cuando se posiciona en la mitad se frena

        auxiliar = *punteroArray; //Conservo el dato del indice Izq
        *punteroArray = *punteroAux; //Piso el dato del indice Izq con el dato del indice Der
        *punteroAux = auxiliar; //Piso el dato del indice de la Der con el valor Aux

        punteroAux--; //La posición del indice Der, se mueve uno menos a la Izq
        punteroArray++; //La posición del indice Izq, se mueve uno más a la Der
    }
}

void convertirStringAMayuscula(char *punteroString) {

    int i = 0;

    while(*punteroString) {

        *punteroString = toupper(*punteroString);
        i++;//Cantidad de veces que se movió por bloque
        punteroString++;//Incremento un bloque de memoria para acceder al próximo index
    }
    punteroString = punteroString - i;//Muevo los bloques de memoria hasta el inicio de la dirección a la que apunta
}


//Ejemplo de Punteros Dobles sencillo:
/*
int main() {
    int num = 42;
    int *ptr1 = &num; // Puntero simple que apunta a 'num'
    int **ptr2 = &ptr1; // Puntero doble que apunta a 'ptr1'

    printf("Valor de num: %d\n", num);
    printf("Valor apuntado por ptr1: %d\n", *ptr1);
    printf("Valor apuntado por ptr2 (usando puntero doble): %d\n", **ptr2);

    return 0;
}
*/



