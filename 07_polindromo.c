#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Dato un vettore di interi grande n (chiesto in input)
// a. Caricare il vettore con valori casuali (1-10)
// b. Dire se è polindromo

void caricaVet(int *v, int *dim);
void stampaVet(int *v, int *dim);


int main (void)
{
    int *pV;
    int *dim;
    srand(time(0));

    dim = (int*) malloc(sizeof(int));
    printf("Inserisci dimensione array> ");
    scanf("%d", dim);

    // Allocare spazio in memoria per array
    pV= (*int) malloc(sizeof(int) * (*dim));

    // Caricamento array
    caricaVet(pV, dim);
    stampaVet(pV, dim);

    return 0;
}

void caricaVet(int *v, int *dim)
{
    int *i = (int*) malloc(sizeof(int));
    for(*i = 0; *i < *dim; (*i)++)
    {
        *(v+*i) = 1 + rand()%10;
    }
}

void stampaVet(int *v, int *dim)
{
    int *i = (int*) malloc(sizeof(int));
     for(*i = 0; *i < *dim; (*i)++)
    {
        printf("v[%d]: %d\n", i, *(v + i));
    }
}
