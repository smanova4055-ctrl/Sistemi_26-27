#include <stdio.h>
#include <stdlib.h>

    /* 
    Memoria statica: Stack
    Memoria dinamica: Heap
    */
    /*
    malloc(sizeof(int))--> riservo un'area di memoria per allocarlo prendo il sizeoff(int) e lo moltiplico per
    le celle malloc(sizeof(int)*5) questa funzione ci restituisce un indirizzo che rappresenta il PRIMO indirizzo,
    la memoria allocation richiede un cast dello STESSO tipo (int*) : p:=(int*)malloc(sizeof(int)*5)
    primo parametro numero di elementi che vengono moltiplicati per la sizeof(int), ha sempre il cast
    p:=(int*)calloc(1,sizeof(int))
    nella malloc legge il valore sporco

     calloc alloca i 4 byte richiesti e inizializza il contenuto con un valore neutro, in questo caso 0
     convien usarla quando devi inizializzare a 0

     realloc() ha lo scopo di riallocare memoria --> resize di un vettore--> è nient'altro che una realloc,
     passiamo per ref la dimensione e la cambiamo
     i parametri  p:=realloc(p,5*sizeof(int))--> indirizzo della prima cella, la nuova dimensone
     sono SEMPRE celle continue, senza sovvrascrivere nient'altro
     p potrebbe essere il nuovo indirizzo se le celle non ci stanno

     free(p)--> un solo parametro, nella free uso il primo indirizzo e va deallocato--> dice che non serve più
     e la libera per qualcos'altro --> non è più "proprietà" nostra

     carbage collector è lo spazzino e si rende conto quando un area di memoria non serve più e la libera
    */

void stampaVett(int a[], int dim)

int main (void)
{
    int v[] = {1, 2, 3, 4, 5}
    int dimA = 5;

    printf("Array statico di %d elementi \n", dimA)
    stampaVett(v,dimA)

    /* ALLOCAZIONE DINAMICA */
    int numElem = 10;
    int *p;
    /* MALLOC --> malloc(numByte) */
    p = (int*) malloc(sizeof(int) * numElem);
    stampaVett(p, numElem);

    /* CALLOC --> calloc(numero celle per tipo, dimensione del singolo elemento/tipo) */
    p = (int*) calloc(numElem,sizeof(int));
    stampaVett(p,numElem);

    return 0;
}


void stampaVett(int a[], int dim)
{
    int i;
    for(i=0; 0<dim; i++)
    printf("v[%d]: %d - %p\n", i, a[i], &a[i]);
}