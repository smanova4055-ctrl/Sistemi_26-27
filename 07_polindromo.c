#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Dato un vettore di interi grande n (chiesto in input)
// a. Caricare il vettore con valori casuali(1-10)
// b. Dire se è palindromo
void caricaVet(int *v, int *dim);
void stampaVet(int *v, int *dim);


int main(void){

    int *pV;
    int *dim;
    srand(time(0));

    dim= (int*) malloc(sizeof(int));
    printf("Inserisci dimensaione array: ");
    scanf("%d", dim);

    // Allocazione spazio in memoria per array
    pV = (int*) malloc(sizeof(int) * (*dim));

    // Caricamento array
    caricaVet(pV, dim);
    // stampa array
    stampaVet(pV,dim);

    return 0;
}


void caricaVet(int *v, int *dim){
    int *i= (int*) malloc(sizeof(int));
    for(*i=0; *i < *dim; (*i)++){
        *(v+*i)= 1 + rand()%10;
    }
}

void stampaVet(int *v, int *dim){
     int *i= (int*) malloc(sizeof(int));
    for(*i=0; *i < *dim; (*i)++){
        printf("v[%d]: %d\n", *i, *(v+*i));
    }
}