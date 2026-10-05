#include <stdio.h>
#include <stdlib.h>

// Dati 3 numeri in input, stampare in output la media

int mian (void)
{

    int* n1;
    n1 = (int*) malloc(sizeof(int));
    // *n1 = 10;
    printf("Inserisci n1: ");
    scanf("%d", n1);

    int* n2;
    n2 = (int*) malloc(sizeof(int));
    // *n2 = 10;
    printf("Inserisci n2: ");
    scanf("%d", n2);

    int* n3;
    n3 = (int*) malloc(sizeof(int));
    // *n3 = 10;
    printf("Inserisci n3: ");
    scanf("%d", n3);

    printf("n1: %d\nn2: %d\nn3: %d\n", *n1, *n2, *n3);




    return 0;
}