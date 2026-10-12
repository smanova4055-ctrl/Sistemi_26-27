#include <stdio.h>
#include <stdlib.h>
// Dati 3 numeri interi in input, stampare in output la media

int main(void)
{
    int *n1, *n2, *n3;
    float *media; 

    n1 = (int*) malloc(sizeof(int));
    n2 = (int*) malloc(sizeof(int));
    n3 = (int*) malloc(sizeof(int));
    media = (float*) malloc(sizeof(float));

    printf("Inserisci n1 > ");
    scanf("%d", n1);
    printf("Inserisci n2 > ");
    scanf("%d", n2);
    printf("Inserisci n3 > ");
    scanf("%d", n3);

    printf("n1: %d\nn2: %d\nn3: %d\n", *n1, *n2, *n3);
    *media = (*n1+*n2+*n3)/3;

    printf("La media e' %.2f\n", *media);

    return 0;
}